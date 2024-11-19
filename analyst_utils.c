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

int	intlen(int *stack)
{
	int i;

	i = 0;
	while (stack[i] != '\0')
		i++;
	return (i);
}

t_bint	*build_bint(int *stack, int intlen, int exist)
{
	t_bint	*bint_list;
	int	i;

	i = 0;
	bint_list = malloc((intlen + 1) * sizeof(t_bint));
	while (i < intlen)
	{
		if (exist == 0)
			bint_list[i].value = stack[i];
		else
			bint_list[i].value = 0;
		bint_list[i].null_check = exist;
		i++;
	}
	bint_list[i].value = '\0';
	bint_list[i].null_check = '\0';
	return (bint_list);
}

int	*build_int(int *stack, t_bint **bint_list, int intlen)
{
	int	i;

	i = 0;
	while (i < intlen)
	{
		stack[i] = (*bint_list)[i].value;
		i++;
	}
	return (free(*bint_list), stack);
}