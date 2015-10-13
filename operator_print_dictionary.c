# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_print_dictionary.h"
# include "macro_operator_c.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c print_dictionary: print the dictionary on \c stdout.
 *
 * For example: \verbatim
vvvvvvvv dictionary vvvvvvvvvv
"Be" => true
"Fe" => {
"tt"
pop
}
^^^^^^^^ dictionary ^^^^^^^^^\endverbatim
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


OPERATOR_DECLARE ( print_dictionary ) 


