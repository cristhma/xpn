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
 * @file mpi_server.c
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
#include "all_system.h"
#include "base/utils.h"
#include "mpi_server_params.h"
#include "mpi_server_ops.h"
#include "base/workers.h"
#include "mpi_server_comm.h"
#include "mpi_server_d2xpn.h"

/************************************************
 *  ... Global variables
 ***********************************************/
char serv_name[HOST_NAME_MAX];
mpi_server_param_st params;
worker_t worker;
int the_end = 0;

/************************************************
 *  ... Auxiliar Functions
 ***********************************************/

/**
 * @brief 'TODO'.
 *
 * 'TODO'.
 *
 * @param th  'TODO'.
 * @par Returns
 *    Nothing.
 */
void mpi_server_run(struct st_th th)
{
  debug_info("[MPI-SERVER] (ID=%d): begin to do operation '%s' OP_ID %d\n", th.id, mpi_server_op2string(th.type_op), th.type_op);

  mpi_server_do_operation(&th, &the_end);

  debug_info("[MPI-SERVER] (ID=%d) end to do operation '%s'\n", th.id, mpi_server_op2string(th.type_op));
}

/**
 * @brief 'TODO'.
 *
 * 'TODO'.
 *
 * @param th  'TODO'.
 * @par Returns
 *    Nothing.
 */
void mpi_server_dispatcher(struct st_th th)
{
  int ret;

  // check params...
  if (NULL == th.params)
  {
    printf("[WORKERS ID=%d] ERROR: NULL arguments", th.id);
    return;
  }

  struct st_th th_arg;
  int disconnect = 0;
  while (!disconnect)
  {
    ret = mpi_server_comm_read_operation(th.params, (MPI_Comm)th.sd, (char *)&(th.type_op), 1, &(th.rank_client_id));
    if (ret < 0)
    {
      debug_info("[MPI-SERVER] ERROR: mpi_server_comm_readdata fail\n");
      return;
    }

    if (th.type_op == MPI_SERVER_DISCONNECT)
    {
      debug_info("[MPI-SERVER] INFO: DISCONNECT received\n");
      disconnect = 1;
      continue;
    }

    if (th.type_op == MPI_SERVER_FINALIZE)
    {
      debug_info("[MPI-SERVER] INFO: FINALIZE received\n");
      disconnect = 1;
      the_end = 1;
      continue;
    }

    // Launch worker per operation
    th_arg.params = &params;
    th_arg.sd = (MPI_Comm)th.sd;
    th_arg.function = mpi_server_run;
    th_arg.type_op = th.type_op;
    th_arg.rank_client_id = th.rank_client_id;
    th_arg.wait4me = FALSE;

    base_workers_launch(&worker, &th_arg, mpi_server_run);
  }

  debug_info("[MPI-SERVER] mpi_server_worker_run (ID=%d) close\n", th.rank_client_id);

  mpiClient_comm_close((MPI_Comm)th.sd);
}

/************************************************
 *  ... Functions
 ***********************************************/

/**
 * @brief 'TODO'.
 *
 * 'TODO'.
 *
 * @par Parameters
 *    None.
 * @return 'TODO'.
 */
int mpi_server_up(void)
{
  MPI_Comm sd;
  struct st_th th_arg;
  int ret;

  printf("\n");
  printf(" ----------------\n");
  printf(" Starting servers (%s)\n", serv_name);
  printf(" ----------------\n");
  printf("\n");

  // Initialize
  debug_msg_init();
  ret = mpi_server_comm_init(&params);
  if (ret < 0)
  {
    printf("[MPI-SERVER] ERROR: mpi_comm initialization fails\n");
    return -1;
  }
  ret = base_workers_init(&worker, params.thread_mode);
  if (ret < 0)
  {
    printf("[MPI-SERVER] ERROR: mpi_comm initialization fails\n");
    return -1;
  }

  // Initialize semaphore for server disks
  /*ret = sem_init(&(params.disk_sem), 0, 1);
  if (ret < 0) {
    printf("[MPI-SERVER] ERROR: semaphore initialize fails\n");
    return -1;
  }*/

  // Initialize semaphore for clients
  /*sprintf(params.sem_name_server, "%s%d", serv_name, getpid());
  sem_t *sem_server = sem_open(params.sem_name_server, O_CREAT, 0777, 1);
  if (sem_server == 0) {
    printf("[MPI-SERVER] ERROR: semaphore open fails\n");
    return -1;
  }*/

  // Loop: receiving + processing
  the_end = 0;
  while (!the_end)
  {
    debug_info("[MPI-SERVER] mpi_server_accept_comm()\n");

    params.client = MPI_COMM_NULL;

    sd = mpi_server_comm_accept(&params);
    if (sd == MPI_COMM_NULL)
    {
      continue;
    }

    // Launch dispatcher per aplication
    th_arg.params = &params;
    th_arg.sd = sd;
    th_arg.function = mpi_server_dispatcher;
    th_arg.type_op = 0;
    th_arg.rank_client_id = 0;
    th_arg.wait4me = FALSE;

    base_workers_launch(&worker, &th_arg, mpi_server_dispatcher);
  }

  // Wait and finalize for all current workers
  debug_info("[MPI-SERVER] base_workers_destroy\n");
  base_workers_destroy(&worker);
  debug_info("[MPI-SERVER] mpi_server_comm_destroy\n");
  mpi_server_comm_destroy(&params);

  // Close semaphores
  /*sem_destroy(&(params.disk_sem));
  sem_unlink(params.sem_name_server);*/

  // return OK
  return 0;
}

