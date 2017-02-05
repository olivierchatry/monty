#ifndef __DLIST_H__
#define __DLIST_H__

union dlist_value_u {
	int		as_int;
	void	*as_ptr;
};

typedef union dlist_value_u dlist_value_t;

struct dlist_node_s {
	struct dlist_node_s	*prev;
	struct dlist_node_s	*next;
	dlist_value_t				value;
};

typedef struct dlist_node_s	dlist_node_t;

struct dlist_s {
	dlist_node_t	*head;
	dlist_node_t	*tail;
	int						count;
};

typedef struct dlist_s dlist_t;

typedef void(*dlist_fct_t)(dlist_value_t);

void		dlist_init(dlist_t *dlist);
void		dlist_apply_head_to_tail(dlist_t *dlist, dlist_fct_t fct);
void		dlist_apply_tail_to_head(dlist_t *dlist, dlist_fct_t fct);
void		dlist_free(dlist_t *dlist);
void		dlist_push_tail(dlist_t *dlist, dlist_value_t value);
void		dlist_push_head(dlist_t *dlist, dlist_value_t value);

dlist_value_t dlist_pop_tail(dlist_t *dlist);
dlist_value_t dlist_pop_head(dlist_t *dlist);

#endif