# ifndef __OPERATOR_DIFFERENT_H
# define __OPERATOR_DIFFERENT_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator \c!=: replace the two \c value's on top of the stack by true if they are different.
 *
 * Values must be both bool, numbers (integer or double) or string.
 * The values are destroyed.
 * 
 * If the stack is not deep enough or incompatible types of value are found, then a \c basic_type_error is returned.
 *
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( different ) 


# endif
