# ifndef __OPERATOR_NOT_H
# define __OPERATOR_NOT_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator \c !: replace the \c value_boolean on top of the stack by its negation.
 *
 * The \c value_boolean is destroyed.
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


OPERATOR_DECLARE ( not ) 


# endif
