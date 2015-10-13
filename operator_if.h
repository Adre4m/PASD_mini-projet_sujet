# ifndef __OPERATOR_IF_H
# define __OPERATOR_IF_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator \c if: when evaluated depending the \c value_boolean on top of the stack activates or not the next value on the stack.
 *
 * Both values are destroyed.
 * Value on top must be a \c value_boolean and under should be a \c value_block or \c value_protected_label.
 * If this last \c value is a \c value_block, the chunks evaluated in order.
 * If this last \c value is a \c value_protected_label, then it as evaluated as the corresponding \c operator_label.
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


OPERATOR_DECLARE ( if ) 


# endif
