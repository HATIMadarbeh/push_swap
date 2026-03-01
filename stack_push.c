#include "push_swap.h"

void	push_stack(t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}
