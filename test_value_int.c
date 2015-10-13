# include <stdio.h>
# include <assert.h>

# include "chunk.h"

# include "value_error.h"
# include "value_int.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION


/*!
 * \file
 * \brief Basic tests for \c value_int (and \c value_error).
 * 
 * Test \c copy, \c print and \c destroy on \c value_int and \c value_error.
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
 * Launch \link test_chunk()\endlink on various \c value_int and \c value_error.
 */
int main ( void ) {
  test_chunk ( value_error_create ( VALUE_ERROR_IO_SYNTAX ) , "error # 0" ) ;
  test_chunk ( value_int_create ( 4 ) ,"int 4" ) ;
  test_chunk ( value_int_create ( 54 ) ,"int 54" ) ;

  return 0 ;
}

