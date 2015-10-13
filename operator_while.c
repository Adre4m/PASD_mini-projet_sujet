# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_while.h"

# include "macro_operator_c.h"

# include "linked_list_chunk.h"

# include "operator_label.h"
# include "value_boolean.h"
# include "value_block.h"
# include "value_protected_label.h"

# include "value_error.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c while: as long as the fist \c value on the top evaluates to true evaluate the previous argument. 
 *
 * The first two \c value's are removed and used each time on the remaining of the stack.
 * At the end, they are destroyed.
 *
 * The two values on top must be \c values_block or \c values_protected_label.
 * Any \c values_protected_label is evaluated as the corresponding \c operator_label.
 * They are re-evaluated each time.
 *
 * The first one should leave a \c value_boolean on top of the stack (any other modification due to the evaluation remains).
 * \li If the value is true, then the other \c value is evaluated and then the process is restarted.
 * \li If the value is false, then the evaluation is finished.
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


OPERATOR_DECLARE ( while ) 


