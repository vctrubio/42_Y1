#ifndef HEADERS_H
# define HEADERS_H

#define OFFSET 350

#include "../lmlx/mlx.h"
#include "../lib/libft.h"
#include "keys.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct s_data
{
	int			width;
	int			height;
	int			**z_matrix;
	int			z;
	int			z1;
	int			zoom;
	int			color;
	double		angle;
	int			shift_x;
	int			shift_y;
	float		x_step;
	float		y_step;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

//FDF
void			read_file(char *file, int fd, t_data *data);
void			bressenham(float x, float y, float x1, float y1, t_data *data);
void			draw(t_data *data);
int				deal_key(int key, t_data *data);
int				ft_max(int a, int b);
float			ft_abs(float a);
void			ft_error_mssg(char *str);
void			set_mss_box(t_data *data);

#endif
