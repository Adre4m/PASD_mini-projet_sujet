# ifndef __INTERPRETER_H
# define __INTERPRETER_H

# include <stdio.h>

# include "linked_list_chunk.h"
# include "dictionary.h"


/*! 
 * \file
 * \brief Interpretation engine.
 */


/*! 
 * Interpretation context:
 * \param program_input_stream where \c chunk should be read from
 * \param stack current stack
 * \param dic \c dictionary used to store ( label , value )
 * \param do_trace if true then the execution should be traces (otherwise no)
 */
typedef struct interpretation_context_struct {
  FILE * program_input_stream ;
  linked_list_chunk stack ;
  dictionary dic ;
  bool do_trace ;
} interpretation_context_struct ,
  * interpretation_context ;


/*! 
 * Interpret a single chunk in a context.
 * \li if it is a value, it should be stacked;
 * \li if it is an operator, it should be evaluated in this context and destroyed after.
 *
 * If a \c basic_type_error is returned by the evaluation of an \c operator, then the first value on the stack should be a \c value_error.
 * This value is printed (and destroyed) and then the stack id printed on \c stderr as follows:
 * \verbatim
 ### ERROR ### operator pop ###  --error-- # 6
 vvvvvvvv stack  top  vvvvvvvvvv
 ^^^^^^^^ stack bottom ^^^^^^^^^
 \endverbatim
 * \param ch \c chunk to interpret
 * \param ic contest to interpret it
 * \pre no pointer is NULL
 */
extern void interprete_chunk ( chunk ch ,
			       interpretation_context ic ) ;


/*! 
 * Interpret a list chunk in a context.
 * They are all interpreted in sequence.
 *
 * The linked_list_chunk is emptied but not destroyed.
 *
 * \param llc \c chunk list to interpret
 * \param ic contest to interpret it
 * \pre no pointer is NULL
 */
extern void interprete_chunk_list ( linked_list_chunk llc ,
				    interpretation_context ic ) ;


/*! 
 * Interpret a program from a stream.
 * As long as the stream is not empty, \c chunk are read and interpreted.
 *
 * The interpretation starts with an empty stack and an empty dictionary.
 *
 * \param input steam to read the program from
 * \param do_trace if true then the execution should be traces (otherwise no)
 * \pre no pointer is NULL
 */
extern void interprete ( FILE * input ,
			 bool do_trace ) ;



# endif
