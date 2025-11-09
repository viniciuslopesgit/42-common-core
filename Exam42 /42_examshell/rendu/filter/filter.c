#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int  ft_len(char *str)
{
    int len;

    len = 0;
    while(str[len])
        len++;
    return len;
}

void    print_stars(int len)
{
    int i;

    i = 0;
    while(i < len)
    {
        ft_putchar('*');
        i++;
    }
}

void    ft_filter(char *str, char *sub_str)
{
    int i;
    int j;
    int len_substr;

    len_substr = ft_len(sub_str);
    if (len_substr == 0)
    {
        ft_putstr(str);
        return;
    }

    i = 0;
    while (str[i])
    {
        j = 0;
        while (sub_str[j] && (str[i + j] == sub_str[j]))
            j++;
        if (j == len_substr)
        {
            print_stars(len_substr);
            i += len_substr;
        }
        else
        {
            ft_putchar(str[i]);
            i++;
        }
    }
}

int     main(int argc, char **argv)
{
    int     total_read;
    char    buff[BUFFER_SIZE];
    char    *res;
    char    *temp;
    ssize_t bytes;

    total_read = 0;
    res = NULL;
    if (argc != 2)
        return (1);

    while ((bytes = read(0, buff, BUFFER_SIZE)) > 0)
    {
        temp = (char *)realloc(res, total_read + bytes + 1);
        if (temp == NULL)
        {
            perror("realloc");
            free(res);
            return 1;
        }
        res = temp;
        memcpy(res + total_read, buff, bytes);
        total_read += bytes;
        res[total_read] = '\0';
    }
    if (bytes < 0)
    {
        perror("read");
        free(res);
        return 1;
    }
    if (res != NULL)
    {
        ft_filter(res, argv[1]);
        free(res);
    }

    return 0;
}
