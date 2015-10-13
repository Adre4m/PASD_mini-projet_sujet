# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_print_stack.h"
# include "macro_operator_c.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c print_stack: print the stack on \c stdout.
 *
 * For example: \verbatim
vvvvvvvv stack  top  vvvvvvvvvv
-52.580000
"zet"
{
33
pop
print
}
true
^^^^^^^^ stack bottom ^^^^^^^^^ \endverbatim
 *
 * Nothing is modified.
 * 
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( print_stack ) 


