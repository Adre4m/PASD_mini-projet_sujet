# ifndef __OPERATOR_OR_H
# define __OPERATOR_OR_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator <tt>||</tt>: replace the two \c value_boolean's on top of the stack by their disjunction.
 *
 * The \c value_boolean's are destroyed.
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


OPERATOR_DECLARE ( or ) 


# endif
