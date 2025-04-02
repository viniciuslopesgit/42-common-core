/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viniciuslopes <viniciuslopes@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:18:58 by viniciuslop       #+#    #+#             */
/*   Updated: 2025/03/19 23:21:35 by viniciuslop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

long	ft_printf(const char *str, ...);
void	ft_putchar_len(char c, int long *len);
void	ft_putstr(char *str, int long *len);
void	ft_putnbr(long n, long *len);
void	ft_putpointer(size_t ptr, long *len);
void	ft_puthex(unsigned int x, long *len, char c);
void	ft_putunsigned_int(unsigned int n, long *len);

#endif