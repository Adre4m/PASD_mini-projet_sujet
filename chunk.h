# ifndef __CHUNK_H
# define __CHUNK_H

# include <stdarg.h>
# include <stdio.h>

# include "basic_type.h"

/*!
 * \file
 * \brief 
 * Provide the basic layer and mechanism for object oriented programming with \c chunk as bottom class.
 *
 * The principle is to respond to a message with a \c basic_type.
 * 
 * The function \c\link chunk_answer_message()\endlink  is used to trigger the appropriate function.
 *
 * The term \em method denotes registered ( message , action ) in any "implementation" of \c chunk
 *
 * All \c chunk's must implement the following \em methods:
 * \li \c "destroy" to destroy the chunk and release ressources,
 * \li \c "print" to print the chunk on a stream (\c FILE \c*), and
 * \li \c "copy" to provide a copy of the chunk (can provide an independent copy or can use a reference counter or…).
 * Destroying an instance or a copy does not destroy the other.
 * This also implies that both should be destroyed before the programs finished.
 *
 * In each module, a function should be provided to test the nature of the \c chunk.
 * Its name is of the form:
 * \li \c chunk_is_XXX
 * \li \c value_is_XXX for sub-classes of value
 * \li \c operator_is_XXX for sub-classes of operator
 * \li …
 *
 * \note Cela ressemble au cours, même s'il y a des différences.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */

// Indicate its existence for next declaration.
struct chunk_struct ;    

/*!
 * Structure used to store a pair ( receivable message, associated action ) to define a \em method.
 *
 * \param message the C-string message accepted
 * \param action function/method called when the message is received
 */
typedef struct {
  char const * const message ;
  basic_type ( * const action ) ( struct chunk_struct * const ,
				  va_list ) ;
} message_action ;



/*!
 * Structure used to define an instance of an \c chunk.
 *
 * \param reactions regroups the definition of the methods
 * \param state stores the data for the instance
 */
// Type provided to allow other modules to define chunks
typedef struct chunk_struct {
  message_action const * reactions ;
  void * state ;
} chunk_struct ,
  * chunk ;  


/*! 
 * Send a message to a \c chunk. 
 * If the message corresponds to a \em method, it is activated and the basic_type it returns is returned.
 * Otherwise, \c basic_type_error is returned.
 *
 * \param ch \c chunk the method is called upon
 * \param message name of the method to activate
 * \param ... extra arguments transmitted to the method
 * \pre no NULL pointer (assert-ed)
 * \return the \c basic_type returned from the invoked method, if none \c basic_type_error
 */
extern basic_type chunk_answer_message ( chunk const ch ,
					 char const * const message ,
					 ...  ) ;


/*! 
 * Destroy a \c chunk and release all associated ressources.
 * It invokes the \em method \c "destroy".
 *
 * \param ch \c chunk to destroy
 * \pre \c ch is not \c NULL (assert-ed)
 * \return \c basic_type_error if \c ch is NULL, otherwise the \c basic_type returned by the \em method \c "destroy"
 */
extern basic_type chunk_destroy ( chunk ch ) ;


/*! 
 * provide a copy of a \c chunk.
 * It invokes the method \c "copy".
 *
 * \param ch \c chunk to copy
 * \pre \c ch is not \c NULL (assert-ed)
 * \return the \c basic_type holds a pointer the copy
 */
extern chunk chunk_copy ( chunk ch ) ;


/*! 
 * Print the chunk to the designated \c FILE \c *.
 * It invokes the method \c "print".
 *
 * \param ch \c chunk to print
 * \param f stream to print to
 * \pre \c ch is not \c NULL (assert-ed)
 * \pre \c f is not be \c NULL (assert-ed)
 * \return the \c basic_type returned by the \c method invoked.  
 */
extern basic_type chunk_print ( chunk ch ,
				FILE * f ) ;


/*! Hard encoded message for method \c chunk_destroy */
# define MESSAGE_DESTROY "destroy" 

/*! Hard encoded message for method \c chunk_copy */
# define MESSAGE_COPY "copy"

/*! Hard encoded message for method \c chunk_print */
# define MESSAGE_PRINT "print" 


/*! 
 * Generated the action listing for \em methods that \em must be present in any \c chunk.
 *
 * \param chunk_ is the base name, to be changed to reflect \em class \em hierarchies (f.e. value and operator)
 * \param type to indicate the proper name of the chunk type
 */ 
# define MESSAGE_ACTION__BASIC_PARAM( chunk_ , type )	\
  { MESSAGE_DESTROY , & chunk_ ## type ## _destroy } ,	\
  { MESSAGE_PRINT , & chunk_ ## type ## _print } ,	\
  { MESSAGE_COPY , & chunk_ ## type ## _copy } 


/*! 
 * Generate the action listing for chunk that are not in any special sub-classification.
 *
 * \param type to indicate the proper name of the chunk type
 */ 
# define MESSAGE_ACTION__BASIC_CHUNK( type )  \
  MESSAGE_ACTION__BASIC_PARAM( chunk_ , type )


# endif
