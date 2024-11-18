/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:11:47 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:15:27 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_string(char chr, va_list args)
{
	int	count;

	count = 0;
	if (chr == 'c')
		count = ft_putchar_n(va_arg(args, int));
	else if (chr == 's')
		count = ft_putstr_n(va_arg(args, char *));
	else if (chr == 'd' || chr == 'i')
		count = ft_putnbr_n(va_arg(args, int));
	else if (chr == 'u')
		count = ft_putunnbr_n(va_arg(args, unsigned int));
	else if (chr == '%')
		count = ft_putchar_n('%');
	else if (chr == 'x')
		count = ft_puthexamin_n(va_arg(args, unsigned int));
	else if (chr == 'X')
		count = ft_puthexamaj_n(va_arg(args, unsigned int));
	else if (chr == 'p')
		count = ft_putp_n(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%' )
		{
			count += check_string(string[i + 1], args);
			i++;
		}
		else
			count += ft_putchar_n(string[i]);
		i++;
	}
	va_end(args);
	return (count);
}
