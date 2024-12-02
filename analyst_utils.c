/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:14 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:17 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *stack, int len)
{
	int	i;
	int j;

	i = 0;
	j = 1;
	while (j < len)
	{
		if (stack[i] >= stack[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}