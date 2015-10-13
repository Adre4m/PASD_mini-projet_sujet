# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <assert.h>

# include "interpreter.h"

# undef NDEBUG   // FORCE ASSERT ACTIVATION



/*!
 * \file
 * \brief THE MAIN FILE!
 *
 * Arguments:
 * \li \c -h help message (and exit)
 * \li \c -t to trace (can be turned off by operator \c stop_trace)
 * \li \c file.pf file to interprete (otherwise it is stdin)
 *
 * \author Jérôme DURAND-LOSE
 * \year 2015
 */


/*!
 * print help message and exit.
 */
static void help_message ( char const * const prog_name ) {
  puts ( "USAGE:" ) ;
  printf ( " %s -h\n\tDisplay this message and exit\n" , prog_name ) ;
  printf ( " %s [OPTIONS] [FILE]\n\tRun the pf interpreter on [FILE] (standard input if void)\n" , prog_name ) ;
  puts ( "OPTIONS:" ) ;
  puts ( " -t to trace the execution" ) ;
  exit ( 0 ) ;
}


/*!
 * THE MAIN FUNCTION
 */
int main ( int const argc ,
	   char const * const argv [] ) {
  help_message ( argv [ 0 ] ) ;
  return 0 ; 	      
}