/**
 * @brief 'TODO'.
 *
 * 'TODO'.
 *
 * @param argc  'TODO'.
 * @param argv  'TODO'.
 * @return 'TODO'.
 */
int mpi_server_down(int argc, char *argv[])
{
  int ret, buf;
  char port_name[MPI_MAX_PORT_NAME];
  char srv_name[1024];
  char dns_name[2048];
  MPI_Comm server;
  FILE *file;

  printf("\n");
  printf(" ----------------\n");
  printf(" Stopping servers (%s)\n", serv_name);
  printf(" ----------------\n");
  printf("\n");

  MPI_Init(&argc, &argv);

  // Open host file
  file = fopen(params.shutdown_file, "r");
  if (file == NULL)
  {
    printf("[MPI-SERVER] ERROR: invalid file %s\n", params.shutdown_file);
    return -1;
  }

  while (fscanf(file, "%[^\n] ", srv_name) != EOF)
  {
    int version_len;
    char version[MPI_MAX_LIBRARY_VERSION_STRING];
    MPI_Get_library_version(version, &version_len);

    if (strncasecmp(version, "Open MPI", strlen("Open MPI")) != 0)
    {
      // Lookup port name
      char aux_srv_ip[1024];
      ret = ns_lookup("mpi_server", srv_name, aux_srv_ip, port_name);
      if (ret < 0)
      {
        printf("[MPI-SERVER] ERROR: server %s not found\n", dns_name);
        continue;
      }
    }
    else
    {
      // Lookup port name on nameserver
      ret = MPI_Lookup_name(srv_name, MPI_INFO_NULL, port_name);
      if (MPI_SUCCESS != ret)
      {
        printf("[MPI-SERVER] ERROR: server %s not found\n", dns_name);
        continue;
      }
    }

    // Connect with servers
    ret = MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &server);
    if (MPI_SUCCESS != ret)
    {
      printf("[MPI-SERVER] ERROR: MPI_Comm_connect fails\n");
      continue;
    }

    buf = MPI_SERVER_FINALIZE;
    MPI_Send(&buf, 1, MPI_INT, 0, 0, server);

    // MPI_Comm_disconnect( &server ); //TODO: fail
  }

  // Close host file
  fclose(file);

  // MPI_Finalize();

  return 0;
}

/************************************************
 *  ... Main
 ***********************************************/
int main(int argc, char *argv[])
{
  int ret = -1;
  char *exec_name = NULL;

  // Initializing...
  setbuf(stdout, NULL);
  setbuf(stderr, NULL);

  // Welcome...
  printf("\n");
  printf(" mpi_server\n");
  printf(" ----------\n");
  printf("\n");
  printf(" Begin.\n");
  printf("\n");

  // Get arguments..
  ret = mpi_server_params_get(&params, argc, argv);
  if (ret < 0)
  {
    mpi_server_params_show_usage();
    return -1;
  }

  // Show configuration...
  exec_name = basename(argv[0]);
  printf(" * action=%s\n", exec_name);
  gethostname(serv_name, HOST_NAME_MAX);
  printf(" * host=%s\n", serv_name);
  mpi_server_params_show(&params);

  // Do associate action...
  if (strcasecmp(exec_name, "xpn_stop_mpi_server") == 0)
  {
    ret = mpi_server_down(argc, argv);
  }
  else
  {
    ret = mpi_server_up();
  }

  return ret;
}

/* ................................................................... */
