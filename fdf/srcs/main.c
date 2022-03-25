#include "../headers/headers.h"

#define W 800
#define H 1200

void		set_fdf(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W, H, "Fdf");
	data->zoom = 10;
	data->angle = 0.8;
}

void		set_mss_box(t_data *data)
{
	char	*msg;

	msg = "hjkl vim mode navigation";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 700, 0xFF0000, msg);
	msg = "i to go In, o to go Out";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 715, 0xFF0000, msg);
	msg = "U n Y to rotate angle";
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 730, 0xFF0000, msg);
}


//todo rotate.
int 			main(int ac, char **av)
{
	t_data	*fdf;
	int		fd;
	
	fdf = (t_data*)malloc(sizeof(t_data));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY, 0);
		if (fd <= 0)
			ft_error_mssg("Please provide valid map~ ./fdf 'maps/42.fdf'\n");
		else
			fdf = (t_data*)malloc(sizeof(t_data));	
		read_file(av[1], fd, fdf);
		close(fd);
	}
	else
		ft_error_mssg("Wrong number of arguments, enter 2: ./fdf maps/42.fdf\n");
	set_fdf(fdf);
	draw(fdf);
	mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}