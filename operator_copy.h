# ifndef __OPERATOR_COPY_H
# define __OPERATOR_COPY_H

# include "operator.h"
# include "macro_operator.h"


/*!
 * \file
 * \brief Operator copy: duplicate the \c k top values on the stack.
 *
 * Integer \c k is on top of the stack.
 * Once \c k is removed, the remaining top \c k elements are duplicate.
 *
 * On
\verbatim [top]                                k   ch0 ch_1 ch_2 ...  ch_k-2 ch_k-1   ch_k ch_k+1 ch_k+2\endverbatim
* the evaluation of \c operator_copy results in:
\verbatim [top] ch0 ch_1 ch_2 ...  ch_k-2 ch_k-1   ch0 ch_1 ch_2 ...  ch_k-2 ch_k-1   ch_k ch_k+1 ch_k+2\endverbatim
 * 
 * If there are less than \k elements, only the present elements are duplicated; this is not considered as an error.
 *
 * If the top element is not a \c value_int an error is returned.
 *
 * assert is enforced.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


OPERATOR_DECLARE ( copy ) 



# endif
