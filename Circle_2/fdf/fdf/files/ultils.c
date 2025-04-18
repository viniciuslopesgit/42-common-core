/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:06:53 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/18 21:43:24 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	get_z_range(t_fdf *data, int *z_min, int *z_max)
{
	int		x;
	int		y;

	*z_min = data->map[0][0];
	*z_max = data->map[0][0];
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] < *z_min)
				*z_min = data->map[y][x];
			if (data->map[y][x] > *z_max)
				*z_max = data->map[y][x];
			x++;
		}
		y++;
	}
}

static int	count_width(char *line)
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
		i++;
	}
	return (width);
}

void	get_dimensions(char *file, int *width, int *height)
{
	int		fd;
	char	*line;

	*height = 0;
	*width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		if (*height == 0)
			*width = count_width(line);
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
