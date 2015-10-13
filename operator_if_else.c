# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_if_else.h"
# include "operator_label.h"
# include "macro_operator_c.h"

# include "value_boolean.h"
# include "value_block.h"
# include "value_error.h"



# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c if_else: when evaluated depending the boolean on top of the stack activate next or following value on the stack.
 *
 * The \c value on top  must be a \c value_boolean and the two \c value's under mus be \c value_block or \c value_protected_label.
 * If the evaluated \c value is a \c value_block, the chunks evaluated in order.
 * If the evaluated \c value is a \c value_protected_label, then it as evaluated as the corresponding \c operator_label.
 * All three \c value's are destroyed.
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


OPERATOR_DECLARE ( if_else ) 



