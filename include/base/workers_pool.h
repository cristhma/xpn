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
 * @file workers_pool.h
 * @brief Workers Pool.
 *
 * Header file where functions are defined to manage the creation,
 * deletion and execution of threads or workers pool.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

#ifndef _WORKERS_POOL_H_
#define _WORKERS_POOL_H_

/************************************************
 *  ... Includes
 ***********************************************/
#include "all_system.h"
#include "workers_common.h"

// Thread count multiplier
#define POOL_OVERSUSCRIPTION 2
// End pool
#define TH_FINALIZE 200

/************************************************
 *  ... Datatype
 ***********************************************/
/** @struct worker_pool_t
 *  This is a struct
 *
 *  @var worker_pool_t::m_pool
 *    A 'TODO'.
 *  @var worker_pool_t::c_pool_no_full
 *    A 'TODO'.
 *  @var worker_pool_t::c_poll_no_empty
 *    A 'TODO'.
 *  @var worker_pool_t::m_pool_end
 *    A 'TODO'.
 *  @var worker_pool_t::POOL_MAX_THREADS
 *    Indicates the maximum number of workers/threads.
 *  @var worker_pool_t::thid
 *    A 'TODO'.
 *  @var worker_pool_t::operations_buffer
 *    Buffer with a maximum capacity of 'MAX_OPERATIONS' operations.
 *  @var worker_pool_t::n_operation
 *    Number of operations in the buffer.
 *  @var worker_pool_t::deq_pos
 *    Position of the operation to be extracted from the buffer.
 *  @var worker_pool_t::enq_pos
 *    Position in the buffer where an operation will be queued.
 *  @var worker_pool_t::pool_end
 *    Control flag to finalize all the created workers.
 */
typedef struct {
    pthread_mutex_t m_pool;
    pthread_cond_t c_pool_no_full;
    pthread_cond_t c_poll_no_empty;
    pthread_mutex_t m_pool_end;

    int POOL_MAX_THREADS;
    pthread_t *thid;

    struct st_th operations_buffer[MAX_OPERATIONS];
    int n_operation;
    int deq_pos;
    int enq_pos;
    int pool_end;
} worker_pool_t;

/************************************************
 *  ... Functions: API
 ***********************************************/
/**
 * @brief Worker pool init.
 *
 * Creates the buffer and the number of threads defined 
 * with their respective variables and structures (condition variables, mutex, etc).
 *
 * @param w 'TODO'.
 * @return 'TODO'.
 */
int base_worker_pool_init(worker_pool_t *w);

/**
 * @brief Worker pool destroy.
 *
 * Finalize and release all structures and threads.
 *
 * @param w 'TODO'.
 * @par Returns
 *    Nothing.
 */
void base_worker_pool_destroy(worker_pool_t *w);

/**
 * @brief Worker pool enqueue.
 *
 * The dispatcher puts operations to the queue.
 *
 * @param w 'TODO'.
 * @param th_arg 'TODO'.
 * @param worker_function 'TODO'.
 * @par Returns
 *    Nothing.
 */
void base_worker_pool_enqueue(worker_pool_t *w, struct st_th *th_arg, void (*worker_function)(struct st_th));

/**
 * @brief Worker pool dequeue.
 *
 * Operations are extracted from the queue.
 *
 * @param w 'TODO'.
 * @return 'TODO'.
 */
struct st_th base_worker_pool_dequeue(worker_pool_t *w);

/**
 * @brief Worker pool wait.
 *
 * Wait for a worker.
 *
 * @param th_arg 'TODO'.
 * @return 'TODO'.
 */
int base_worker_pool_wait(struct st_th *th_arg);

#endif
