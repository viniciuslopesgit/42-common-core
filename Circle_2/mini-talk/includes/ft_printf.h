////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                    ////
////                                Minitalk - FT_PRINTF                                ////
////                                                                                    ////
////////////////////////////////////////////////////////////////////////////////////////////

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> // Default function for 'write' and 'unsleep';
# include <stdarg.h> // Default function for variables args; ex: 'int soma(int num, ...)';
# include <stdlib.h> // Default function for 'malloc';
# include <stddef.h> // Default function for 'sizeof', 'size_t'...;

long	ft_printf(const char *str, ...);
void	ft_putchar_len(char c, int long *len);
void	ft_putstr(char *str, int long *len);
void	ft_putnbr(long n, long *len);
void	ft_putpointer(size_t ptr, long *len);
void	ft_puthex(unsigned int x, long *len, char c);
void	ft_putunsigned_int(unsigned int n, long *len);

#endif
