/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:06:53 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/06 03:44:30 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/get_next_line/get_next_line.h"
#include "../includes/draw.h"

// Abrir o ficheiro e preparar as variaveis
// Ler a primeira linha para contar colunas
// Continuar a ler para contar linhas
// Fechar o ficheiro e devolver os valores via ponteiro

void get_z_range(t_fdf *data, int *z_min, int *z_max)
{
    int x, y;

    *z_min = data->map[0][0];
    *z_max = data->map[0][0];

    for (y = 0; y < data->height; y++)
    {
        for (x = 0; x < data->width; x++)
        {
            if (data->map[y][x] < *z_min)
                *z_min = data->map[y][x];
            if (data->map[y][x] > *z_max)
                *z_max = data->map[y][x];
        }
    }
}

void get_dimensions(char *file, int *width, int *height)
{
    int     fd;
    char    *line; // Nao e preciso iniciar edr de memoria
    int     i;

    *height = 0;
    *width = 0;
    fd = open(file, O_RDONLY); // Abre o ficheiro para leitura
    if (fd < 0) // Se der erro, sai
        return ;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (*height == 0)
        {
            i = 0;
            while (line[i])
            {
                if ((line[i] != ' ') && (line[i + 1] == ' ' || line[i + 1] == '\0'))
                    (*width)++;
                i++;
            }
        }
        (*height)++; // Cada linha soma 1 a altura
        free(line); // Liberta a linha devolvida por get_next_line
    }
    close(fd);
}

int **read_map(char *file, int width, int height)
{
    int fd;
    char *line;
    int **map;
    int x, y;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
    map = malloc(sizeof(int *) * height); // Aloca espaço pras linhas
    y = 0;
    while (y < height)
    {
        line = get_next_line(fd);         // Lê a linha diretamente
        if (!line)                        // Se NULL, algo correu mal
            break;
        map[y] = malloc(sizeof(int) * width); // Aloca espaço pras colunas
        x = 0;
        for (int i = 0; x < width; i++)
        {
            while (line[i] == ' ')
                i++;                      // Pula espaços
            map[y][x] = atoi(&line[i]);   // Converte pra número
            while (line[i] && line[i] != ' ')
                i++;                      // Avança até o próximo espaço
            x++;
        }
        free(line);                       // Liberta a linha
        y++;
    }
    close(fd);
    return (map);
}