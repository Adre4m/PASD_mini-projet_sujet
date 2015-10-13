# include <stdio.h>
# include <assert.h>

# include "chunk.h"

# include "value_boolean.h"
# include "value_sstring.h"
# include "value_double.h"
# include "value_int.h"
# include "value_protected_label.h"

# include "dictionary.h"

# undef NDEBUG   // FORCE ASSERT ACTIVATION


/*!
 * \file
 * \brief Basic tests for \c dictionary.
 * 
 * This should also be used to test for memory leak.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*!
 * Do various set and get with the provided arguments.
 * At the end, the entry is added.
 */
static void test_dico_key_val ( dictionary const dic ,
				char const * const key_st ,
				chunk const val ) {
  sstring key = sstring_create_string ( key_st ) ;
  dictionary_set ( dic , key , val ) ;
  fprintf ( stdout , "Accessing with key: [%s] \"" , key_st ) ;
  sstring_print ( key , stdout ) ;
  chunk val_get = dictionary_get_copy ( dic , key ) ;
  fprintf ( stdout , "\"\n          expected: \"" ) ;
  chunk_print ( val , stdout ) ;
  chunk_destroy ( val ) ;
  sstring_destroy ( key ) ;
  fprintf ( stdout , "\"\n               got: \"" ) ;
  chunk_print ( val_get , stdout ) ;
  chunk_destroy ( val_get ) ;
  fprintf ( stdout , "\"\n" ) ;
}


/*!
 * Do some test on different keys, print and then redefine and then print and finally destroy the \c dictionary.
 */
int main ( void ) {
  dictionary dic = dictionary_create () ;

  // Add various entries
  test_dico_key_val ( dic , "etsd" , value_boolean_create ( true ) ) ;
  test_dico_key_val ( dic , "Zeun" , value_double_create ( 45 ) ) ;
  test_dico_key_val ( dic , "Bun" , value_double_create ( 55 ) ) ;
  test_dico_key_val ( dic , "eun" , value_double_create ( 5 ) ) ;
  test_dico_key_val ( dic , "S4567" , value_int_create ( 85 ) ) ;
  test_dico_key_val ( dic , "##:!!##" , value_protected_label_create ( sstring_create_string ( "Etiquette"  ) ) ) ;

  dictionary_print ( dic , stdout ) ;

  // re-definitions

  test_dico_key_val ( dic , "eun" , value_boolean_create ( false ) ) ;
  test_dico_key_val ( dic , "S4567" , value_boolean_create ( false ) ) ;
  test_dico_key_val ( dic , "etsd" , value_boolean_create ( false ) ) ;

  dictionary_print ( dic , stdout ) ;
  
  dictionary_destroy ( dic ) ;
  return 0 ;
}

