# include <stdlib.h>   // malloc + free
# include <stdbool.h>
# include <assert.h>

# include "linked_list_chunk.h"


# undef NDEBUG   // FORCE ASSERT ACTIVATION




/*!
 * \file
 * \brief Structure used to store list of \link chunk\endlink 's.
 *
 * Please note that \c linked_list_chunk does not make any copy of \c chunk's.
 *
 * The list is bidirectional and can be accessed from both end.
 *
 * The structure is 2-level:
 * \li \c link's are used to provide the bidirectional links (with pointers) and points to \c chunk
 * \li the \c main structure has pointers to first and last \c link's.
 *
 * The empty list has the pointers of its \c main structure at \c NULL.
 *
 * \note Cela ressemble au TDM2 (sans être circulaire).
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */

 
 typedef struct link_struct {
   chunk val;
   link* next;
   link* prev;
} link;
 
 
 static link* link_create (chunk _val) {
	link* l = (link*) malloc (sizeof (link));
	l->val = _val;
	l->next = l;
	l->prev = l;
	return l;
 }
 
 
 static void link_destroy (link** l) {
	if ((*l)->next != NULL) {
		link_destroy((*l)->next);
	}
	free(*l);
 }
 
 static void link_print (FILE *f, link *l) {
	link* it = l->next;
	while (it != NULL) {
		chunk_print (l->val, f); //aucune idee de comment l'utiliser a voir
		fprintf(f, "\n");
		it = it->next;
	}
 }
 
 static void link_add_front (link *l, chunk c) {
	link* res = (link*) malloc (siezof (link));
	res->val = c;
	res->prev = NULL;
	res->next = l;
	l->prev = res;
 } 
 
 static void link_add_back (link *l, chunk c) {
	link* res = (link*) malloc (sizeof (link));
	res->val = c;
	res->prev = l;
	res->next = NULL;
	l->next = res;
}

static chunk link_pop_front (link *l) {
	chunk c = l->val;
	l = l->next;
	l->prev = NULL;
	return c;
}
 
/*! 
 * \c linked_list_chunk is a pointer to a hidden structure (\c main structure). 
*/
struct linked_list_chunk_struct {
	unsigned int size;
	link* first;
	link* last;
};

/*!
 * Generate an empty \c linked_list_chunk
 *
 * \return an empty \c linked_list_chunk
 */
linked_list_chunk linked_list_chunk_create ( void )  { 
	linked_list_chunk* llc = (linked_list_chunk*) malloc (sizeof (linked_list_chunk));
	llc->first = NULL;
	llc->last = NULL;
	llc->size = 0;
	return llc;
}

/*!
 * Destroy the whole structure and the stored values.
 *
 * \param llc \c linked_list_chunk to destroy
 * \pre \c llc is valid (assert-ed)
 */
void linked_list_chunk_destroy ( linked_list_chunk llc )  {
	link_destroy (llc->first);
	free(llc);
}


/*!
 * To know whether a \c linked_list_chunk is empty.
 *
 * \param llc \c linked_list_chunk to test
 * \pre \c llc is valid (assert-ed)
 * \return true iff \c llc is empty
 */
bool linked_list_chunk_is_empty ( linked_list_chunk llc)  { 
	return (llc->first == NULL && llc->last == NULL); 
}


/*!
 * To print a \c linked_list_chunk.
 * Each chink is printed on a separate line with \c chunk_print.
 *
 * \param llc \c linked_list_chunk to print
 * \param f stream to print to
 * \pre \c llc is valid (assert-ed)
 * \pre \c f is not \c NULL (assert-ed)
 */
void linked_list_chunk_print ( linked_list_chunk llc , FILE * f )  {
	link_print (f, llc->first);
}

/*!
 * Add a chunk at the beginning of the \c linked_list_chunk.
 *
 * \param llc \c linked_list_chunk to add to
 * \param ch \c chunk to add
 * \pre \c llc is valid (assert-ed)
 * \pre \c ch is not \c NULL (assert-ed)
 */
void linked_list_chunk_add_front ( linked_list_chunk llc ,chunk ch )  {
	if (list_chunk_is_empty) {
		llc->first = link_create(ch);
		llc->last = llc->first;
	} else {	
		link_add_front(llc->first, ch);
		llc->first = llc->first->prev;
	}
	llc->size ++;
}

/*!
 * Add a \c chunk at the end of the \c linked_list_chunk.
 *
 * \param llc \c linked_list_chunk to add to
 * \param ch \c chunk to add
 * \pre \c llc is valid (assert-ed)
 * \pre \c ch is not \c NULL (assert-ed)
 */
void linked_list_chunk_add_back ( linked_list_chunk llc , chunk ch )  {
if (list_chunk_is_empty) {
		llc->first = link_create(ch);
		llc->last = llc->first;
	} else {	
		link_add_back(llc->last, ch);
		llc->last = llc->last->next;
	}
	llc->size ++;
}

/*!
 * Return the \c chunk at the beginning of the \c linked_list_chunk.
 * The \c chunk is removed from the \c linked_list_chunk.
 *
 * \param llc \c linked_list_chunk to pop from
 * \return The removed \c chunk at the beginning or \c NULL if linked_list_chunk empty
 */
chunk linked_list_chunk_pop_front ( linked_list_chunk llc )  { 
	llc->first = llc->first->next;
	llc->size --;
	return link_pop_front (llc->first->prev);
 }


/*!
 * Add a \b copy of the \c k first \c chunk at the beginning of the \c linked_list_chunk to it-self.
 * If there is less than \c k \c chunk then no copy is made.
 *
 * For \c k, the following \c linked_list_chunk
 * \verbatim [front]                                     ch0 ch_1 ch_2 ...  ch_k-2 ch_k-1   ch_k ch_k+1 ch_k+2 \endverbatim 
 * is transformed into
 * \verbatim [front]  ch0 ch_1 ch_2 ...  ch_k-2 ch_k-1   ch0 ch_1 ch_2 ...  ch_k-2 ch_k-1   ch_k ch_k+1 ch_k+2 \endverbatim 
 *
 * \param llc \c linked_list_chunk to add to
 * \param k size of the prefix to copy in front
 * \pre \c llc is valid (assert-ed)
 * \return false if there where less than k element. In such a case, no copy is made.
 */
bool linked_list_chunk_add_self_copy_front ( linked_list_chunk llc , unsigned int k )  { 
	if (llc-> size < k) 
		return false;
	else {
		link *l =llc->first;
		for (unsigned int i = 1;i < k; i++) {
			l=l->next; // aller a l'element k
		} 
		for (unsigned int i = 0; i < k; i++) {
			linked_list_chunk_add_front (llc, l->val);
			l = l->prev;
		} 
	}
	return true; 
}


/*!
 * Generate a copy of the \c linked_list_chunk.
 *
 * \param llc \c linked_list_chunk to copy
 * \pre \c llc is valid (assert-ed)
 */
 linked_list_chunk linked_list_chunk_copy ( linked_list_chunk llc )  { 
	linked_list_chunk llc_bis = linked_list_chunk_create();
	link *l=llc->first;
	for (unsigned int i = 0; i < taille; i++) {
		linked_list_chunk_add_back (llc_bis; l->val);
		l= l->next;
	} 
	return llc_bis;
}


