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
 * @file xpn_stdio.h
 * @brief Header file to 'TODO'.
 *
 * Header file to 'TODO'.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

#ifndef _XPN_STDIO_H
#define _XPN_STDIO_H

/************************************************
 *  ... Includes
 ***********************************************/
#include "xpn.h"
#include "xpn_err.h"
#include "xpn_policy_cwd.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <xpn.h>

#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "xpn_open.h"
#include <xpn.h>


  extern struct xpn_filedesc *xpn_file_table[XPN_MAX_FILE];

/************************************************
 *  ... Functions
 ***********************************************/

  /************************************************************************/
  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param path 'TODO'.
   * @param mode 'TODO'.
   * @return 'TODO'.
   */
  FILE *xpn_fopencookie(const char *path, const char *mode);
  /************************************************************************/

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param filename 'TODO'.
   * @param mode 'TODO'.
   * @return 'TODO'.
   */
  FILE *xpn_simple_fopen(const char *filename, const char *mode);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  int xpn_simple_fclose(FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param ptr 'TODO'.
   * @param size 'TODO'.
   * @param nmemb 'TODO'.
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  size_t xpn_simple_fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param ptr 'TODO'.
   * @param size 'TODO'.
   * @param nmemb 'TODO'.
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  size_t xpn_simple_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  int xpn_simple_fgetc(FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param s 'TODO'.
   * @param tam 'TODO'.
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  char *xpn_simple_fgets(char *s, int tam, FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  int xpn_simple_getc(FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @param offset 'TODO'.
   * @param whence 'TODO'.
   * @return 'TODO'.
   */
  int xpn_simple_fseek(FILE *stream, long offset, int whence);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  long xpn_simple_ftell(FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @par Returns
   *    Nothing.
   */
  void xpn_simple_rewind(FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  int xpn_simple_fflush(FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  int xpn_simple_fileno(FILE *stream);

  /**
   * @brief 'TODO'.
   *
   * 'TODO'.
   *
   * @param stream 'TODO'.
   * @return 'TODO'.
   */
  int xpn_simple_ferror(FILE *stream);

#ifdef __cplusplus
}
#endif

#endif
