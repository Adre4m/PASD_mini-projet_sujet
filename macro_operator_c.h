# ifndef __MACRO_OPERATOR_C_H
# define __MACRO_OPERATOR_C_H


# include "value_error.h"

# undef OPERATOR_DECLARE

# define OPERATOR_DECLARE( type_name )				\
  chunk operator_ ## type_name ## _create () {			\
    return NULL ;						\
  }								\
  bool operator_is_ ## type_name ( chunk const ch ) {		\
    return true ;						\
  }


/*
 * Except for operator label, all are identifcal.
 * This is simplified into making only one static instance of the operator for each kind.
 * Creation and destruction are thus handled regularly as any global variable.
 */

# define OPERATOR_BASIC_FULL( op_name , op )				\
									\
  									\
  static basic_type operator_ ## op_name ## _print ( chunk const ch ,	\
						     va_list va ) {	\
    return basic_type_erreur ;						\
  }									\
									\
  static basic_type operator_ ## op_name ## _destroy ( chunk const ch ,	\
						       va_list va ) {	\
    return basic_type_erreur ;						\
  }									\
									\
  static basic_type operator_ ## op_name ## _copy ( chunk const ch ,	\
						    va_list va ) {	\
    return basic_type_void ;						\
  }									\
									\
  static const message_action operator_ ## op_name ## _reactions [] = {	\
    MESSAGE_ACTION__BASIC_OPERATOR( op_name ) ,				\
    { NULL, NULL }							\
  } ;									\
									\
  static chunk_struct operator_ ## op_name ## _instance = {		\
    .state = NULL ,							\
    .reactions = operator_ ## op_name ## _reactions  } ;		\
  									\
  chunk operator_ ## op_name ## _create () {				\
    return NULL ;                                                       \
  }									\
									\
  bool operator_is_ ## op_name ( chunk const ch ) {			\
    return true ;                               			\
  }



# define OPERATOR_NUMBER( op_name , op )				\
  static basic_type operator_ ## op_name ## _operate ( chunk const ch ,	\
						       va_list va ) {	\
    return basic_type_error ;						\
  }

# define OPERATOR_BOOLEAN( op_name , op )				\
  static basic_type operator_ ## op_name ## _operate ( chunk const ch ,	\
						       va_list va ) {	\
    return basic_type_error ;						\
  }									\
									\
  OPERATOR_BASIC_FULL( op_name , op )



# define OPERATOR_COMPARATOR( op_name , op )				\
  static basic_type operator_ ## op_name ## _operate ( chunk const ch ,	\
						       va_list va ) {	\
    return basic_type_error ;						\
  }


# define OPERATOR_EQUALITY( op_name , op )				\
  static basic_type operator_ ## op_name ## _operate ( chunk const ch ,	\
						       va_list va ) {	\
    return basic_type_error ;					        \
  }									\
									\
  OPERATOR_BASIC_FULL( op_name , op )



# endif
