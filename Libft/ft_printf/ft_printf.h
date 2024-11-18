/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:15:34 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:15:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *string, ...);
int	ft_puthexamaj_n(unsigned int n);
int	ft_puthexamin_n(unsigned int n);
int	ft_putchar_n(char c);
int	ft_putstr_n(char *str);
int	ft_putunnbr_n(unsigned int n);
int	ft_putnbr_n(int n);
int	ft_putp_n(void *n);

#endif
