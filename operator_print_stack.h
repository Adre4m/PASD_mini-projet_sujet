# ifndef __OPERATOR_PRINT_STACK_H
# define __OPERATOR_PRINT_STACK_H

# include "operator.h"
# include "macro_operator.h"


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


# endif
