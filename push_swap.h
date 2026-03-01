#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_node	*new_node(int value);
void	push_stack(t_stack *stack, int value);
void	free_stack(t_stack *stack);
int	is_valid_number(const char *str);
int	safe_atoi(const char *str, int *error);
int	is_duplicate(t_stack *stack, int value);

#endif
