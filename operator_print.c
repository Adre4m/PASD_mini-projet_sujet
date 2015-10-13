# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_print.h"
# include "macro_operator_c.h"


# include "value_error.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION


/*!
 * \file
 * \brief Operator \c print: print the top \c value of the stack on \c stdout.
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


OPERATOR_DECLARE ( print ) 


