# include <stdlib.h> // malloc + free
# include <assert.h>

# include "dictionary.h"

# undef NDEBUG   // FORCE ASSERT ACTIVATION





/*!
 * \file
 * \brief Provide a dictionary (associative table).
 * \li keys must be non-empty \c sstring's
 * \li values must be \c chunk's
 *
 * Keys and values are copied to get independent long term storage.
 * In the same spirit, queried values are \b copies. 
 * The <b>caller is in charge of destroying copies</b>; this is indicated by the \c _copy in the query function name.
 *
 * Values are stored in an ordered binary tree.
 * They are two data structures: one for the dictionary and one for nodes.
 *
 * \note Cela ressemble au TDM 3, même s'il y a des différences.
 *
 * assert is enforced.
 *
 * \author Jérôme DURAND-LOSE
 * \version 1
 * \date 2015
 * \copyright GNU Public License.
 */


/*! \c dictionary is a pointer to the hidden structure for dictionary. */

typedef struct node_struct node;

struct node_struct {
  sstring key;
  chunk val;
  node* left_son;
  node* right_son;
  node* father;
};

node* node_create(void) {
  node* nd = (node*) malloc(sizeof(node));
  nd->key = sstring_create_empty();
  nd->val = NULL;
  nd->left_son = NULL;
  nd->right_son = NULL;
  nd->father = NULL;
  return nd;
}

void node_destroy(node** nd) {
	if((*nd)->left_son != NULL) {
		(*nd)->left_son->father = NULL;
		node_destroy(&((*nd)->left_son));
		(*nd)->left_son = NULL;
	}
	if((*nd)->right_son != NULL) {
		(*nd)->right_son->father = NULL;
		node_destroy(&((*nd)->right_son));
		(*nd)->right_son = NULL;
	}
	if((*nd)->father != NULL) {
		if((*nd)->father->left_son == (*nd)) {
			(*nd)->father->left_son = NULL;
		} else {
			(*nd)->father->right_son = NULL;
		}
		node_destroy(&((*nd)->father));
		(*nd)->father = NULL;
	}
	sstring_destroy((*nd)->key);
	chunk_destroy((*nd)->val);
	(*nd)->father = NULL;
	(*nd)->right_son = NULL;
	(*nd)->left_son = NULL;
	free(*nd);
}

void node_print(node* nd, FILE* f) {
	if(nd->left_son != NULL)
		node_print(nd->left_son, f);
	if(nd->right_son != NULL)
		node_print(nd->right_son, f);
	chunk_print(nd->val, f);
	fprintf(f, "\n");
}

bool node_is_leaf(node* nd) {
	return (nd->right_son == NULL) && (nd->left_son == NULL);
}

int node_size(node* nd) {
	int size = 0;
	if(nd->left_son != NULL)
		size += node_size(nd->left_son);
	if(nd->right_son != NULL)
		size += node_size(nd->right_son);
	return size + 1;
}

chunk node_search(node* nd, sstring key) {
	int cmp = sstring_compare(key, nd->key);
	if(cmp == 0) {
		return nd->val;
	} else {
		if(1 <= cmp) {
			if(nd->right_son != NULL)
				return node_search(nd->right_son, key);
		} else {
			if(nd->left_son != NULL)
				return node_search(nd->left_son, key);
		}
		return NULL;
	}
}

void node_add_value(node* nd, sstring key, chunk value) {
	assert(!sstring_is_empty(key));
	if(sstring_is_empty(nd->key)) {
		int cmp = sstring_compare(nd->key, key);
		if(cmp != 0) {
			if (cmp <= -1) {
				if(nd->right_son == NULL) {
					nd->right_son = node_create();
					sstring_concatenate(nd->right_son->key, key);
					nd->right_son->val = chunk_copy(value);
				} else
					node_add_value(nd->right_son, key, value);
			} else {
				if(nd->left_son == NULL) {
					nd->left_son = node_create();
					sstring_concatenate(nd->left_son->key, key);
					nd->left_son->val = chunk_copy(value);
				} else
					node_add_value(nd->left_son, key, value);
			}
		}
	} else {
		sstring_concatenate(nd->key, key);
		nd->val = chunk_copy(value);
	}	
}

