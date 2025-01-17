/*
 *  Copyright 2000-2023 Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez
 * Garcia, Borja Bergua Guerra
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
 * @file string_misc.h
 * @brief Header file to Strings.
 *
 * Header file to to perform operations on strings (length, equal, dup, etc.).
 *
 * @authors Felix Garcia Carballeira, Diego Camarmas Alonso, Alejandro Calderon Mateos, Luis Miguel Sanchez Garcia,
 * Borja Bergua Guerra
 * @date  Jul 22, 2021
 * @bug No known bugs.
 */

#ifndef _STRING_MISC_H_
#define _STRING_MISC_H_

/************************************************
 *  ... Includes
 ***********************************************/
#include "all_system.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************
 *  ... Functions
 ***********************************************/

/**
 *   Return the string length of 'str'.
 *
 *   @param str the string.
 *   @return the string length.
 *
 */
long base_string_misc_length(
    /*IN*/ char *str);

/**
 *   Return true if and only if the strings 'str1' and 'str2' are equals.
 *
 *   @param str1 the first string.
 *   @param str2 the second string.
 *   @return true (1) iff are equals or false (0) in other case.
 *
 */
int8_t base_string_misc_equal(
    /*IN*/ char *str1,
    /*IN*/ char *str2);

/**
 *   Return a string clone of 'str'.
 *
 *   @param str the string.
 *   @return a clone of 'str'.
 *
 */
char *base_string_misc_dup(
    /*IN*/ char *str);

/**
 *
 *     Like 'strlen' but also accept a string with format.
 *
 *     @param  format string format.
 *     @param  argl   format params.
 *     @return string legth.
 *
 */
int base_string_misc_length_format(
    /*IN*/ char *format,
    /*IN*/ va_list argl);

/**
 *
 *     Like vsprintf, but request dynamic memory
 *      to write string elements into.
 *
 *     @param  format string format.
 *     @param  argl   format params.
 *     @return string pointer or NULL if error.
 *
 */
char *base_string_misc_dynamic_vsprintf(
    /*IN*/ char *format,
    /*IN*/ va_list argl);

/**
 *
 *     Like before, but with variable arguments.
 *
 *     @param  format string with message format.
 *     @return string pointer or NULL if error.
 *
 */
char *base_string_misc_dynamic_vsprintf_mul_vars(
    /*IN*/ char *format, ...);

/* .................................................................... */

#ifdef __cplusplus
}
#endif

#endif /* _STRING_MISC_H */
