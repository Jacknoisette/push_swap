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

int	check_sort(t_stack *stack, int len, int start)
{
	int	i;
	int j;

	i = start;
	j = start + 1;
	while (j < len)
	{
		if (stack->list[i] >= stack->list[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

int	check_little(t_stack *stack, int len, int start)
{
	int	i;
	int j;

	i = start;
	j = start;
	while (j < len)
	{
		if (stack->list[i] > stack->list[j])
			i = j;
		j++;
	}
	return (i);
}

int	check_seclittle(t_stack *stack, int len, int start)
{
	int	i;
	int j;
	int sec;

	sec = start;
	i = start;
	j = start;
	while (j < len)
	{
		if (stack->list[i] > stack->list[j])
			i = j;
		if ((stack->list[sec] > stack->list[j]) && (i != j)) 
			sec = j;
		if ((stack->list[sec] > stack->list[j]) && (i == j)
			&& stack->list[sec] > stack->list[j - 1]) 
			sec = i - 1;
		j++;
	}
	return (sec);
}

int	check_big(t_stack *stack, int len, int start)
{
	int	i;
	int j;

	i = start;
	j = start + 1;
	while (j < len)
	{
		if (stack->list[i] <= stack->list[j])
			i = j;
		j++;
	}
	return (i);
}
		
// ft_printf("i : %i, j : %i, sec : %i, sl[i] : %i. sl[j] : %i\n", i, j, sec, stack->list[i], stack->list[j]);