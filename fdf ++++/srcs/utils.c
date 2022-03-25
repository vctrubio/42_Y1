#include "../headers/headers.h"

//later add to libft

void	ft_error_mssg(char *str)
{
	ft_putstr(str);
	exit(1);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float		ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}