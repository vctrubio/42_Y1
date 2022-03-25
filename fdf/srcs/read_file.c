#include "../headers/headers.h"

static int		get_height(char *file)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int		get_width(char *file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wrdcnt(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void			fill_matrix(int *z_line, char *line)
{
	char	**n;
	int		i;

	n = ft_strsplit(line, ' ');
	i = 0;
	while (n[i])
	{
		z_line[i] = ft_atoi(n[i]);
		free(n[i]);
		i++;
	}
	free(n);
}

void			read_file(char *file, int fd, t_data *data)
{
	char	*line;
	int		i;

	data->height = get_height(file);
	data->width = get_width(file);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
}