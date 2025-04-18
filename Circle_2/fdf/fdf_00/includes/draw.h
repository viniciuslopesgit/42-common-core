/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:09:35 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/16 19:28:45 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

#   include "../libft/minilibx-linux/mlx.h" // Cabecalho MiniLibX
#   include <stdlib.h> // Para usar malloc e free
#   include <fcntl.h> // Para 'open' e 'close'
#   include <unistd.h>
#   include <math.h>
#   include <stdlib.h>

typedef struct s_fdf
{
    void    *mlx_ptr;  // Ponteiro para MiniLibX
    void    *win_ptr;  // Ponteiro para janela
    int     **map;      // matriz com os valores do mapa
    int     height;     // altura da matriz
    int     width;      // largura da matriz
    int     zoom;      // Escala do desenho
    int     shift_x;
    int     shift_y;
}           t_fdf;

typedef struct s_point
{
    int x;
    int y;
    int z;
}       t_point;

typedef struct s_drawline
{
    int dx;
	int dy;
	int sx;
	int sy;
	int avg_z;
	int color;
}       t_drawline;

// Calcula o tamanho da matriz
void get_dimensions(char *file, int *width, int *height);
void get_z_range(t_fdf *data, int *z_min, int *z_max);
int **read_map(char *file, int width, int height);
// Desenha matriz na janela
void draw_map(t_fdf *data);
// Adiciona cores
int get_color(int z);
// limpa tela
void redraw(t_fdf *data);
void get_z_range(t_fdf *data, int *z_min, int *z_max);
//set inicial _view
void set_initial_view(t_fdf *data, int win_width, int win_height);
// teclas
int deal_key(int key, t_fdf *data);
// fecha janela com X
void free_data(t_fdf *data);
int close_window(t_fdf *data);

#endif