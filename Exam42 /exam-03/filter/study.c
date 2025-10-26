#include <unistd.h>
#include <stdio.h>

#define BLOCK 1024

int main(int argc, char **argv)
{

    if (argc != 2 || argv[1][0] == ' ')
        return 1;

    char buff[BLOCK];
    size_t n = 0;

    while( (n = (read(0, buff, BLOCK))) > 0)
    {
        write(1, buff, n);
    }

    return 0;
}