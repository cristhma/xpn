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
 * @file xpn_init.h
 * @brief Header file to 'TODO'.
 *
 * Header file to 'TODO'.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

#ifndef _XPN_INIT_H
#define _XPN_INIT_H

/************************************************
 *  ... Includes
 ***********************************************/
#include "all_system.h"
#include "base/path_misc.h"
#include "xpn_policy_init.h"
#include "xpn_cwd.h"
#include "xpn_file.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define XPN_MAX_PART 128

  extern struct xpn_partition xpn_parttable[XPN_MAX_PART];

/************************************************
 *  ... Functions
 ***********************************************/

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param partname 'TODO'.
   * @return 'TODO'.
   */
  int xpn_init_partition(char *partname);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @par Parameters
   *    None.
   * @return 'TODO'.
   */
  int xpn_simple_destroy(void);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @par Parameters
   *    None.
   * @return 'TODO'.
   */
  int xpn_simple_init(void);

#ifdef __cplusplus
}
#endif

#endif
