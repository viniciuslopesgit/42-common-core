/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:36:26 by vilopes           #+#    #+#             */
/*   Updated: 2024/12/11 23:05:46 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *extract_line(char **store)
{
    char    *line;
    char    *temp;
    int     i;

    i = 0;
    while ((*store)[i] && (*store)[i] != '\n')
        i++;
        
    if ((*store)[i] == '\n')
        i++;
    
    line = ft_substr(*store, 0, i);
    
    temp = ft_strdup(*store + i);
    free (*store);
    *store = temp;
    return (line);
}

static char *read_and_store(int fd, char *store)
{
    char    buff[BUFFER_SIZE + 1];
    int     bytes_r;
    char    *temp;

    if (!store)
        store = ft_strdup("");
    while (1)
    {
        bytes_r = read(fd, buff, BUFFER_SIZE);
        if (bytes_r == -1)
            return (0);
        else if (bytes_r == 0)
            break; // end of read or error
        
        buff[bytes_r] = '\0';
        temp = ft_strjoin(store, buff);
        if (!temp)
        {
            free(store);
            return (NULL);
        }
        free(store);
        store = temp;
        if (ft_strchr(buff, '\n'))
            break;
    }
    return (store);
}

char	*get_next_line(int fd)
{
    char	*store;

    store = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    store = read_and_store(fd, store);
    if (!store || *store == '\0')
        return (NULL);
    return (extract_line(&store));
}


/*
read - le ate o BUFFER_SIZE bytes do fd para o buffer;
return strdup - retorna o que foi lido(BUFFER_SIZE + 1) "\0";
*/
/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Erro ao abrir o ficheiro.\n");
        return (1);
    }
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
*/