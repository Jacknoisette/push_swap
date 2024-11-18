/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:13:18 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:18:24 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunnbr_n(unsigned int n)
{
	unsigned int	i;
	char			c;

	i = 0;
	if (n >= 10)
		i += ft_putunnbr_n(n / 10);
	i ++;
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (i);
}

/*
int main(void)
{
    int i;

    i = ft_putunnbr_n(1400);
    printf("\n%d\n", i);
}
*/
