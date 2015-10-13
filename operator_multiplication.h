# ifndef __OPERATOR_MULTIPLICATION_H
# define __OPERATOR_MULTIPLICATION_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator \c *: replace the two \c value's on top of the stack by their product.
 *
 * The \c value's must be integer or float.
 * The result is an integer \c value iff both \c value's are integer.
 * The \c value's are destroyed.
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


OPERATOR_DECLARE ( multiplication ) 


# endif
