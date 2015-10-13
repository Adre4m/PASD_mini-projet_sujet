# ifndef __MACRO_VALUE_H
# define __MACRO_VALUE_H

# include "value.h"

/*!
 * \file
 * \brief Macros for function declarations for \c value:
 *
 * \li <tt>value_ ## op_name ## \_create</tt>: to create an <tt>value_ ## op_name</tt>
 * \li <tt>value_is_ ## op_name</tt>: to test whether a chunk is an <tt>value_ ## op_name</tt>
 */
# define VALUE_DECLARE( type_name , type_C )				\
   extern chunk value_ ## type_name ## _create ( type_C const val ) ;	\
   extern bool value_is_ ## type_name ( chunk const ) ;


# endif

