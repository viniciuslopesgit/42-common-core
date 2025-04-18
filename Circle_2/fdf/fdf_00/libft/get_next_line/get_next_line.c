/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:36:26 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/06 02:59:30 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	vc;

	vc = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == vc)
			return ((char *)&s[i]);
		i++;
	}
	if (vc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

static char	*extract_line(char **store)
{
	char	*line;
	char	*temp;
	int		i;

	if (!store || !*store)
		return (NULL);
	i = 0;
	while ((*store)[i] && (*store)[i] != '\n')
		i++;
	if ((*store)[i] == '\n')
		i++;
	line = ft_substr(*store, 0, i);
	if (!line)
		return (NULL);
	temp = ft_strdup(*store + i);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(*store);
	*store = temp;
	if (**store == '\0')
	{
		free(*store);
		*store = NULL;
	}
	return (line);
}

static char	*handle_read(int bytes_r, char *store, char *buff)
{
	char	*temp;

	buff[bytes_r] = '\0';
	temp = ft_strjoin(store, buff);
	if (!temp)
	{
		free(store);
		return (NULL);
	}
	free(store);
	return (temp);
}

static char	*read_and_store(int fd, char *store)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_r;

	if (!store)
		store = ft_strdup("");
	if (!store)
		return (NULL);
	bytes_r = read(fd, buff, BUFFER_SIZE);
	while (bytes_r > 0)
	{
		store = handle_read(bytes_r, store, buff);
		if (!store || ft_strchr(buff, '\n'))
			break ;
		bytes_r = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes_r < 0)
	{
		free(store);
		return (NULL);
	}
	return (store);
}

void gnl_cleanup(void)
{
    static char *store = NULL; // Re-declaramos a estática aqui pra acessar

    if (store)
    {
        free(store);
        store = NULL;
    }
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_and_store(fd, store);
	if (!store)
		return (NULL);
	if (*store == '\0')
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	line = extract_line(&store);
	if (!line)
	{
		free(store);
		store = NULL;
	}
	return (line);
}
/*
# include <stdio.h>
int main(void)
{
    int     fd;
    char    *line;
    int     line_number;

    // Abrir o ficheiro test.txt
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Erro ao abrir o ficheiro test.txt");
        return (1);
    }

    printf("Lendo do ficheiro test.txt:\n");
    line_number = 1;

    // Ler linhas do ficheiro até EOF
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linha %d: %s", line_number, line);
        free(line);
        line_number++;
    }

    // Fechar o ficheiro
    close(fd);
    return (0);
}
*/