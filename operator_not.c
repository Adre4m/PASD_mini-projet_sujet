# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_not.h"
# include "macro_operator_c.h"

# include "value.h"
# include "value_boolean.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



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


