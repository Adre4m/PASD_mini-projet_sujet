# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_equal.h"
# include "macro_operator_c.h"

# include "value_boolean.h"
# include "value_sstring.h"
# include "value_double.h"
# include "value_int.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c ==: replace the two \v value's on top of the stack by true if they are equal.
 *
 * Values must be both bool, numbers (integer or double) or string.
 * The values are destroyed.
 * 
 * If the stack is not deep enough or incompatible types of value are found, then a \c basic_type_error is returned.
 *
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( equal ) 


