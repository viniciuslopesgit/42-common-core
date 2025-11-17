#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  len;

    len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
}

char    *ft_strdup(const char *str)
{
    char    *copy;
    int     i;

    copy = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
    if (copy == NULL)
        return (NULL);

    i = 0;
    while (str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *get_next_line(int fd)
{
    static  char buff[BUFFER_SIZE];
            char line[10000];
    static  int a;
    static  int z;
            int i;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);

    i = 0;
    while (1)
    {
        if (a >= z)
        {
            a = 0;
            z = read(fd, buff, BUFFER_SIZE);
            if (z <= 0)
            {
                a = 0;
                z = 0;
                break;
            }
        }
        line[i] = buff[a];
        i++;
        a++;
        if (line[i - 1] == '\n' || i >= 10000)
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return NULL;
    return (ft_strdup(line));
}

/*
#include <fcntl.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    size_t i;
    
    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int     main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        write(2, "Erro ao abrir ficheiro\n", 24);
        return (1);
    }
    while((line = get_next_line(fd)) != NULL)
    {
        ft_putstr(line);
        free(line);
    }
    close(fd);
    return (0);
}
*/