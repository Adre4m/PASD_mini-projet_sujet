# include <stdlib.h>
# include <stdio.h>
# include <assert.h>

# include "value_error.h"

# include "macro_value_c.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION


/*! 
 * Defined for I/O: beginning for the print.
 * The number should come right after.
 */
static char const * const value_error_string = "--error-- #" ;


/*!
 * Just record the error nbr as enum \link error_code \endlink.
 */
typedef struct {
  unsigned int copies_count ;
  error_code error ;
} value_error_state_struct ,
  * value_error_state ;



static basic_type value_error_get_value ( chunk const ch ,
					  va_list va ) {
  return basic_type_long_long_int ( ( ( value_error_state ) ch ) -> error ) ; 
}


static basic_type value_error_print ( chunk const ch ,
				      va_list va ) {
  FILE * f = va_arg ( va , FILE * ) ;
  fprintf ( f
	    , "%s %u"
	    , value_error_string
	    , ( ( value_error_state ) ( ch -> state ) ) -> error ) ;
  return basic_type_void ;
}


static basic_type value_error_destroy ( chunk const ch ,
					va_list va ) {
  if ( 1 == ( ( value_error_state  ) ( ch -> state ) ) -> copies_count -- ) {
    free ( ch -> state ) ;  
    ch -> state = NULL ;
    ch -> reactions = NULL ;
    free ( ch ) ;
  }
  return basic_type_void ;
}


static basic_type value_error_copy ( chunk const ch ,
				     va_list va ) {
  // not commented since it has to be explained
  ( ( value_error_state ) ( ch -> state ) ) -> copies_count ++ ;
  return basic_type_pointer( ch ) ; 
}


static const message_action value_error_reactions [] = {
  MESSAGE_ACTION__BASIC_VALUE( error ) ,
  { NULL, NULL }
} ;


chunk value_error_create ( error_code const error ) {
  //  Allocation
  chunk ch = ( chunk ) malloc ( sizeof ( chunk_struct ) ) ; 
  assert ( NULL != ch ) ;
  ch -> state = malloc ( sizeof ( value_error_state ) ) ; 
  assert ( NULL != ch -> state ) ;
  //  Initialisation
  ( ( value_error_state ) ( ch -> state ) ) -> copies_count = 1 ;
  ( ( value_error_state ) ( ch -> state ) ) -> error = error ;
  ch -> reactions = value_error_reactions ;
  return ch ;
}


VALUE_IS_FULL( error )

