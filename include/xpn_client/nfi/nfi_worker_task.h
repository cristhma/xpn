/*
 *  Copyright 2000-2023 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
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
 * @file nfi_worker_task.h
 * @brief Header file to 'TODO'.
 *
 * Header file to 'TODO'.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

#ifndef _NFI_WORKER_TASK_H_
#define _NFI_WORKER_TASK_H_

/************************************************
 *  ... Includes
 ***********************************************/
#include "all_system.h"
#include "debug_msg.h"
#include "trace_msg.h"
#include "workers.h"
#include "nfi.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /** @struct nfi_worker_io
   *  This is a struct
   *
   *  @var nfi_worker_io::offset
   *    A 'TODO'.
   *  @var nfi_worker_io::size
   *    A 'TODO'.
   *  @var nfi_worker_io::buffer
   *    A 'TODO'.
   */
  struct nfi_worker_io
  {
    off_t offset;
    size_t size;
    void *buffer;
  };

  /** @struct nfi_worker_args
   *  This is a struct
   *
   *  @var nfi_worker_args::operation
   *    A 'TODO'.
   *  @var nfi_worker_args::result
   *    A 'TODO'.
   *  @var nfi_worker_args::url
   *    A 'TODO'.
   *  @var nfi_worker_args::master_node
   *    A 'TODO'.
   *  @var nfi_worker_args::is_master_node
   *    A 'TODO'.
   *  @var nfi_worker_args::virtual_path
   *    A 'TODO'.
   *  @var nfi_worker_args::storage_path
   *    A 'TODO'.
   *  @var nfi_worker_args::newurl
   *    A 'TODO'.
   *  @var nfi_worker_args::fh
   *    A 'TODO'.
   *  @var nfi_worker_args::attr
   *    A 'TODO'.
   *  @var nfi_worker_args::opt
   *    A 'TODO'.
   *  @var nfi_worker_args::inf
   *    A 'TODO'.
   *  @var nfi_worker_args::n_io
   *    A 'TODO'.
   *  @var nfi_worker_args::io
   *    A 'TODO'.
   *  @var nfi_worker_args::entry
   *    A 'TODO'.
   *  @var nfi_worker_args::type
   *    A 'TODO'.
   */
  struct nfi_worker_args
  {
    int operation;
    ssize_t result;

    char url[PATH_MAX];
    int master_node;
    int is_master_node;

    char virtual_path[PATH_MAX];
    char storage_path[PATH_MAX];
    char newurl[PATH_MAX];
    struct nfi_fhandle *fh;
    struct nfi_attr *attr;
    int opt;

    struct nfi_info *inf;

    int n_io;
    struct nfi_worker_io *io;
    struct dirent *entry;
    unsigned char *type;
  };

  /** @struct nfi_worker
   *  This is a struct
   *
   *  @var nfi_worker::thread
   *    A 'TODO'.
   *  @var nfi_worker::pth
   *    A 'TODO'.
   *  @var nfi_worker::mt
   *    A 'TODO'.
   *  @var nfi_worker::cnd
   *    A 'TODO'.
   *  @var nfi_worker::ready
   *    A 'TODO'.
   *  @var nfi_worker::wb
   *    A 'TODO'.
   *  @var nfi_worker::warg
   *    A 'TODO'.
   *  @var nfi_worker::server
   *    A 'TODO'.
   *  @var nfi_worker::arg
   *    A 'TODO'.
   */
  struct nfi_worker
  {
    int thread;

    // OLD
    pthread_t pth;
    pthread_mutex_t mt;
    pthread_cond_t cnd;
    int ready;

    // NEW
    worker_t wb;
    struct st_th warg;

    struct nfi_server *server;
    struct nfi_worker_args arg; // TODO: Convert this into a list of 'struct nfi_worker_args' to make Expand reentrant
  };

#ifdef __cplusplus
}
#endif

#endif
