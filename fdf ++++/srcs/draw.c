#include "../headers/headers.h"

static void		isometrical(float *x, float *y, int z, double angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

static void		set_color(t_data *data, int z, int z1)
{
	if (z)
		data->color =  0x0000ff;
	else 
		data->color = 0x00ff00;
}

void		set_z(t_data *data, float x, float x1, float y, float y1)
{
	data->z = data->z_matrix[(int)y][(int)x];
	data->z1 = data->z_matrix[(int)y1][(int)x1];
	set_color(data, data->z, data->z1);
}

void			bman(float x, float y, float x1, float y1, t_data *data)
{
	int		max;

	set_z(data, x, x1, y, y1);
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	isometrical(&x, &y, data->z, data->angle);
	isometrical(&x1, &y1, data->z1, data->angle);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	data->x_step = x1 - x;
	data->y_step = y1 - y;
	max = ft_max(ft_abs(data->x_step), ft_abs(data->y_step));
	data->x_step /= max;
	data->y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + OFFSET, y + OFFSET, data->color);
		x += data->x_step;
		y += data->y_step;
	}
}

void			draw(t_data *data)
{
	int		x;
	int		y;

	set_mss_box(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bman(x, y, x + 1, y, data);		
			if (y < data->height - 1)
				bman(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}