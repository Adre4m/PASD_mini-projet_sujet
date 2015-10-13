# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "value_boolean.h"

# include "macro_value_c.h"

# undef NDEBUG   // FORCE ASSERT ACTIVATION





/*!
 * \file 
 * \brief \c value used to hold a boolean.
 *
 * For I/O, they appear as keyword \c true and \c false.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*!
 * Keyword for boolean constant \c true. 
 * Defined for I/O.
 */
# define VALUE_BOOLEAN_STRING_TRUE "true"


/*!
 * Keyword for boolean constant \c false. 
 * Defined for I/O.
 */
# define VALUE_BOOLEAN_STRING_FALSE "false"


VALUE_DECLARE ( boolean , bool )


