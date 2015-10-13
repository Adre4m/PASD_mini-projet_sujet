# include <stdio.h>
# include <assert.h>

# include "chunk.h"

# include "value_error.h"

# include "linked_list_chunk.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION

/*!
 * \file
 * \brief Basic tests and examples of use of \c linked_list_chunk.
 * All functions are tested on various values.
 *
 * This should also be used to test for memory leak.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*!
 * Do various modifications of the  \c linked_list_chunk with the provided \c chunk.
 * On return, the \c chunk is added on both extremities.
 */
static void test_llc_ch ( linked_list_chunk const llc ,
			  chunk const ch ) {
  
  fprintf ( stdout , "*** adding to back : \"" ) ;
  chunk_print ( ch , stdout ) ;
  fprintf ( stdout , "\" :\n" ) ;
  linked_list_chunk_add_back ( llc , ch ) ;
  linked_list_chunk_print ( llc , stdout ) ;
  
  fprintf ( stdout , "*** adding to front : \"" ) ;
  chunk_print (  ch , stdout ) ;
  fprintf ( stdout , "\" :\n" ) ;
  linked_list_chunk_add_front ( llc , chunk_copy ( ch ) ) ;
  linked_list_chunk_print ( llc , stdout ) ;

  assert ( ! linked_list_chunk_is_empty ( llc ) ) ;
}


/*!
 * Build in initial \c linked_list_chunk and then do various list modifications.
 * Everything is destroyed in the end.
 */
int main ( void ) {
  chunk ch ;
  linked_list_chunk llc = linked_list_chunk_create () ;
  assert ( linked_list_chunk_is_empty ( llc ) ) ;
  
  test_llc_ch ( llc , value_error_create ( 0 ) ) ;
  test_llc_ch ( llc , value_error_create ( 1 ) ) ;
  test_llc_ch ( llc , value_error_create ( 2 ) ) ;
  test_llc_ch ( llc , value_error_create ( 3 ) ) ;
  test_llc_ch ( llc , value_error_create ( 4 ) ) ;
  test_llc_ch ( llc , value_error_create ( 5 ) ) ;

  linked_list_chunk llc_2 = linked_list_chunk_copy ( llc ) ;
  linked_list_chunk_destroy ( llc );
  puts ( " copy" ) ;
  linked_list_chunk_print ( llc_2 , stdout ) ;
  linked_list_chunk llc_3 = linked_list_chunk_copy ( llc_2 ) ;

  while ( ! linked_list_chunk_is_empty ( llc_2 ) ) {
    chunk ch = linked_list_chunk_pop_front ( llc_2 ) ;
    fprintf ( stdout , "*** removing from front : \"" ) ;
    chunk_print ( ch , stdout ) ;
    fprintf ( stdout , "\" :\n" ) ;
    linked_list_chunk_print ( llc_2 , stdout ) ;
    chunk_destroy ( ch ) ;
  }
  linked_list_chunk_destroy ( llc_2 );
  fprintf ( stdout , "*** Adding a copy of 3 first elements: \n" ) ;
  linked_list_chunk_add_self_copy_front ( llc_3 , 3 ) ;
  linked_list_chunk_print ( llc_3 , stdout ) ;

  linked_list_chunk_destroy ( llc_3 );

  return 0 ;
}
