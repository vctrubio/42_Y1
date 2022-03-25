/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:23:28 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/08 15:30:34 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *s)
{
	int	sign;
	int	n;
	int	valid;

	n = 0;
	sign = 1;
	valid = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		valid++;
		s++;
	}
	if (valid > 1)
		return (0);
	while (*s >= '0' && *s <= '9')
		n = n * 10 + *(s++) - '0';
	return (n * sign);
}