void node_del_value(node* nd, sstring key) {
	int cmp = sstring_compare(key, nd->key);
	if(1 <= cmp) {
		if(nd->right_son != NULL)
			node_del_value(nd->right_son, key);
	} else if (cmp <= -1) {
		if(nd->left_son != NULL)
			node_del_value(nd->left_son, key);
	} else {
		if(nd->right_son == NULL && nd->left_son == NULL) {
			if(nd->father != NULL) {
				if(nd->father->right_son == nd) {
					nd->father->right_son = NULL;
				} else {
					nd->father->left_son = NULL;
				}
			}
			sstring_destroy(nd->key);
			chunk_destroy(nd->val);
			nd->father = NULL;
			nd->right_son = NULL;
			nd->left_son = NULL;
			free(nd);
		} else {
			if(nd->right_son != NULL && nd->left_son != NULL) {
				node* inter = nd->right_son;
				while(inter->left_son != NULL) {
					inter = inter->left_son;
				}
				inter->father = nd->father;
				if(nd->father != NULL) {
					if(nd->father->right_son == nd) {
						nd->father->right_son = inter;
					} else {
						nd->father->left_son = inter;
					}
				}
				inter->left_son = nd->left_son;
				nd->left_son->father = inter;
				if(nd->right_son != inter) {
					nd->right_son->father = inter;
					inter->right_son = nd->right_son;
				}
				sstring_destroy(nd->key);
				chunk_destroy(nd->val);
				nd->father = NULL;
				nd->right_son = NULL;
				nd->left_son = NULL;
				free(nd);
			} else {
				node* inter;
				if(nd->left_son != NULL) {
					inter = nd->left_son;
				} else {
					inter = nd->right_son;
				}
				inter->father = nd->father;
				if(nd->father != NULL) {
					if(nd->father->left_son == nd) {
						nd->father->left_son = inter;
					} else {
						nd->father->right_son = inter;
					}
				}
				sstring_destroy(nd->key);
				chunk_destroy(nd->val);
				nd->father = NULL;
				nd->right_son = NULL;
				nd->left_son = NULL;
				free(nd);
			}
		}
	}
}

node* node_copy(node* nd) {
	node* res = (node*) malloc(sizeof(node));
	res->key = sstring_copy(nd->key);
	res->val = chunk_copy(nd->val);
	res->father = NULL;
	if(nd->right_son != NULL) {
		res->right_son = node_copy(nd->right_son);
		res->right_son->father = res;
	} else
		res->right_son = NULL;
	if(nd->left_son != NULL) {
		res->left_son = node_copy(nd->left_son);
		res->left_son->father = res;
	} else
		res->left_son = NULL;
	return res;
}

struct dictionary_struct {
  node* tree;
};

/*!
 * Generate an empty \c dictionary.
 *
 * \return an empty \c dictionary
 */
dictionary dictionary_create ( void )  {
  dictionary dic = (dictionary) malloc(sizeof(struct dictionary_struct));
  dic->tree = node_create();
  return dic;
}


/*!
 * Add an entry \c (key,val) into a \c dictionary.
 *
 * Copies of key and val are made.
 * The original values can be safely destroyed after the call.
 *
 * \param dic \c dictionary to modify
 * \param key insertion key
 * \param val inserted value
 * \pre no pointer is NULL (assert-ed)
 * \pre key is not an empty string  (assert-ed)
 */
void dictionary_set ( dictionary dic , sstring key , chunk val )  {
  assert(key != NULL && val != NULL);
  assert(!sstring_is_empty(key));
  node_add_value(dic->tree, key, val);
}


/*!
 * Retrieve a \b copied value from a \c dictionary according to a \c key.
 *
 * \param dic \c dictionary to query from
 * \param key key to search a value for
 * \pre no pointer is NULL (assert-ed)
 * \pre key is not empty
 * \return a \b copy of the associated \c chunk or NULL if undefined 
 */
chunk dictionary_get_copy ( dictionary dic , sstring key )  {
	return chunk_copy(node_search(dic->tree, key));
}


/*!
 * Destroy a \c dictionary and released associated resources.
 * All keys and values are destroyed.
 *
 * \param dic \c dictionary to destroy
 * \pre no pointer is NULL (assert-ed)
 */
void dictionary_destroy ( dictionary dic )  {
	node_destroy(&(dic->tree));
	free(dic);
}


/*!
 * Print a \c dictionary to a stream.
 * Entries are printed in \c key alphabetical order.
 * The format is as in the following example with and \c value_integer and a \c value_blok
 \verbatim
 "Bob" => 3
 "Increment_Bob" => {
 Bob
 1
 +
 \Bob
 def
 } \endverbatim
 * \param dic \c dictionary to print
 * \param f stream to print to
 * \pre no pointer is NULL (assert-ed)
 */
void dictionary_print ( dictionary dic , FILE * f )  {
	node_print(dic->tree, f);
}