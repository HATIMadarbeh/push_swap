#include "push_swap.h"

int	safe_atoi(const char *str, int *error)
{
	long	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	*error = 0;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return ((int)(result * sign));
}
