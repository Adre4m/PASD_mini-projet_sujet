# ifndef __VALUE_H
# define __VALUE_H

# include <stdbool.h>

# include "chunk.h"


/*!
 * \file 
 * \brief Chunk used to hold any \c value.
 *
 * Except for \c value_block, all \c value's are immutable (i.e. cannot be modified).
 *
 * A \c chunk is a \c value if it gives a positive response to the message \link MESSAGE_VALUE_IS_VALUE \endlink.
 *
 * \c value's must also respond to the message \link MESSAGE_VALUE_GET_VALUE \endlink.
 *
 * There is no \c …_create
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
 * Test whether a chunk is a value.
 * It is done by sending the \link MESSAGE_VALUE_IS_VALUE \endlink message and decoding the response (or the absence of).
 *
 * \param ch \c chunk to test
 * \pre \c ch must not be \c NULL (assert-ed)
 * \return \c true iff this is indeed a value
 */
extern bool chunk_is_value ( chunk const ch ) ;


/*!
 * Always respond positively.
 * This should be used as a method directly by any subclass.
 *
 * \param ch \c chunk to test
 * \param va unused extra arguments
 * \return \c basic_type_true
 */
extern basic_type chunk_is_value_true ( chunk const ch ,
					va_list va ) ;


/*!
 * Return the value held in a \c value.
 * It is done by sending the \link MESSAGE_VALUE_get_VALUE \endlink message and decoding the response.
 *
 * \param ch \c chunk to query
 * \pre \c ch must be a value (assert-ed)
 * \return the held value (not a copy)
 */
extern basic_type value_get_value ( chunk const ch ) ;


/*! Mesage to query whether a \c chunk is a value. */
# define MESSAGE_VALUE_IS_VALUE "value_is_value" 


/*! Mesage to get the value held. */
# define MESSAGE_VALUE_GET_VALUE "value_get_value"


/*!
 * Enlarged message_action array for values.
 * Directly sets \c chunk_is_value_true.
 */
# define MESSAGE_ACTION__BASIC_VALUE( type )			\
  MESSAGE_ACTION__BASIC_PARAM( value_ , type ) ,		\
  { MESSAGE_VALUE_IS_VALUE , & chunk_is_value_true } ,		\
  { MESSAGE_VALUE_GET_VALUE , & value_ ## type ## _get_value }


# endif
