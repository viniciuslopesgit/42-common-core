/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:31:16 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/16 20:00:21 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

int main(int argc, char **argv)
{
    t_fdf *data; // Ponteiro para a estrutura t_fdf
    int win_width;
    int win_height;

    if (argc != 2)
    {
        write(1, "Error: Usage: ./fdf <filename>.fdf\n", 36);
        return (1);
    }
    data = (t_fdf *)malloc(sizeof(t_fdf));
    get_dimensions(argv[1], &data->width, &data->height);
    data->map = read_map(argv[1], data->width, data->height);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF - 42School");
    // Ajusta o zoom e os deslocamentos automaticamente
    win_width = 1000;
    win_height = 1000;
    set_initial_view(data, win_width, win_height);

    draw_map(data);
    // Associa teclas
    mlx_key_hook(data->win_ptr, deal_key, data);
    mlx_hook(data->win_ptr, 17, 0, close_window, data);
    // para manter a janela aberta
    mlx_loop(data->mlx_ptr); // Entra num ciclo infinito, esperando eventos (como cliques ou teclas). Passamos o mlx_ptr porque é ele que controla tudo.
    return (0);
}
