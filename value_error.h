# ifndef __VALUE_VALUE_ERROR_H
# define __VALUE_VALUE_ERROR_H

# include <stdbool.h>

# include "value.h"

# include "macro_value.h"

/*!
 * \file
 * \brief Provide all the necessary to handle \c value_error.
 *
 * A \c value_error indicates an error with a code corresponding to its nature.
 * The function \link error_get_value\endlink returns this value (as a \c basic_type)
 *
 * This \c value cannot appear in any input.
 * A \c value_error can only appear an incorrect program reading, interpretation or evaluation.
 *
 * Output is like <tt>--error-- #</tt> followed by the error number.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*!
 * Provide distinct constant codes for some errors.
 * Any added value should be added at the end.
 */
typedef enum {
  VALUE_ERROR_IO_SYNTAX = 1 ,
  VALUE_ERROR_IO_EOF = 2 ,
  VALUE_ERROR_IO_MALFORMED_STRING = 3 ,
  VALUE_ERROR_IO_UNFINISHED_BLOCK = 4 ,
  VALUE_ERROR_IO_LABEL_IS_KEYWORD = 5 ,
  VALUE_ERROR_IO_LABEL_EMPTY = 6 ,
  VALUE_ERROR_EMPTY_STACK = 7 ,
  VALUE_ERROR_ILLEGAL_OPERAND = 8 ,
  VALUE_ERROR_UNDEFINED_LABEL = 9 ,
} error_code ;


VALUE_DECLARE( error , error_code ) 


# endif
