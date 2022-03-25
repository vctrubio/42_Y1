/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:35:13 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/08 16:01:06 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strsplit(char const *str, char c)
{
	char	**split;
	int		i;
	int		i2;
	int		cnt;

	i = 0;
	i2 = 0;
	cnt = 0;
	split = (char **)malloc(sizeof(char *) * (count_words((char *)str, c) + 1));
	if (!split)
		return (0);
	while (cnt < count_words((char *)str, c) && count_words((char *)str, c) > 0)
	{
		while (str[i] == c && str[i])
			i++;
		i2 = i;
		while (str[i] != c && str[i])
			i++;
		split[cnt++] = ft_substr((char *)str, i2, i - i2);
	}
	split[cnt] = 0;
	return (split);
}
