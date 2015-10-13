# ifndef __OPERATOR_PRINT_H
# define __OPERATOR_PRINT_H

# include "operator.h"
# include "macro_operator.h"

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


# endif
