# ifndef __OPERATOR_H
# define __OPERATOR_H

# include <stdbool.h>

# include "chunk.h"

# include "interpreter.h"


/*!
 * \file 
 * \brief \link chunk\endlink used to hold any \c operator.
 *
 * \c operator's are immutable (i.e. cannot be modified).
 *
 * A \c chunk is a \c operator if it gives a positive response to the message \link MESSAGE_OPERATOR_IS_OPERATOR \endlink.
 *
 * Any \c operator must also respond to the message \link MESSAGE_OPERATOR_EVALUATE \endlink.
 *
 * There is no \c operator_create.
 * This it thought as an abstract intermediary class.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*!
 * Test whether a \c chunk is a \c operator.
 * It is done by sending the \link MESSAGE_OPERATOR_IS_OPERATOR \endlink message and decoding the response (or the absence of).
 *
 * \param ch \c chunk to test
 * \pre \c ch must not be \c NULL (assert-ed)
 * \return \c true iff this is indeed a operator
 */
extern bool chunk_is_operator ( chunk const ch ) ;


/*!
 * Always respond positively.
 * This should be used as a method directly by any subclass.
 *
 * \param ch \c chunk to test
 * \param va unused extra arguments
 * \return \c basic_type_true regardless of the \c chunk
 */
extern basic_type chunk_is_operator_true ( chunk const ch ,
					   va_list va ) ;


/*!
 * Ask an operator to evaluate it-self.
 * This is done by sending the \link MESSAGE_OPERATOR_EVALUATE\endlink  message together with the \c interpretation_context.
 *
 * \param ch \c chunk to evaluate
 * \param ic context for the evaluation
 * \pre \ch must be an operator (assert-ed)
 * \pre \c ic must not be \c NULL (assert-ed)
 * \return \c basic_type_void unless there is an error
 */
extern basic_type operator_evaluate ( chunk const ch ,
				      interpretation_context ic ) ;


/*! Mesage to query whether is is a operator. */
# define MESSAGE_OPERATOR_IS_OPERATOR "operator_is_operator" 


/*! Mesage to evaluate an operator . */
# define MESSAGE_OPERATOR_EVALUATE "operator_evaluate" 


/*!
 * Enlarged message_action array for \c operator's.
 * Directly set \c chunk_is_operator_true.
 */
# define MESSAGE_ACTION__BASIC_OPERATOR( type )				\
  MESSAGE_ACTION__BASIC_PARAM( operator_ , type ) ,			\
  { MESSAGE_OPERATOR_IS_OPERATOR , & chunk_is_operator_true } ,		\
  { MESSAGE_OPERATOR_EVALUATE , & operator_ ## type ## _evaluate }



# endif
