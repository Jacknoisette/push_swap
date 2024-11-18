/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:14:10 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:15:55 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_n(char c)
{
	write(1, &c, 1);
	return (1);
}

// int	main(void)
// {
// 	char st = 'h';
// 	printf("%d\n", ft_putchar_n(st));
// }