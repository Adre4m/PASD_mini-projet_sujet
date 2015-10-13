# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_def.h"
# include "macro_operator_c.h"

# include "value_protected_label.h"
# include "value_error.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c def: add an entry into the \c dictionary.
 *
 * The entry is composed of a protected label on the top of the stack and the value under it.
 * Both values are removed from the stack.
 * Nothing else is modified.
 * 
 * If the stack is not deep enough or the first one is not a \c value_protected_label, a \c basic_type_error is returned.
 *
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( def ) 


