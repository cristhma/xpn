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
 * @file mpi_server_d2xpn.h
 * @brief Header file to 'TODO'.
 *
 * Header file to 'TODO'.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

#ifndef _MPI_SERVER_D2XPN_H_
#define _MPI_SERVER_D2XPN_H_

/************************************************
 *  ... Includes
 ***********************************************/
#include <sys/param.h>
#include <stdio.h>
#include <sys/file.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/errno.h>

#include "all_system.h"
#include "base/utils.h"
#include "mpi_server_params.h"
#include "mpi_server_ops.h"

#include "xpn.h"

#define PRELOAD_SYNC 0
#define PRELOAD_ASYNC 1

/************************************************
 *  ... Functions
 ***********************************************/
/**
 * @brief 'TODO'.
 *
 * 'TODO'.
 *
 * @param params  'TODO'.
 * @param origen  'TODO'.
 * @param destino  'TODO'.
 * @return 'TODO'.
 */
int mpi_server_d2xpn(mpi_server_param_st *params, char *origen, char *destino);

#endif
