/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:45:34 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/18 21:57:01 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	bresenham_loop(t_fdf *data, t_point *start,
	t_point end, t_drawline line)
{
	int	err;
	int	e2;

	err = line.dx - line.dy;
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start->x,
			start->y, line.color);
		if (start->x == end.x && start->y == end.y)
			break ;
		e2 = err * 2;
		if (e2 > -line.dy)
		{
			err -= line.dy;
			start->x += line.sx;
		}
		if (e2 < line.dx)
		{
			err += line.dx;
			start->y += line.sy;
		}
	}
}

static int	process_line(char *line, int *row, int width)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (x < width)
	{
		while (line[i] == ' ')
			i++;
		if (!line[i])
			return (0);
		row[x] = ft_atoi(&line[i]);
		while (line[i] && line[i] != ' ')
			i++;
		x++;
	}
	return (1);
}

static int	**alloc_map(int width, int height)
{
	int	**map;
	int	y;

	map = malloc(sizeof(int *) * height);
	if (!map)
		return (NULL);
	y = 0;
	while (y < height)
	{
		map[y] = malloc(sizeof(int) * width);
		if (!map[y])
		{
			while (y > 0)
				free(map[--y]);
			free(map);
			return (NULL);
		}
		y++;
	}
	return (map);
}

static void	free_map_close(int **map, int y, int fd, char *line)
{
	while (y >= 0)
		free(map[y--]);
	free(map);
	free(line);
	close(fd);
}

int	**read_map(char *file, int width, int height)
{
	int		fd;
	int		**map;
	int		y;
	char	*line;

	y = 0;
	fd = open(file, O_RDONLY);
	map = alloc_map(width, height);
	if (fd < 0 || !map)
		return (NULL);
	while (y < height)
	{
		line = get_next_line(fd);
		if (!line || !process_line(line, map[y], width))
		{
			free_map_close(map, y, fd, line);
			return (NULL);
		}
		free(line);
		y++;
	}
	close(fd);
	return (map);
}
