#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

typedef struct	s_node {
	int		value;
	struct	s_node  *next;
} t_node;

typedef struct	s_stack {
	Node	*head;
	Node	*tail;
	int	size;
} t_stack;

Node  *new_node(int value);
void	push_stack(t_stack *stack, int value);
void	free_stack(t_stack *stack);
int	is_valid_number(const char *str);
int	safe_atoi(const char *str, int *error);
int	is_duplicate(t_stack *stack, int value);
static void     fatal(const char *msg);
void    stack_init(Stack *s);
Node *node_new(int value);
void    stack_append_tail(Stack *s, Node *n);
void    stack_push_head(Stack *s, Node *n);
Node *stack_pop_head(Stack *s);
void    stack_free(Stack *s);
void    stack_print(const char *name, const Stack *s);


#endif
