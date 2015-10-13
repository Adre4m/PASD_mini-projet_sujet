# ifndef __VALUE_INT_H
# define __VALUE_INT_H

# include <stdbool.h>

# include "value.h"

# include "macro_value.h"


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


# endif

