# include <string.h>
# include <ctype.h>
# include <assert.h>

# include "read_chunk_io.h"

# include "value_boolean.h"
# include "value_sstring.h"
# include "value_double.h"
# include "value_int.h"
# include "value_block.h"
# include "value_protected_label.h"
# include "value_error.h"

# include "operator_addition.h"
# include "operator_division.h"
# include "operator_multiplication.h"
# include "operator_subtraction.h"
# include "operator_remainder.h"

# include "operator_less.h"
# include "operator_less_equal.h"

# include "operator_equal.h"
# include "operator_different.h"

# include "operator_and.h"
# include "operator_or.h"
# include "operator_not.h"

# include "operator_label.h"

# include "operator_creator_list.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Read \c chunk from a stream.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */

/*!
 * Maximal length of a token or label.
 * Larger length labels or keywords are not allowed.
 */
# define TOKEN_KEYWORD_MAX_LEGTH 50


/*!
 * Read a token from a stream.
 *
 * The first (non-space) character is read and depending on it, only some \c chunk are possible.
 * More characters are read until:
 * \li chunk is fully read, and
 * \li there is no ambiguity  (\c"!" from \c"!=", minus operation from sign of number…).
 * If one (or more) \c char that could belong to another \c chunk are read to settle ambiguity, they are put back (with \c ungetc).
 *
 * Label (protected or not) are distinguished from keywords by using the table in \c operator_creator_list.
 *
 * Static functions are used to handle separately numbers (int or float), label or keyword, sstring, block…
 *
 * Following spaces are discarded.
 *
 * If the OEF is reached before anything is read, then a \c value_error with \c VALUE_ERROR_IO_EOF is returned.
 *
 * If the input cannot form a legal \c chunk, then a corresponding  \c value_error is returned.
 *
 * \param f \c stream to read from
 * \pre \c f is not \c NULL (assert-ed)
 * \return chunk read (should be a \c value or an \c operator) or a \c value_error if reading fail.
 */

chunk read_chunk_io ( FILE * f )  { return NULL ; }



