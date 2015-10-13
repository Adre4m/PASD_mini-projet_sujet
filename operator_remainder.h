# ifndef __OPERATOR_REMAINDER_H
# define __OPERATOR_REMAINDER_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator \c %: replace the two \c value_int's on top of the stack by the remainder of their integer division.
 *
 * The \c value's must be \c value_int.
 * Result is a \c value_int.
 * The \c value_int's are destroyed.
 * 
 * If the stack is not deep enough or a wrong kind of \c value is found, then a \c basic_type_error is returned.
 *
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( remainder ) 


# endif
