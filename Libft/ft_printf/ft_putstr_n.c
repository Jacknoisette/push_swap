/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:12:39 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:18:36 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_n(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
	{
		return (ft_putstr_n("(null)"));
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	char *st = "hello";
	
	printf("%d\n", ft_putstr_n(st));
}
*/
