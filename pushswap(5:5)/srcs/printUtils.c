#include "../head.h"

void	ft_print_node_h(t_node *n)
{
	t_node	*ptr;

	ptr = n;
	// printf("hello from node_t (%d)\n", ptr->nb);
	while (ptr)
	{
		printf("%d ", ptr->nb);
		if (ptr->next == NULL)
			break;
		ptr = ptr->next;
	}
	printf("print_ll_h\n");
}

void	ft_print_node_t(t_node *n)
{
	t_node	*ptr;

	ptr = n;
	while (ptr)
	{
		printf("%d ", ptr->nb);
		if (ptr->prev == NULL)
			break;
		ptr = ptr->prev;
	}
	printf("print_ll_t\n");
}

void	ft_printf_arr(int *a, int size)
{
	int	i;

	i = 0;
	while(i < size)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
}
