# include <assert.h>

# include "operator_creator_list.h"

# include "operator_nop.h"
# include "operator_pop.h"
# include "operator_print.h"
# include "operator_copy.h"
# include "operator_if.h"
# include "operator_if_else.h"
# include "operator_while.h"
# include "operator_def.h"
# include "operator_print_stack.h"
# include "operator_print_dictionary.h"
# include "operator_stop_trace.h"
# include "operator_start_trace.h"


# define OPERATOR_CREATE( op_name , op_keyword )		\
  { .keyword = # op_keyword ,					\
    .create_operator = operator_## op_name ##_create } ,


operator_creator operator_creator_list [] = {
  OPERATOR_CREATE ( nop , nop )
  OPERATOR_CREATE ( pop , pop )
  OPERATOR_CREATE ( print , print )
  OPERATOR_CREATE ( copy , copy )
  OPERATOR_CREATE ( start_trace , start_trace )
  OPERATOR_CREATE ( stop_trace , stop_trace )
  OPERATOR_CREATE ( print_stack , print_stack )
  OPERATOR_CREATE ( if , if )
  OPERATOR_CREATE ( if_else , if_else )
  OPERATOR_CREATE ( while , while )
  OPERATOR_CREATE ( def , def )
  OPERATOR_CREATE ( print_dictionary , print_dictionary )
  { .keyword = NULL , .create_operator = NULL } 
} ;
