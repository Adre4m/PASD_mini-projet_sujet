# include <stdio.h>
# include <assert.h>

# include "chunk.h"

# include "value_error.h"
# include "value_boolean.h"
# include "value_sstring.h"
# include "value_double.h"
# include "value_int.h"
# include "value_protected_label.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION

/*!
 * \file
 * \brief Basic tests for\c value's.
 * 
 * Test \c copy, \c print and \c destroy on:
 * \li \c value_block
 * \li \c value_boolean
 * \li \c value_double
 * \li \c value_error
 * \li \c value_int
 * \li \c value_protected_label
 * \li \c value_sstring
 * 
 * \c value_block is not tested since it relies on \c linked_list_chunk. 
 * It is tested in \link test_linked_list_chunk.c\endlink.
 *
 * All \c value's (including \c value_block) are also tested with \c pf programs.
 *
 * This should also be used to test for memory leak.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*!
 * Used to make test on a specific chunk.
 * \param ch chunk to test
 * \param st C-string to print
 */
static void test_chunk ( chunk ch ,
			 char const * const st ) {
  assert ( NULL != ch ) ;
  assert ( NULL != st ) ;
  printf ( "== %s ==\n" , st ) ;
  basic_type bt = chunk_print ( ch , stdout ) ;
  assert ( t_void == bt.type ) ;
  fputc ( '\n' , stdout ) ;
  chunk ch2 = chunk_copy ( ch ) ;
  assert ( NULL != ch2 ) ;
  chunk_destroy ( ch ) ;
  chunk_print ( ch2 , stdout ) ;
  fputc ( '\n' , stdout ) ;
  chunk_destroy ( ch2 ) ;
}


/*!
 * Launch \link test_chunk()\endlink on the value types.
 */
int main ( void ) {
  test_chunk ( value_error_create ( VALUE_ERROR_IO_SYNTAX ) , "error # 0" ) ;
  test_chunk ( value_int_create ( 54 ) ,"int 54" ) ;
  test_chunk ( value_double_create ( 5.44 ) , "double 5.44" ) ;
  test_chunk ( value_boolean_create ( true ) , "true" ) ;
  test_chunk ( value_protected_label_create ( sstring_create_string ( "eundt_ets_4567" ) ) , "Protected label eundt_ets_4567" ) ;
  test_chunk ( value_sstring_create ( sstring_create_string ( "eundt ets 4567" ) ) , "sstring eundt ets 4567" ) ;

  test_chunk ( value_error_create ( VALUE_ERROR_IO_EOF ) , "error # 1" ) ;
  test_chunk ( value_int_create ( 45 ) ,"int 45" ) ;
  test_chunk ( value_double_create ( 9 ) , "double 9.0" ) ;
  test_chunk ( value_boolean_create ( false ) , "true" ) ;
  test_chunk ( value_protected_label_create ( sstring_create_string ( "ets_4567" ) ) , "Protected label ets_4567" ) ;
  test_chunk ( value_sstring_create ( sstring_create_string ( "ets 4567" ) ) , "sstring ets 4567" ) ;

  return 0 ;
}

