# ifndef __SSTRING_H
# define __SSTRING_H

# include <stdbool.h>
# include <stdio.h>


/*!
 * \file
 * \brief This module provides a « safer » string.
 * 
 * These are not C-string but a \c struct that holds the length of the string and a pointer to the actual char sequence.
 * Please note that there is no \c '\0' to mark the end of the \c sstring.
 *
 * Empty string is encoded by 0 \c length and \c NULL \c pointer.
 *
 * assert is enforced.
 *
 * \note Cela ressemble au TDM 1, même s'il y a des différences.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*! \c sstring is a pointer to a hidden structure. */
typedef struct sstring_struct * sstring ;


/*!
 * Generate an empty \c sstring.
 *
 * \return an empty \c sstring
 */
extern sstring sstring_create_empty ( void ) ;


/*!
 * Generate a \c sstring with the same \c char sequence as a C-string.
 *
 * \param st C-string
 * \pre st is not \c NULL (assert-ed)
 * \return a sstring corresponding to st
 */
extern sstring sstring_create_string ( char const * const st ) ;


/*!
 * Destroy a \c sstring and release related resources.
 *
 * \param ss C-string to destroy
 * \pre ss is a valid \c sstring (assert-ed)
 */
extern void sstring_destroy ( sstring ss ) ;


/*!
 * Print a \c sstring to a stream.
 * There is no line return (unless it is contained in \c ss).
 *
 * \param ss \c sstring to print
 * \param f stream to print to
 * \pre ss is a valid \c sstring (assert-ed)
 * \pre f is not \c NULL (assert-ed)
 */
extern void sstring_print ( sstring ss ,
			    FILE * f ) ;

/*!
 * Concatenate a \c sstring at the end of another.
 *
 * \param ss1 \c sstring to be modified
 * \param ss2 \c sstring to concatenate to \c ss1
 * \pre \c ss1 and \c ss2 are valid \c sstring (assert-ed)
 */
extern void sstring_concatenate ( sstring ss1,
				  sstring ss2 ) ;

/*!
 * Provide a copy of a string.
 *
 * \param ss \c sstring to copy
 * \pre ss is a valid \c sstring (assert-ed)
 * \return an independant copy of \c ss
 */
extern sstring sstring_copy ( sstring ss ) ;


/*!
 * Indicate how two \c sstring are ordered alphabetically.
 *
 * \param ss1 \c sstring 
 * \param ss2 \c sstring 
 * \pre ss1 and ss2 are valid \c sstring (assert-ed)
 * \return 
 * \li 0 if ss1 == ss2
 * \li -1 if ss1 < ss2
 * \li 1 otherwise
 */
extern int sstring_compare ( sstring ss1 ,
			     sstring ss2 ) ;


/*!
 * Indicate whether a string is empty.
 *
 * This function has no side effect and can be safely used in asserts.
 *
 * \param ss \c sstring to test
 * \pre ss is a valid \c sstring (assert-ed)
 * \return true ssi \c ss is empty
 */
extern bool sstring_is_empty ( sstring ss ) ;


# endif
