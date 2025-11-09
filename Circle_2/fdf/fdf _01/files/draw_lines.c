/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:05:43 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/16 21:00:54 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

static void	bresenham_loop(t_fdf *data, t_point *start, t_point end, t_drawline line)
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

void	draw_line(t_fdf *data, t_point start, t_point end)
{
	t_drawline	line;

	line.dx = abs(end.x - start.x);
	line.dy = abs(end.y - start.y);
	line.avg_z = (start.z + end.z) / 2;
	line.color = get_color(line.avg_z);
	if (start.x < end.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (start.y < end.y)
		line.sy = 1;
	else
		line.sy = -1;
	bresenham_loop(data, &start, end, line);
}

void	isometric_draw(t_point *point, t_fdf *data)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (prev_x - prev_y) * cos(0.523599) * data->zoom + data->shift_x;
	point->y = (prev_x + prev_y) * sin(0.523599) * data->zoom \
		- point->z * data->zoom + data->shift_y;
}

static void	draw_horizontal_line(t_fdf *data, int x, int y)
{
	t_point	start;
	t_point	end;

	start.x = x;
	start.y = y;
	start.z = data->map[y][x];
	isometric_draw(&start, data);
	if (x + 1 < data->width)
	{
		end.x = x + 1;
		end.y = y;
		end.z = data->map[y][x + 1];
		isometric_draw(&end, data);
		draw_line(data, start, end);
	}
}

static void	draw_vertical_line(t_fdf *data, int x, int y)
{
	t_point	start;
	t_point	end;

	start.x = x;
	start.y = y;
	start.z = data->map[y][x];
	isometric_draw(&start, data);
	if (y + 1 < data->height)
	{
		end.x = x;
		end.y = y + 1;
		end.z = data->map[y + 1][x];
		isometric_draw(&end, data);
		draw_line(data, start, end);
	}
}

void	draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw_horizontal_line(data, x, y);
			draw_vertical_line(data, x, y);
			x++;
		}
		y++;
	}
}
