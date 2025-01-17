/*
 *  Copyright 2020-2023 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
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
 * @file string_misc.c
 * @brief File to 'TODO'.
 *
 * File to 'TODO'.
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia, Borja Bergua Guerra
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

/************************************************
 *  ... Includes
 ***********************************************/
#include "base/string_misc.h"

/************************************************
 *  ... Functions
 ***********************************************/

long base_string_misc_length(/*IN*/ char *str)
{
  /* check params */
  if (str == NULL)
    return 0L;

  return (long)strlen(str);
}

int8_t base_string_misc_equal(/*IN*/ char *str1,
                         /*IN*/ char *str2)
{
  /* easy cases */
  if (str1 == str2)
    return (1);
  if ((str1 == NULL) || (str2 == NULL))
    return (0);

  /* use strcmp */
  if ((strcmp(str1, str2) == 0))
    return (1);

  return (0);
}

char *base_string_misc_dup(/*IN*/ char *str)
{
  int lenstr;
  char *pch;

  /* check params */
  if (NULL == str)
    return NULL;

  /* alloc memory for the clone... */
  lenstr = base_string_misc_length(str) + 1;
  pch = (char *)malloc(lenstr);
  if (NULL == pch)
    return NULL;

  /* copy contents */
  memmove(pch, str, lenstr);
  return pch;
}

int base_string_misc_length_format(/*IN*/ char *format,
                        /*IN*/ va_list argl)
{
  int ineed;
  static FILE *nullfd = NULL;

  if (nullfd == NULL)
  {
    nullfd = fopen(NULL_DEVICE_PATH, "w");
    /*
     *   we will lost one file descriptor,
     *   because we never "fclose(nullfd)".
     */
  }

  if (strchr(format, '%') != NULL)
  {
    ineed = vfprintf(nullfd, format, argl);
  }
  else /* only a string, not format */
  {
    ineed = strlen(format);
  }

  return ineed;
}

char *base_string_misc_dynamic_vsprintf(/*IN*/ char *format,
                            /*IN*/ va_list argl)
{
  char *baux;
  int ineed;

  ineed = base_string_misc_length_format(format, argl);
  baux = (char *)malloc(ineed + 1);
  if (NULL == baux)
    return NULL;

  vsprintf(baux, format, argl);

  return baux;
}

char *base_string_misc_dynamic_vsprintf_mul_vars(/*IN*/ char *format,
                           ...)
{
  char *saux;
  va_list varg;

  va_start(varg, format);
  saux = base_string_misc_dynamic_vsprintf(format, varg);
  va_end(varg);

  return saux;
}

/* ...................................................................... */
