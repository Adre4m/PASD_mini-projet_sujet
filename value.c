# include <assert.h>

# include "value.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION


bool chunk_is_value ( chunk const ch ) {
  assert ( NULL != ch ) ;
  // Do not use get_boolean since false should be returned for error
  return t_true == chunk_answer_message ( ch , MESSAGE_VALUE_IS_VALUE ).type;
}


basic_type chunk_is_value_true ( chunk const ch ,
				 va_list va ) {
  return basic_type_true ;
}


basic_type value_get_value ( chunk const ch ) {
  assert ( chunk_is_value ( ch ) ) ;
  return chunk_answer_message ( ch , MESSAGE_VALUE_GET_VALUE ) ;
}

