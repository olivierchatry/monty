#include <stdlib.h>
#include "dlist.h"

void		dlist_init(dlist_t* dlist) {
	dlist->count = 0;
	dlist->head = NULL;
	dlist->tail = NULL;
}

void		dlist_apply_tail_to_head(dlist_t *dlist, void *user_data, dlist_fct_t fct) {
	dlist_node_t* node = dlist->tail;
	
	while(node) {
		if (fct(user_data, node->value) == DLIST_CONTINUE) {
			node = node->prev;
		}	else {
			node = NULL;
		}
	}	
}

void		dlist_apply_head_to_tail(dlist_t *dlist, void *user_data, dlist_fct_t fct) {
	dlist_node_t* node = dlist->head;
	
	while(node) {
		if (fct(user_data, node->value) == DLIST_CONTINUE) {
			node = node->next;
		}	else {
			node = NULL;
		}
	}	
}

void		dlist_free(dlist_t *dlist) {
	dlist_node_t	*node = dlist->head;

	while(node) {
		dlist_node_t	*current = node;

		node = node->next;
		free(current);
	}
	dlist_init(dlist);
}

void		dlist_push_tail(dlist_t *dlist, dlist_value_t value) {
	dlist_node_t	*new;
	
	new = (dlist_node_t*) calloc(sizeof(dlist_node_t), 1);
	if (new) {
		new->value = value;
		if (dlist->tail) {
			dlist->tail->next = new;
			new->prev = dlist->tail;
			dlist->tail = new;
		} else {
			dlist->tail = dlist->head = new;
		}
		dlist->count++;
	}
}

void		dlist_push_head(dlist_t *dlist, dlist_value_t value) {
	dlist_node_t	*new;
	
	new = (dlist_node_t*) calloc(sizeof(dlist_node_t), 1);
	if (new) {
		new->value = value;
		if (dlist->head) {
			dlist->head->prev = new;
			new->next = dlist->head;
			dlist->head = new;
		} else {
			dlist->tail = dlist->head = new;
		}
		dlist->count++;
	}
}

dlist_value_t dlist_pop_tail(dlist_t *dlist) {
	dlist_value_t value;

	value.as_ptr = NULL;
	if (dlist->tail) {
		dlist_node_t	*prev;

		prev = dlist->tail->prev;
		value = dlist->tail->value;
		free(dlist->tail);
		dlist->tail = prev;
		dlist->count--;
	}
	if (dlist->tail == NULL) {
		dlist->head = NULL;
	} else {
		dlist->tail->next = NULL;
	}
	return value;
}

dlist_value_t dlist_pop_head(dlist_t *dlist) {
	dlist_value_t value;

	value.as_ptr = NULL;
	if (dlist->head) {
		dlist_node_t	*next;

		next = dlist->head->next;
		value = dlist->head->value;
		free(dlist->head);
		dlist->head = next;
		dlist->count--;
	}
	if (dlist->head == NULL) {
		dlist->tail = NULL;
	} else {
		dlist->head->prev = NULL;
	}
	return value;
}
