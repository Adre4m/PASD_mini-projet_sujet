# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "value_int.h"

# include "macro_value_c.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION





/*!
 * \file 
 * \brief \c value to hold an \c int.
 * 
 * Integers are read and printed in the usual way:
 * \li '-' sign if negative (nothing for positive) followed by
 * \li sequence of digits.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


VALUE_DECLARE( int , long long int ) 



