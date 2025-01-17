/*
 *  Copyright 2020-2023 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos
 *
 *  This file is part of Expand.
 *
 *  Expand is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Expand is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Expand.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * @file mpi_server_comm.c
 * @brief File to 'TODO'.
 *
 * File to 'TODO'.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

/************************************************
 *  ... Includes
 ***********************************************/
#include "mpi_server_comm.h"

/************************************************
 *  ... Functions
 ***********************************************/

int mpi_server_comm_init(mpi_server_param_st *params)
{
  int ret, provided, claimed;
  char serv_name[HOST_NAME_MAX];

  // Get timestap
  struct timeval t0;
  base_time_misc_timer(&t0);

  DEBUG_BEGIN();

  // MPI_Init

  // Threads disable
  if (!params->thread_mode)
  {
    ret = MPI_Init(&(params->argc), &(params->argv));
    if (MPI_SUCCESS != ret)
    {
      debug_error("Server[%d]: MPI_Init fails :-(", -1);
      return -1;
    }
  }
  // Threads enable
  else
  {
    ret = MPI_Init_thread(&(params->argc), &(params->argv), MPI_THREAD_MULTIPLE, &provided);
    if (MPI_SUCCESS != ret)
    {
      debug_error("Server[%d]: MPI_Init_thread fails :-(", -1);
      return -1;
    }

    MPI_Query_thread(&claimed);
    if (claimed != MPI_THREAD_MULTIPLE)
    {
      printf("MPI_Init_thread: your MPI implementation seem not supporting thereads\n");
    }
  }

  // params->rank = comm_rank()
  ret = MPI_Comm_rank(MPI_COMM_WORLD, &(params->rank));
  if (MPI_SUCCESS != ret)
  {
    debug_error("Server[%d]: MPI_Comm_rank fails :-(", params->rank);
    return -1;
  }

  // params->size = comm_size()
  ret = MPI_Comm_size(MPI_COMM_WORLD, &(params->size));
  if (MPI_SUCCESS != ret)
  {
    debug_error("Server[%d]: MPI_Comm_size fails :-(", params->rank);
    return -1;
  }

  // Open server port...
  ret = MPI_Open_port(MPI_INFO_NULL, params->port_name);
  if (MPI_SUCCESS != ret)
  {
    debug_error("Server[%d]: MPI_Open_port fails :-(", params->rank);
    return -1;
  }

  // Generate DNS file
  int version_len;
  char version[MPI_MAX_LIBRARY_VERSION_STRING];
  MPI_Get_library_version(version, &version_len);

  if (strncasecmp(version, "Open MPI", strlen("Open MPI")) != 0)
  {
    for (int j = 0; j < params->size; j++)
    {
      if (j == params->rank)
      {
        char *ip;

        ns_get_hostname(params->srv_name);

        ip = ns_get_host_ip();
        if (ip == NULL)
        {
          debug_error("Server[%d]: NS_PUBLISH fails :-(", params->rank);
          return -1;
        }

        ret = ns_publish(params->dns_file, "mpi_server", params->srv_name, ip, params->port_name);
        if (ret < 0)
        {
          debug_error("Server[%d]: NS_PUBLISH fails :-(", params->rank);
          return -1;
        }
      }

      MPI_Barrier(MPI_COMM_WORLD);
    }
  }
  else
  {
    // Publish port name
    MPI_Info info;
    MPI_Info_create(&info);
    MPI_Info_set(info, "ompi_global_scope", "true");

    // struct hostent *serv_entry;
    gethostname(serv_name, HOST_NAME_MAX); // get hostname
    // serv_entry = gethostbyname(serv_name); // find host information
    sprintf(params->srv_name, "%s", serv_name);

    ret = MPI_Publish_name(params->srv_name, info, params->port_name);
    if (MPI_SUCCESS != ret)
    {
      debug_error("Server[%d]: MPI_Publish_name fails :-(", params->rank);
      return -1;
    }
  }

  // Print server init information
  MPI_Barrier(MPI_COMM_WORLD);

  struct timeval t1;
  struct timeval tf;
  float time;
  base_time_misc_timer(&t1);
  base_time_misc_diff_time(&t0, &t1, &tf);
  time = base_time_misc_timeval_to_seconds(&tf);

  if (params->rank == 0)
  {
    printf("\n\n");
    printf("Time to inizialize all servers: %f s\n", time);
    printf("\n");
    printf("---------------------------\n");
    printf("All XPN MPI servers running\n");
    printf("---------------------------\n");
    printf("\n\n");
  }

  debug_info("[SERV-COMM] server %d available at %s\n", params->rank, params->port_name);
  debug_info("[SERV-COMM] server %d accepting...\n", params->rank);

  DEBUG_END();

  // Return OK
  return 1;
}

