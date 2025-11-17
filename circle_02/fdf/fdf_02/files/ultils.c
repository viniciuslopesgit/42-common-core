/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:06:53 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/18 13:51:56 by vilopes          ###   ########.fr       */
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

void	get_dimensions(char *file, int *width, int *height)
{
	int		fd;
	char	*line;
	int		i;

	*height = 0;
	*width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*height == 0)
		{
			i = 0;
			while (line[i])
			{
				if ((line[i] != ' ') && (line[i + 1] == ' '
						|| line[i + 1] == '\0'))
				{
					(*width)++;
				}
				i++;
			}
		}
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int **read_map(char *file, int width, int height)
{
    int fd;
    char *line;
    int **map;
    int x;
	int y;
	int i;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
    map = malloc(sizeof(int *) * height); // Aloca espaço pras linhas
	if (!map)
	{
		close(fd);
		return (NULL);
    }
	y = 0;
    while (y < height)
    {
        line = get_next_line(fd);         // Lê a linha diretamente
        if (!line)                        // Se NULL, algo correu mal
            break;
        map[y] = malloc(sizeof(int) * width); // Aloca espaço pras colunas
        if (!map[y])
		{
			free(line);
			while( y >= 0)
				free(map[y--]);
			free(map);
			close(fd);
			return (NULL);
		}
		x = 0;
		i = 0;
		while (x < width)
		{
			while (line[i] == ' ')
                i++;                      // Pula espaços
            map[y][x] = ft_atoi(&line[i]);   // Converte pra número
            while (line[i] && line[i] != ' ')
                i++;                      // Avança até o próximo espaço
            x++;	
		}
        free(line);
        y++;
    }
    close(fd);
    return (map);
}
