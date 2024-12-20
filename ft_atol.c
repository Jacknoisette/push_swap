/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:05:10 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 16:56:48 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr, int *error, int i, int s)
{
	long	n;

	*error = 0;
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
	if ((nptr[i] != '\0') && nptr[i] >= '0' && nptr[i] <= '9')
	{
		while ((nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9'))
		{
			n = (n * 10) + (nptr[i] - '0');
			i++;
		}
	}
	if (((nptr[i] != '\0') && nptr[i] >= '0' && nptr[i] >= '9')
		|| nptr[i] == '-' || nptr[i] == '+' || nptr[i] == ',')
		*error = 1;
	return (n *= s);
}
