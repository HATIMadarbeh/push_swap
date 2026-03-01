#include "push_swap.h"

int	is_duplicate(t_stack *stack, int value)
{
	t_node *current;

	if (!stack)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}
