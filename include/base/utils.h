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
 * @file utils.h
 * @brief Header file to 'TODO'.
 *
 * Header file to 'TODO'.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

#ifndef _UTILS_H
#define _UTILS_H

/************************************************
 *  ... Includes
 ***********************************************/
#include <stdio.h>
#include <stdarg.h>
#include <sys/time.h>
#include "base/debug_msg.h"
#include "base/trace_msg.h"

#ifdef __cplusplus
extern "C"
{
#endif

   /************************************************
    *  ... Definitions
    ***********************************************/
// Check arguments
#define FREE_AND_NULL(ptr) \
   if ((ptr) != NULL)      \
   {                       \
      free((ptr));         \
      (ptr) = NULL;        \
   }

#define NULL_RET_ERR(ptr, err_val) \
   if (NULL == (ptr))              \
   {                               \
      return -1;                   \
   }

   /************************************************
    *  ... Functions
    ***********************************************/

   /**
    * @brief Get time.
    *
    * 'TODO'.
    *
    * @par Parameters
    *    None.
    * @return 'TODO'.
    */
   long base_utils_get_time(void);

   /* .................................................................... */

#ifdef __cplusplus
}
#endif

#endif
