/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:32:45 by V                 #+#    #+#             */
/*   Updated: 2022/03/16 18:32:57 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lst_clear(t_node *n)
{
	t_node *tmp;

	if (!n)
		return ;
	while (n)
	{
		tmp = n;
		n = n->next;
		free(tmp);
	}
}