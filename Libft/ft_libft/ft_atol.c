/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:05:10 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 16:07:46 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

long	ft_atol(const char *nptr)
{
	long	n;
	int	i;
	int	s;

	i = 0;
	s = 0;
	n = 0;
	if ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
			i++;
	}
	if ((nptr[i] == '+' && ++s) || (nptr[i] == '-' && --s))
		i++;
	else
		s = 1;
	while ((nptr[i + 1] != '\0') && nptr[i] == '0')
		i++;
	if ((nptr[i] != '\0') && nptr[i] >= '0' && nptr[i] <= '9')
	{
		while ((nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9'))
		{
			n = (n * 10) + (nptr[i] - '0');
			i++;
		}
	}
	return (n *= s);
}

int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = " 12837628";
	printf("%d\n", ft_atoi(str1));
	printf("%d\n", atoi(str1));
	str2 = "    -1234500000000000";
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", atoi(str2));
	str3 = "  \n-12";
	printf("%d\n", ft_atoi(str3));
	printf("%d\n", atoi(str3));
}
