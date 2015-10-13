# ifndef __OPERATOR_LABEL_H
# define __OPERATOR_LABEL_H

# include "operator.h"
# include "macro_operator.h"


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
extern chunk operator_label_create ( sstring ss ) ;


/*!
 * Test whether a chunk is an operator_label
 *
 * \param ch cunk to test
 * \return true iff it is an operator_label
 */
extern bool operator_is_label ( chunk const ch ) ;


# endif
