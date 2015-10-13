# ifndef __VALUE_SSTRING_H
# define __VALUE_SSTRING_H

# include "value.h"
# include "sstring.h"

# include "macro_value.h"


/*!
 * \file 
 * \brief \c value to hold a \c sstring.
 *
 * \c value_sstring are read and printed with \c '"' delimiters like <tt>"ed fe"</tt>.
 * On input, use \c "\"" for a \c '"', \c '\n' for a newline, \c '\t' for a tabulation and \c '\\' for a backspace char.
 * Protective \c '\\' are not restored on printing (i.e. follows the \c print of \link sstring\endlink)
 *
 * There is \em no \em limit to the length of a string.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


VALUE_DECLARE ( sstring , sstring ) 


# endif