int mpi_server_comm_destroy(mpi_server_param_st *params)
{
  int ret;

  DEBUG_BEGIN();

  // Close port
  MPI_Close_port(params->port_name);

  for (int i = 0; i < params->size; ++i)
  {
    if (params->rank == i)
    {

      int version_len;
      char version[MPI_MAX_LIBRARY_VERSION_STRING];
      MPI_Get_library_version(version, &version_len);

      if (strncasecmp(version, "Open MPI", strlen("Open MPI")) != 0)
      {
        char hostname[1024];
        ns_get_hostname(hostname);

        // Unpublish port name
        ret = ns_unpublish(params->dns_file, "mpi_server", hostname);
        if (ret < 0)
        {
          debug_error("Server[%d]: ns_unpublish fails :-(", params->rank);
          return -1;
        }
      }
      else
      {
        // Unpublish port name
        ret = MPI_Unpublish_name(params->srv_name, MPI_INFO_NULL, params->port_name);
        if (MPI_SUCCESS != ret)
        {
          debug_error("Server[%d]: port unregistration fails :-(\n", params->rank);
          return -1;
        }
      }
    }

    MPI_Barrier(MPI_COMM_WORLD);
  }

  // Finalize
  ret = MPI_Finalize();
  if (MPI_SUCCESS != ret)
  {
    debug_error("Server[%d]: MPI_Finalize fails :-(", params->rank);
    return -1;
  }

  DEBUG_END();

  // Return OK
  return 1;
}

MPI_Comm mpi_server_comm_accept(mpi_server_param_st *params)
{
  int ret;

  DEBUG_BEGIN();

  // Accept
  ret = MPI_Comm_accept(params->port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &(params->client));
  if (MPI_SUCCESS != ret)
  {
    debug_error("Server[%d]: MPI_Comm_accept fails :-(", params->rank);
    return MPI_COMM_NULL;
  }

  DEBUG_END();

  // Return client MPI_Comm
  return params->client;
}

int mpiClient_comm_close(MPI_Comm fd)
{
  int ret;

  if (fd == MPI_COMM_NULL)
  {
    debug_error("Server[]: ERROR: MPI_COMM_NULL as communication descriptor :-(");
    return 1;
  }

  // Disconnect
  ret = MPI_Comm_disconnect(&fd);
  if (MPI_SUCCESS != ret)
  {
    debug_error("Server[]: ERROR: MPI_Comm_disconnect fails :-(");
    return -1;
  }

  // Return OK
  return 1;
}

ssize_t mpi_server_comm_read_operation(mpi_server_param_st *params, MPI_Comm fd, char *data, ssize_t size, int *rank_client_id)
{
  int ret;
  MPI_Status status;

  DEBUG_BEGIN();

  // Check params
  if (NULL == params)
  {
    debug_warning("Server[%d]: ERROR: NULL arguments", -1);
    return -1;
  }
  if (size == 0)
  {
    return 0;
  }
  if (size < 0)
  {
    debug_warning("Server[%d]: ERROR: size < 0", params->rank);
    return -1;
  }

  // Get message
  ret = MPI_Recv(data, size, MPI_INT, MPI_ANY_SOURCE, 0, fd, &status);
  if (MPI_SUCCESS != ret)
  {
    debug_warning("Server[%d]: MPI_Recv fails :-(", params->rank);
  }

  *rank_client_id = status.MPI_SOURCE;

  debug_info("[SERV-COMM] MPI SOURCE %d, MPI_TAG %d, MPI_ERROR %d\n", status.MPI_SOURCE, status.MPI_TAG, status.MPI_ERROR);

  DEBUG_END();

  // Return bytes read
  return size;
}

ssize_t mpi_server_comm_write_data(mpi_server_param_st *params, MPI_Comm fd, char *data, ssize_t size, int rank_client_id)
{
  int ret;

  DEBUG_BEGIN();

  // Check params
  if (NULL == params)
  {
    debug_warning("Server[%d]: ERROR: NULL params", -1);
    return -1;
  }
  if (size == 0)
  {
    return 0;
  }
  if (size < 0)
  {
    debug_warning("Server[%d]: ERROR: size < 0", params->rank);
    return -1;
  }

  // Send message
  ret = MPI_Send(data, size, MPI_CHAR, rank_client_id, 1, fd);
  if (MPI_SUCCESS != ret)
  {
    debug_warning("Server[%d]: ERROR: MPI_Recv fails :-(", params->rank);
  }

  DEBUG_END();

  // Return bytes written
  return size;
}

ssize_t mpi_server_comm_read_data(mpi_server_param_st *params, MPI_Comm fd, char *data, ssize_t size, int rank_client_id)
{
  int ret;
  MPI_Status status;

  DEBUG_BEGIN();

  // Check params
  if (NULL == params)
  {
    debug_warning("Server[-1]: ERROR: NULL params", -1);
    return -1;
  }
  if (size == 0)
  {
    return 0;
  }
  if (size < 0)
  {
    debug_warning("Server[%d]: ERROR: size < 0", params->rank);
    return -1;
  }

  // Get message
  ret = MPI_Recv(data, size, MPI_CHAR, rank_client_id, 1, fd, &status);
  if (MPI_SUCCESS != ret)
  {
    debug_warning("Server[%d]: ERROR: MPI_Recv fails :-(", params->rank);
  }

  debug_info("[SERV-COMM] MPI SOURCE %d, MPI_TAG %d, MPI_ERROR %d\n", status.MPI_SOURCE, status.MPI_TAG, status.MPI_ERROR);

  DEBUG_END();

  // Return bytes read
  return size;
}

/* ................................................................... */
