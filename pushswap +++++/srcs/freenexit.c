/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freenexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:45:17 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/27 18:21:49 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head.h"

void	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	freenexit(t_ps *game)
{
	if (game->a)
	{
		if (game->a->head)
			ft_lst_clear(game->a->head);
		if (game->a->inf != NULL)
			free(game->a->inf);
		free(game->a);
	}
	if (game->b)
	{
		if (game->b->head)
			ft_lst_clear(game->b->head);
		if (game->b->inf != NULL)
			free(game->b->inf);
		free(game->b);
	}
	free(game);
}
