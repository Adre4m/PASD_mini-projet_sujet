# include <assert.h>

# include "operator.h"

# undef NDEBUG   // FORCE ASSERT ACTIVATION


bool chunk_is_operator ( chunk const ch ) {
  assert ( NULL != ch ) ;
  return basic_type_is_true ( chunk_answer_message ( ch , MESSAGE_OPERATOR_IS_OPERATOR ) ) ;
}


basic_type chunk_is_operator_true ( chunk const ch ,
				    va_list va ) {
  // no assert because it can only be called by chunk_answer_message
  return basic_type_true ;
}


basic_type operator_evaluate ( chunk const ch ,
			       interpretation_context ic ) {
  assert ( chunk_is_operator ( ch ) ) ;
  assert ( NULL != ic ) ;
  return chunk_answer_message ( ch , MESSAGE_OPERATOR_EVALUATE , ic ) ;
}


