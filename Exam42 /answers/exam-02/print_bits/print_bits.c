
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit = 8;

	while(i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main()
{
	int n = 2;

	print_bits(n);
	return 0;
}