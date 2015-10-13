# ifndef __OPERATOR_MACRO_H
# define __OPERATOR_MACRO_H


/*!
 * \file
 * \brief Macros for function declarations for \c operator:
 *
 * \li <tt>operator_ ## op_name ## \_create</tt>: to create an <tt>operator_ ## op_name</tt>
 * \li <tt>operator_is_ ## op_name</tt>: to test whether a chunk is an <tt>operator_ ## op_name</tt>
 */
# define OPERATOR_DECLARE( op_name )				\
  extern chunk operator_ ## op_name ## _create () ;		\
  extern bool operator_is_ ## op_name ( chunk const ) ;


# endif
