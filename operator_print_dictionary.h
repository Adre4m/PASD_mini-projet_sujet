# ifndef __OPERATOR_PRINT_DICTIONARY_H
# define __OPERATOR_PRINT_DICTIONARY_H

# include "operator.h"
# include "macro_operator.h"


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


# endif
