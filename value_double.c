# include <stdlib.h>
# include <stdio.h>
# include <assert.h>


# include "value_double.h"

# include "macro_value_c.h"



# undef NDEBUG   // FORCE ASSERT ACTIVATION!_




/*!
 * \file 
 * \brief \c value used to hold a \c double.
 *
 * For I/O these are just numbers with decimal point like 78.0 0.75 -568.58.
 * No exponential form is supported.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


VALUE_DECLARE( double , long double ) 


