/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilopes <vilopes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:06:12 by vilopes           #+#    #+#             */
/*   Updated: 2024/11/20 21:26:20 by vilopes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIB_H 
# define PRINTFLIB_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void    ft_putchar(char c);
int     ft_putstr(char *str);
int     ft_putnumber(int num);
char    *ft_itoa(int n);
int     ft_strlen(const char *str);

#endif