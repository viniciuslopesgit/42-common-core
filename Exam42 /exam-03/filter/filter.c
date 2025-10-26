#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BLOCK 1024

int main(int argc, char **argv)
{
    if (argc != 2 || argv[1][0] == '\0')
        return 1;

    char *pat = argv[1];
    size_t pat_len = strlen(pat);

    char buf[BLOCK];
    char carry[BLOCK + 256]; // buffer grande suficiente
    size_t carry_len = 0;

    ssize_t n;
    while ((n = read(0, buf, BLOCK)) > 0)
    {
        memcpy(carry + carry_len, buf, n);
        size_t total_len = carry_len + n;

        char *ptr = carry;
        char *end = carry + total_len;

        while ((ptr = memmem(ptr, end - ptr, pat, pat_len)) != NULL)
        {
            memset(ptr, '*', pat_len);
            ptr += pat_len;
        }

        size_t write_len = (total_len >= pat_len - 1) ? total_len - (pat_len - 1) : 0;
        if (write_len > 0 && write(1, carry, write_len) < 0)
        {
            perror("Error");
            return 1;
        }

        carry_len = total_len - write_len;
        memmove(carry, carry + write_len, carry_len);
    }

    if (n < 0)
    {
        perror("Error");
        return 1;
    }

    if (carry_len > 0 && write(1, carry, carry_len) < 0)
    {
        perror("Error");
        return 1;
    }

    return 0;
}
