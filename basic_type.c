# include <assert.h>

# include "basic_type.h"

# undef NDEBUG   // FORCE ASSERT ACTIVATION



/* 
 * CONSTANTES
 */


basic_type const basic_type_void = { .type = t_void } ;

basic_type const basic_type_error = { .type = t_error } ;

basic_type const basic_type_false = { .type = t_false } ;
basic_type const basic_type_true = { .type = t_true } ;



/* 
 * Simple tests
 */


bool basic_type_is_error ( basic_type bt ) {
  return t_error == bt . type ;
}


bool basic_type_is_true ( basic_type bt ) {
  return t_true == bt . type ;
}

/*
 * for INTEGERS
 */

basic_type basic_type_long_long_int ( long long int const long_long_int ) {
  basic_type rep = { .type = t_long_long_int ,
		     .value = { .val_long_long_int = long_long_int } } ;
  return rep ;
}


long long int basic_type_get_long_long_int ( basic_type const bt ) {
  assert ( t_long_long_int == bt . type ) ;
  return bt . value . val_long_long_int ;
}


/*
 * for FLOATS
 */

basic_type basic_type_long_double ( long double const long_double ) {
  basic_type rep = { .type = t_long_double ,
		     .value = { .val_long_double = long_double } } ;
  return rep ;
}


long double basic_type_get_long_double ( basic_type const bt ) {
  assert ( t_long_double == bt . type ) ;
  return bt . value.val_long_double ;
}


/*
 * for POINTERS
 */

basic_type basic_type_pointer ( void * const pointer ) {
  basic_type rep = { .type = t_pointer ,
		     .value = { .val_pointer = pointer } } ;
  return rep ;
}


void * basic_type_get_pointer ( basic_type const bt ) {
  assert ( t_pointer == bt . type ) ;
  return bt . value . val_pointer ;
}


/*
 * for BOOLEANS
 */

basic_type basic_type_boolean ( bool boolean ) {
  return boolean ? basic_type_true : basic_type_false ;
}


bool basic_type_get_boolean ( basic_type const bt ) {
  if ( t_true == bt . type ) {
    return true ;
  }
  assert ( t_false == bt . type ) ;
  return false ;
}
