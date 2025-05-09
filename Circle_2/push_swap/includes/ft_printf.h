/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:52:54 by vilopes           #+#    #+#             */
/*   Updated: 2025/04/14 21:45:23 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

long	ft_printf(const char *str, ...);
void	ft_putchar_len(char c, int long *len);
void	ft_putstr(char *str, int long *len);
void	ft_putnbr(long n, long *len);
void	ft_putpointer(size_t ptr, long *len);
void	ft_puthex(unsigned int x, long *len, char c);
void	ft_putunsigned_int(unsigned int n, long *len);

#endif
