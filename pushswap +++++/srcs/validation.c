/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:47:26 by V                 #+#    #+#             */
/*   Updated: 2022/03/27 13:17:54 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

static void	ft_abc(char *str, t_array *array)
{
	int			nbr;
	char		**tmp;
	int			i;

	i = 0;
	if (count_words(str, 32) == 1 && *str != 0)
		array->array[array->pos++] = ft_abs_atoi(str);
	else if (count_words(str, 32) > 1 && *str != 0)
	{
		tmp = ft_strsplit(str, 32);
		while (tmp[i])
			array->array[array->pos++] = ft_abs_atoi(tmp[i++]);
		ft_clr_split(tmp);
		tmp = 0;
	}
}

static void	ft_fill_init_aray(char **argv, t_array *array)
{
	int	i;

	i = 1;
	while (argv[i])
		ft_abc(argv[i++], array);
}

bool	check_only_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (!ft_isdigit(str[i + 1]))
				return (false);
		}
		else if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	check_unique_numbers(t_array *arr)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arr->size)
	{
		tmp = arr->array[i];
		j = ++i;
		while (j < arr->size)
		{
			if (tmp == arr->array[j++])
			{
				free(arr->array);
				free(arr);
				ft_exit();
			}
		}
	}
	return (true);
}

t_array	*ft_validate_ps(int ac, char **args)
{
	int		c;
	int		i;
	t_array	*arr;

	i = 1;
	c = 0;
	while (args[i])
	{
		if (check_only_numbers(args[i]) == false)
			ft_exit();
		c += count_words(args[i], 32);
		i++;
	}
	arr = malloc(sizeof(t_array));
	arr->array = malloc(sizeof(int) * c);
	arr->size = c;
	ft_fill_init_aray(args, arr);
	check_unique_numbers(arr);
	if (arr->size == 1)
		exit(1);
	return (arr);
}
