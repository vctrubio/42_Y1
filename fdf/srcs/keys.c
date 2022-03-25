#include "../headers/headers.h"

int		deal_key(int key, t_data *data)
{
	if (key == K_K)
		data->shift_y -= 10;
	if (key == K_J)
		data->shift_y += 10;
	if (key == K_H)
		data->shift_x -= 10;
	if (key == K_L)
		data->shift_x += 10;
	if (key == K_I)
		data->zoom += 5;
	if (key == K_O)
		data->zoom -= 5;
	if (key == K_U)
		data->angle += 0.05;
	if (key == K_Y)
		data->angle -= 0.05;
	if (key == K_ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(1);
	}	
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
