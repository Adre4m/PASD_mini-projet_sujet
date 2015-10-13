# include <stdio.h>
# include <assert.h>


# include "value.h"
# include "operator.h"

# include "interpreter.h"



# undef NDEBUG   // FORCE ASSERT ACTIVATION




void interprete_chunk ( chunk ch ,
			interpretation_context ic )  {}

void interprete_chunk_list ( linked_list_chunk ch ,
			     interpretation_context ic )  {}

void interprete ( FILE * f ,
		  bool do_trace )  {}


