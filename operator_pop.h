# ifndef __OPERATOR_POP_H
# define __OPERATOR_POP_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator \c pop: remove the top \c value from the stack.
 *
 * The \c value is destroyed.
 * Nothing else is modified.
 * 
 * If the stack is empty, a \c basic_type_error is returned.
 *
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( pop ) 


# endif
