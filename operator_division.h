# ifndef __OPERATOR_DIVISION_H
# define __OPERATOR_DIVISION_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator \c ∕: replace the two \c value's on top of the stack by the quotient of their division.
 * 
 * The \c value's must be integer or float.
 * If both values are integer, then this is the result of the integer division.
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


OPERATOR_DECLARE ( division ) 



# endif
