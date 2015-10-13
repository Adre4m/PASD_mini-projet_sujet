# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "operator_label.h"
# include "macro_operator_c.h"

# include "value_block.h"

# include "value_error.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief Operator \c label: when evaluated it is replaced by the corresponding \c value from the \c dictionary.
 *
 * If the associated \c value is a \c value_block, then the \c chunk's are processed in order.
 * Otherwise, it is processed as usually.
 *
 * Label can be created even if the entry is not defined in the dictionary.
 * It should be defined when evaluated.
 * 
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*!
 * Create an \c operator_label.
 *
 * \param ss non empty string
 * \pre \c ss in not \ NULL and non-empty (assert-ed)
 * \return a newly created \c operator_label
 */
chunk operator_label_create ( sstring ss )  { return NULL ; }


/*!
 * Test whether a chunk is an operator_label
 *
 * \param ch cunk to test
 * \return true iff it is an operator_label
 */
bool operator_is_label ( chunk const ch )  { return NULL ; }


