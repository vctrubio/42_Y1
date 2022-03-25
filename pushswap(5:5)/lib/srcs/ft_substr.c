/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:25:04 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/08 15:35:34 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char *str, int begg, int l)
{
	char	*sub;
	int		i;
	int		strl;

	if (!str)
		return (0);
	strl = ft_strlen(str);
	if (begg >= strl)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (0);
		*sub = '\0';
		return (sub);
	}
	if (strl < l)
		return (ft_strdup((char *)str + begg));
	i = 0;
	sub = (char *)malloc(l + 1 * sizeof(char));
	if (!sub)
		return (0);
	while (begg < strl && i < l)
		sub[i++] = str[begg++];
	sub[i] = '\0';
	return (sub);
}
