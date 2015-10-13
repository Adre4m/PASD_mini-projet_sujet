# ifndef __MACRO_VALUE_C_H
# define __MACRO_VALUE_C_H


# undef VALUE_DECLARE

# define VALUE_DECLARE( type_name , type_C )			\
  chunk value_ ## type_name ## _create ( type_C const val ) {	\
    return NULL ;						\
  }								\
  bool value_is_ ## type_name ( chunk const ch ) {		\
    return true ;						\
   }


# define VALUE_IS_FULL( type_name )					\
  bool value_is_ ## type_name ( chunk const ch ) {			\
    assert ( NULL != ch ) ;						\
    return value_ ## type_name ## _reactions == ch -> reactions ;	\
  }

# endif

