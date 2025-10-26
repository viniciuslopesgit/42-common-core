// Vamos resolver o exercício ft_strcspn da 42. A função strcspn retorna o comprimento da substring inicial da string s que não contém nenhum caractere presente na string reject. Vamos implementar uma versão que reproduza exatamente esse comportamento.

// Explicação
// A função ft_strcspn deve percorrer a string s até encontrar um caractere que esteja presente em reject ou até chegar ao fim de s (\0).
// Para cada caractere em s, verificamos se ele existe em reject. Se encontrarmos um caractere em comum, retornamos o índice atual (o comprimento da substring inicial válida).
// Se chegarmos ao fim de s sem encontrar nenhum caractere de reject, retornamos o comprimento total de s.
// O tipo size_t é usado para o valor de retorno, pois representa um tamanho (inteiro sem sinal).

#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	size_t j = 0;

	while(s[i])
	{
		j = 0;
		while(reject[j])
		{
			if (s[i] == reject[j])
				return i;
			j++;
		}
		i++;
	}
	return i;
}
