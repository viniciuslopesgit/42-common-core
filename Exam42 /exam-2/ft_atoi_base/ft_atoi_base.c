

//Verifica se o char é válido enquanto for menor que o tamanho da base
// NUM + ABCDEF...
int is_valid(char c, int str_base)
{
	char base1[17] = "0123456789abcdef";
	char base2[17] = "0123456789ABCDEF";

	int i = 0;
	while(i < str_base)
	{
		if (c == base1[i] || c == base2[i])
			return (1);
		i++;
	}
	return 0;
}

// converte o base number em int
int base_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c = c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c = (c - 'a') + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return 0;
}

int	ft_atoi_base(const char *str, int str_base)
{

	int i = 0;
	int sign = 1;
	int result = 0;

	while(str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++; 
	}
	while(is_valid(str[i], str_base))
	{
		result = (result * str_base) + (base_num(str[i]));
		i++;
	}
	return (result * sign);
}


// #include <stdio.h>
// int main()
// {

// 	int n = ft_atoi_base("-13268!", 10);
// 	printf("%d\n", n);
// 	return 0;
// }