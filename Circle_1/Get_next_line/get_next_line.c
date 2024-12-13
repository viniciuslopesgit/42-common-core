/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:36:26 by vilopes           #+#    #+#             */
/*   Updated: 2024/12/13 19:47:49 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **store)
{
	char	*line;
	char	*temp;
	int		i;

	if (!store || !*store) // Verifica se `store` está válido
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
	if (!temp) // Falha na alocação
	{
		free(line);
		return (NULL);
	}
	free(*store);
	*store = temp;
	return (line);
}

static char	*read_and_store(int fd, char *store)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes_r;
	char	*temp;

	if (!store)
		store = ft_strdup("");
	if (!store)
		return (NULL);
	while (1)
	{
		bytes_r = read(fd, buff, BUFFER_SIZE);
		if (bytes_r < 0)
		{
			free(store);
			return (NULL);
		}
		if (bytes_r == 0)
			break ;
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
			break ;
	}
	return (store);
}

char	*get_next_line(int fd)
{
	char	*line;

	static char *store; // Mantém o estado entre chamadas
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_and_store(fd, store);
	if (!store) // Falha na leitura ou memória
		return (NULL);
	if (*store == '\0') // Fim do ficheiro (string vazia)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	line = extract_line(&store);
	if (!line) // Falha na extração
	{
		free(store);
		store = NULL;
	}
	return (line);
}
