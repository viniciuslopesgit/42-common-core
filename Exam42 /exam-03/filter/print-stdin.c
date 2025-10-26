#include <stdio.h>
#include <unistd.h>

#define BLOCK 50

int main()
{
    char buff[BLOCK];
    size_t n = 0;

    while((n = read(0, buff, BLOCK)) > 0)
    {
        write(1, buff, n);
    }

    return 0;
}