# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_stop_trace.h"
# include "macro_operator_c.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c stop_trace: the program is no more traced.
 *
 * If trace was on, then the end of tracing is traced.
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

OPERATOR_DECLARE ( stop_trace ) 


