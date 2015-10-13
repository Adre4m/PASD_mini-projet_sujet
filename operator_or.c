# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_or.h"
# include "macro_operator_c.h"

# include "value_boolean.h"
# include "value_error.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



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


