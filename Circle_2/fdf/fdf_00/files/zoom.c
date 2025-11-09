/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:50:19 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/06 03:52:34 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void redraw(t_fdf *data)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr); // limpa janela
    draw_map(data);
}

void set_initial_view(t_fdf *data, int win_width, int win_height)
{
    int margin = 100;
    int z_min, z_max;

    // Obtém os valores de z mínimo e máximo
    get_z_range(data, &z_min, &z_max);

    // Dimensões projetadas na projeção isométrica
    // x = (prev_x - prev_y) * cos(30°) * zoom
    // y = (prev_x + prev_y) * sin(30°) * zoom - z * zoom
    float cos_30 = cos(0.523599); // Aproximadamente 0.866
    float sin_30 = sin(0.523599); // Aproximadamente 0.5

    // Extremos das coordenadas projetadas
    float min_x = (0 - (data->height - 1)) * cos_30; // Quando x=0, y=height-1
    float max_x = ((data->width - 1) - 0) * cos_30;  // Quando x=width-1, y=0
    float min_y = (0 + 0) * sin_30 - z_max;          // Quando x=0, y=0, z=z_max
    float max_y = ((data->width - 1) + (data->height - 1)) * sin_30 - z_min; // Quando x=width-1, y=height-1, z=z_min

    // Dimensões projetadas do mapa (em unidades, sem zoom)
    float iso_width = max_x - min_x;
    float iso_height = max_y - min_y;

    // Ajustar o zoom pra que o mapa caiba na janela
    float zoom_x = (win_width - 2 * margin) / iso_width;
    float zoom_y = (win_height - 2 * margin) / iso_height;
    data->zoom = (zoom_x < zoom_y) ? zoom_x : zoom_y;

    // Ajustar os deslocamentos pra centrar o mapa
    float map_width = iso_width * data->zoom;
    float map_height = iso_height * data->zoom;

    // Centra o mapa considerando os extremos projetados
    data->shift_x = (win_width - map_width) / 2 - min_x * data->zoom;
    data->shift_y = (win_height - map_height) / 2 - min_y * data->zoom;
}

int deal_key(int key, t_fdf *data)
{
    if (key == 65307) // Tecla ESC
    {
        free_data(data);
        exit(0); // Sai do programa
    }
    if (key == 61 || key == 65451) // Tecla +
        data->zoom += 5;
    if (key == 45 || key == 65453) // Tecla -
        data->zoom -= 5;
    if (key == 65362) // Seta pra cima
        data->shift_y -= 10;
    if (key == 65364) // Seta pra baixo
        data->shift_y += 10;
    if (key == 65361) // Seta pra esquerda
        data->shift_x -= 10;
    if (key == 65363) // Seta pra direita
        data->shift_x += 10;

    redraw(data); // Redesenha com os novos valores
    return (0);
}