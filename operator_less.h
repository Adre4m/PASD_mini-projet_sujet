# ifndef __OPERATOR_LESS_H
# define __OPERATOR_LESS_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator \c<: replace the two values on top of the stack by true if they are increasing.
 *
 * Values must be both numbers (integer or double) or string.
 * The values are destroyed.
 * 
 * If the stack is not deep enough or incompatible kinds of \c value's are found, then a \c basic_type_error is returned.
 *
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( less ) 


# endif
