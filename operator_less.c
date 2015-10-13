# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_less.h"
# include "macro_operator_c.h"

# include "value_boolean.h"
# include "value_double.h"
# include "value_int.h"
# include "value_sstring.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c<: replace the two values on top of the stack by true if they are increasing.
 *
 * Values must be both numbers (integer or double) or string.
 * The values are destroyed.
 * 
 * If the stack is not deep enough or incompatible kinds of \c value's are found, then a \c basic_type_error is returned.
 *
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( less ) 


