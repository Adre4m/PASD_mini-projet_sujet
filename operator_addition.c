# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_addition.h"
# include "macro_operator_c.h"

# include "value_double.h"
# include "value_int.h"

# include "value_error.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c +: replace the two \c value's on top of the stack by their sum.
 *
 * The \c value's must be integer or float.
 * The result is an integer \c value iff both \c value's are integer.
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


OPERATOR_DECLARE ( addition ) 


