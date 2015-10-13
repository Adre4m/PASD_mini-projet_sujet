# ifndef __DICTIONARY_H
# define __DICTIONARY_H


# include <stdio.h>
# include <stdbool.h>


# include "sstring.h"
# include "chunk.h"

/*!
 * \file
 * \brief Provide a dictionary (associative table).
 * \li keys must be non-empty \c sstring's
 * \li values must be \c chunk's
 *
 * Keys and values are copied to get independent long term storage.
 * In the same spirit, queried values are \b copies. 
 * The <b>caller is in charge of destroying copies</b>; this is indicated by the \c _copy in the query function name.
 *
 * Values are stored in an ordered binary tree.
 * They are two data structures: one for the dictionary and one for nodes.
 *
 * \note Cela ressemble au TDM 3, même s'il y a des différences.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*! \c dictionary is a pointer to the hidden structure for dictionary. */
typedef struct dictionary_struct * dictionary ;  


/*!
 * Generate an empty \c dictionary.
 *
 * \return an empty \c dictionary
 */
extern dictionary dictionary_create ( void ) ;


/*!
 * Add an entry \c (key,val) into a \c dictionary.
 *
 * Copies of key and val are made.
 * The original values can be safely destroyed after the call.
 *
 * \param dic \c dictionary to modify
 * \param key insertion key
 * \param val inserted value
 * \pre no pointer is NULL (assert-ed)
 * \pre key is not an empty string  (assert-ed)
 */
extern void dictionary_set ( dictionary dic ,
			     sstring key ,
			     chunk val ) ;


/*!
 * Retrieve a \b copied value from a \c dictionary according to a \c key.
 *
 * \param dic \c dictionary to query from
 * \param key key to search a value for
 * \pre no pointer is NULL (assert-ed)
 * \pre key is not empty
 * \return a \b copy of the associated \c chunk or NULL if undefined 
 */
extern chunk dictionary_get_copy ( dictionary dic ,
				   sstring key ) ;


/*!
 * Destroy a \c dictionary and released associated resources.
 * All keys and values are destroyed.
 *
 * \param dic \c dictionary to destroy
 * \pre no pointer is NULL (assert-ed)
 */
extern void dictionary_destroy ( dictionary dic ) ;


/*!
 * Print a \c dictionary to a stream.
 * Entries are printed in \c key alphabetical order.
 * The format is as in the following example with and \c value_integer and a \c value_blok
 \verbatim
 "Bob" => 3
 "Increment_Bob" => {
 Bob
 1
 +
 \Bob
 def
 } \endverbatim
 * \param dic \c dictionary to print
 * \param f stream to print to
 * \pre no pointer is NULL (assert-ed)
 */
extern void dictionary_print ( dictionary dic ,
			       FILE * f ) ;





# endif
