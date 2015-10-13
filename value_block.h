# ifndef __VALUE_BLOCK_H
# define __VALUE_BLOCK_H

# include <stdbool.h>

# include "value.h"

# include "macro_value.h"

# include "linked_list_chunk.h"


/*!
 * \file 
 * \brief \c value used to hold an \c linked_list_chunk.
 *
 * The \c linked_list_chunk can be accessed and manipulated directly with \link value_block_get_list() \endlink.
 * Thus \c value_block is \em mutable.
 *
 * Copies are distinct (deep copy of the structure) so that acting on one does not modify any copy.
 *
 * Its output is like:
 * \verbatim
 { 
 "Bob"
 3
 +
 \Bob
 def
 true
 } \endverbatim
 *
 * In input, spaces and newlines are meaningless as long as the order of \c chunk's are preserved and they are separated, as in any \c pf program.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


VALUE_DECLARE ( block , linked_list_chunk )


/*!
 * Return the \c linked_list_chunk held.
 *
 * This is not a copy but a direct access.
 *
 * \param vb chunk to query
 * \pre \c vb must be a \c value_block (assert-ed)
 * \return the \c linked_list_chunk held
 */
extern linked_list_chunk value_block_get_list ( chunk const vb ) ;


# endif
