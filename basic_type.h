# ifndef __BASIC_TYPE_H
# define __BASIC_TYPE_H

# include <stdbool.h>

/*!
 * \file
 * \brief 
 * Provide a 'universal' elementary type able to store any 'basic' value.
 *
 * Use
 * \li long_long_int: any integer type (including unsigned, char, size...)
 * \li long double: any float type
 * \li pointer: any pointer
 * \li bool and constant basic_type_true and basic_type_false: booleans
 * \li void constant: for void (i.e. nothing)
 * \li error constant: for error
 *
 * It should be used as a basic value and passed as is, avoiding any pointer/reference.
 * (this is why there is no basic_type_destroy available).
 *
 * Cela ressemble au cours, même s'il y a des différences.
 *
 * assert is enforced to test that the get_xxx are used on the appropriate type.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */

/*!
 * Type is given otherwise direct use is impossible.
 * But it should never be accessed directly: appropriate functions should be used. 
 */
typedef struct {
  /*! Encode the type */
  enum { t_error, t_long_long_int , t_long_double , t_pointer, t_void , t_true , t_false
  } type ;
  /*! Encode the value */
  union {
    long long int val_long_long_int ;
    long double val_long_double ;
    void * val_pointer ;
  } value ;
} basic_type ;


/*! Constant indicating a void value / the absence of a value. */
extern basic_type const basic_type_void ;


/*! Constant indicating an error. */
extern basic_type const basic_type_error ;


/*! Constant encoding the boolean value false. */
extern basic_type const basic_type_false ;


/*! Constant encoding the boolean value true. */
extern basic_type const basic_type_true ;


/*! 
 * Test if a basic_type represents an error.
 *
 * \return true iff bt -> type is t_error
 */
extern bool basic_type_is_error ( basic_type bt ) ;


/*! 
 * Test if a basic_type represents true.
 * Returns false for t_false, but also for t_error, t_void…
 *
 * \return true iff bt -> type is t_true
 */
extern bool basic_type_is_true ( basic_type bt ) ;



/*! 
 * Encode an integer value as a \c basic_type.
 *
 * \param long_long_int the integer to encode
 * \return basic_type representing the integer
 */
extern basic_type basic_type_long_long_int ( long long int const long_long_int ) ;


/*! 
 * Recover the integer encoded in a basic_type.
 *
 * \param bt basic_type representing an integer
 * \pre bt must be of .type t_long_long_int (assert-ed)
 * \return the encoded integer
 */
extern long long int basic_type_get_long_long_int ( basic_type const bt ) ;


/*! 
 * Encode a float value as a \c basic_type.
 *
 * \param long_double the float to encode
 * \return basic_type encoding the float
 */
extern basic_type basic_type_long_double ( long double const long_double ) ;


/*! 
 * Recover the float encoded in a basic_type.
 *
 * \param bt basic_type representing a float
 * \pre bt must be of .type t_long_double (assert-ed)
 * \return the encoded float
 */
extern long double basic_type_get_long_double ( basic_type const bt ) ;


/*! 
 * Encode a pointer value as a \c basic_type.
 *
 * \param pointer the pointer to encode
 * \return basic_type encoding the pointer
 */
extern basic_type basic_type_pointer ( void * const ) ;


/*! 
 * Recover the integer encoded in a basic_type.
 *
 * \param bt basic_type representing a pointer
 * \pre bt must be of .type t_pointer (assert-ed)
 * \return the encoded pointer
 */
extern void * basic_type_get_pointer ( basic_type const bt ) ;


/*! 
 * Encode a boolean value as a \c basic_type.
 *
 * \param boolean the boolean to encode
 * \return basic_type encoding the boolean
 */
extern basic_type basic_type_boolean ( bool boolean ) ;


/*! 
 * Recover the boolean encoded in a basic_type.
 *
 * \param bt basic_type representing a boolean
 * \pre bt must be of .type t_true ou t_false (assert-ed)
 * \return the encoded integer
 */
extern bool basic_type_get_boolean ( basic_type const bt ) ;


# endif
