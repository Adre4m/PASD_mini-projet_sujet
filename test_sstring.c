# include <stdio.h>
# include <string.h>
# include <assert.h>


# include "sstring.h"

# undef NDEBUG   // FORCE ASSERT ACTIVATION


/*!
 * \file
 * \brief Basic tests for \c sstring.
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
 * Print an \c sstring surrounded by \c '"' followed by a \c "\n"
 *
 * \param ss \c sstring to print
 */
static void test_sstring_println ( sstring ss ) {
  assert ( NULL != ss ) ;
  putc ( '\"', stdout ) ;
  sstring_print ( ss , stdout ) ;
  fputs ( "\"\n" , stdout ) ;
}


/*!
 * Print a C-string and an \c sstring surrounded by \c '"' followed by a \c "\n"
 *
 * \param st C-string to print
 * \param ss \c sstring to print
 */
static void test_sstring_println_st_ss ( char const * const st ,
					 sstring ss ) {
  assert ( NULL != st ) ;
  assert ( NULL != ss ) ;
  puts ( "---------------" ) ;
  fprintf ( stdout , "\"%s\"\n"  , st ) ;
  test_sstring_println ( ss );
}


/*!
 * Test comparison on \c sstring.
 * It should produce the same output as \c strcmp.
 * Output is generated only in case of error.
 * All \c sstring are destroyed in the end.
 *
 * \param st1 1st C-strings to encode in \c sstring and compare
 * \param st2 2nd C-strings to encode in \c sstring and compare
 */
static void test_sstring_compare (  char const * const st1 ,
				    char const * const st2
				    ) {
  assert ( NULL != st1 ) ;
  assert ( NULL != st2 ) ;

  sstring ss1 = sstring_create_string ( st1 ) ;
  assert ( NULL != ss1 ) ;
  sstring ss2 = sstring_create_string ( st2 ) ;
  assert ( NULL != ss2 ) ;
  int cmp = strcmp ( st1, st2 ) ;
  cmp = ( 0 < cmp )
    ? 1
    : ( (  cmp < 0 )
	? -1
	: 0 ) ;
  int ss_cmp = sstring_compare ( ss1 , ss2 ) ;
  if ( cmp != ss_cmp ) {
    fprintf ( stdout , "ERROR: \"%s\" <=> \"%s\" = %d should be %d\n" ,
	      st1 ,
	      st2 ,
	      ss_cmp ,
	      cmp ) ;
  }
  sstring_destroy ( ss1 ) ;
  sstring_destroy ( ss2 ) ;
}


/*!
 * Launch different tests on \c sstring primitives:
 * \li \c sstring_create_string
 * \li \c sstring_concatenate
 * \li \c sstring_create_empty
 * \li \c sstring_destroy
 * \li launch various \link\c test_sstring_compare() \enlink.
 *
 * All \c sstring are destroyed in the end.
 *
 * \param st1 1st C-strings encode in \c sstring 
 * \param st2 2nd C-strings encode in \c sstring
 */
static void test_sstring ( char const * const st1 ,
			   char const * const st2
			   ) {
  assert ( NULL != st1 ) ;
  assert ( NULL != st2 ) ;

  sstring ss1 = sstring_create_string ( st1 ) ;
  assert ( NULL != ss1 ) ;
  test_sstring_println_st_ss ( st1, ss1 ) ;
  sstring ss2 = sstring_create_string ( st2 ) ;
  assert ( NULL != ss2 ) ;
  test_sstring_println_st_ss ( st2, ss2 ) ;

  test_sstring_compare ( st1 , st2 ) ;
  test_sstring_compare ( st2 , st1 ) ;
  test_sstring_compare ( st1 , st1 ) ;

  // Concatenate
  sstring_concatenate ( ss1 , ss2 ) ;
  assert ( NULL != ss1 ) ;
  fprintf ( stdout , "ss1.ss2 = " ) ;
  test_sstring_println ( ss1 ) ;

  sstring_concatenate ( ss2 , ss1 ) ;
  assert ( NULL != ss2 ) ;
  fprintf ( stdout , "ss2.ss1 = " ) ;
  test_sstring_println ( ss2 ) ;
  
  sstring ss3 = sstring_create_empty () ;
  assert ( NULL != ss3 ) ;
  
  sstring_concatenate ( ss2 , ss3 ) ;
  assert ( NULL != ss2 ) ;
  fprintf ( stdout , "ss2.ss3 = " ) ;
  test_sstring_println ( ss2 ) ;

  sstring_concatenate ( ss3 , ss2 ) ;
  assert ( NULL != ss3 ) ;
  fprintf ( stdout , "ss3.ss2 = " ) ;
  test_sstring_println ( ss3 ) ;
   
  sstring_destroy ( ss1 ) ;
  sstring_destroy ( ss2 ) ;
  sstring_destroy ( ss3 ) ;
}


/*!
 * Launch \link\c test_sstring_test() \enlink on various cases including empty C-string.
 */
int main ( void ) {

  test_sstring ( "roudoudou" , "unfzer_5\tdf" ) ;
  test_sstring ( "roudoudou" , "" ) ;
  test_sstring ( "" , "unfzer_5\tdf" ) ;
  test_sstring ( "" , "" ) ;

  test_sstring ( "rou\ndoudou" , "unfzer\n_5\tdf" ) ;
  
  return 0 ;
}
