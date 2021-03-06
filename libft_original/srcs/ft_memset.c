/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:24:16 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/08 15:32:32 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *str, char c, size_t l)
{
	size_t	i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (i < l)
		s[i++] = c;
	return (s);
}
