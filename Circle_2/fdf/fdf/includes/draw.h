/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:09:35 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/18 16:02:03 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "get_next_line.h"
# include "../minilibx-linux/mlx.h" // Cabecalho MiniLibX
# include <stdlib.h> // Para usar malloc e free
# include <fcntl.h> // Para 'open' e 'close'
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**map;
	int		height;
	int		width;
	int		zoom;
	int		shift_x;
	int		shift_y;
}			t_fdf;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct s_drawline
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		avg_z;
	int		color;
}			t_drawline;

typedef struct s_init_view
{
	int		margin;
	int		z_min;
	int		z_max;
	float	cos_30;
	float	sin_30;
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
	float	iso_width;
	float	iso_height;
	float	zoom_x;
	float	zoom_y;
	float	map_width;
	float	map_height;
}			t_init_view;

int		ft_atoi(const char *str);
void	*ft_memset(void *s, int c, size_t n);

void	get_dimensions(char *file, int *width, int *height);
void	get_z_range(t_fdf *data, int *z_min, int *z_max);
int		**read_map(char *file, int width, int height);
void	draw_map(t_fdf *data);
int		get_color(int z);
void	redraw(t_fdf *data);
void	get_z_range(t_fdf *data, int *z_min, int *z_max);
void	set_initial_view(t_fdf *data, int win_width, int win_height);
int		deal_key(int key, t_fdf *data);
void	free_data(t_fdf *data);
int		close_window(t_fdf *data);
void	bresenham_loop(t_fdf *data, t_point *start,
			t_point end, t_drawline line);

#endif
