# ifndef __READ_CHUNK_IO_H
# define __READ_CHUNK_IO_H

# include <stdio.h>

# include "chunk.h"

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

extern chunk read_chunk_io ( FILE * f ) ;


# endif

