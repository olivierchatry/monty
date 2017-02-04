#ifndef __DLIST_H__
#define __DLIST_H__

struct dlist_node_s {
	struct dlist_node_s	*prev;
	struct dlist_node_s	*next;
	void*								value;
};

typedef struct dlist_node_s	dlist_node_t;

struct dlist_s {
	dlist_node_t	*head;
	dlist_node_t	*tail;
	int						count;
};

typedef struct dlist_s dlist_t;

typedef void(*dlist_fct_t)(void*);

void		dlist_init(dlist_t *dlist);
void		dlist_apply_head_to_tail(dlist_t *dlist, dlist_fct_t fct);
void		dlist_apply_tail_to_head(dlist_t *dlist, dlist_fct_t fct);
void		dlist_free(dlist_t *dlist);
void		dlist_push_tail(dlist_t *dlist, void *value);
void		dlist_push_head(dlist_t *dlist, void *value);
void		*dlist_pop_tail(dlist_t *dlist);
void		*dlist_pop_head(dlist_t *dlist);

#endif