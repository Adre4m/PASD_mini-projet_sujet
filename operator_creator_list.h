# ifndef __OPERATOR_CREATOR_LIST_H
# define __OPERATOR_CREATOR_LIST_H

# include <stdarg.h>
# include <stdio.h>

# include "chunk.h"


/*!
 * \file
 * \brief Comprehensive listing of all labels that are reserved word together with functions to create the corresponding \c operator's.
 *
 * Only \c operator's written as a sequence of letters are concerned (i.e. neither + nor &&… are concerned).
 *
 * This is used to:
 * \li distinguish keyword from legal label, and
 * \li to identify and generate the right operator on reading.
 * 
 * This module has only data and no function.
 * 
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*!
 * Record together the :
 * \param reserved keyword corresponding to an operator
 * \param create_operator pointer to the function to generate the corresponding chunk
 */
typedef struct operator_creator {
  char const * keyword ;
  chunk ( * const create_operator ) () ;
} operator_creator ;


/*!
 * List all such keywords / creation functions in the language.
 */
extern operator_creator operator_creator_list [] ;


# endif
