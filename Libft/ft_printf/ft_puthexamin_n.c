/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamin_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:12:48 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:16:16 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexamin_n(unsigned int n)
{
	unsigned int	i;
	char			c;
	char			*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		i += ft_puthexamin_n(n / 16);
	i ++;
	c = (hex[n % 16]);
	write(1, &c, 1);
	return (i);
}

/*
int main(void)
{
    int i;

    i = ft_puthexamin_n(15);
    printf("\n%d\n", i);
}
*/
