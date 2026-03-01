#include "push_swap.h"
#include <unistd.h>

int main(int argc, char **argv)
{
    t_stack stack;
    int i;
    int num;
    int error;

    stack.top = NULL;
    stack.size = 0;

    if (argc < 2)
        return (0);

    i = 1;
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
        {
            write(2, "Error\n", 6);
            free_stack(&stack);
            return (1);
        }

        num = safe_atoi(argv[i], &error);
        if (error)
        {
            write(2, "Error\n", 6);
            free_stack(&stack);
            return (1);
        }

        if (is_duplicate(&stack, num))
        {
            write(2, "Error\n", 6);
            free_stack(&stack);
            return (1);
        }

        push_stack(&stack, num);
        i++;
    }

    free_stack(&stack);
    return (0);
}
