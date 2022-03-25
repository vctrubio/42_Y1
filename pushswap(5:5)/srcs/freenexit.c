#include "../head.h"

void	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	freenexit(t_ps *game)
{
	// /* THIS IS BS 
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
		// printf("ok\n");
		if (game->b->head)
			ft_lst_clear(game->b->head);
		if (game->b->inf != NULL)
			free(game->b->inf);
		free(game->b);
	} 
	// */
	free(game);
}