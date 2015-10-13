# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_nop.h"
# include "macro_operator_c.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c nop: does nothing.
 *
 * It is just discarded.
 * Nothing is modified.
 * 
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( nop ) 


