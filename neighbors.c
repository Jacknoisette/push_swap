/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:29:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 17:35:41 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_neighbors(t_stack *stack_a, t_v *v, t_stack chunks, int num)
{
	v->j = v->i + 1;
	if (stack_a->list[v->k] > num)
	{
		while (v->j < chunks.len)
		{
			if (chunks.list[v->j] == stack_a->list[v->k])
				return (1);
			v->j++;
		}
	}
	return (0);
}

int	find_neighbors(t_stack *stack_a, t_stack *stack_b,
	t_info *data, t_stack chunks)
{
	int	smallest_bigger;
	int	valid_found;
	t_v	v;

	v.difa = chunks.len - stack_a->len;
	v.i = 0;
	while (v.i < chunks.len && chunks.list[v.i]
		< stack_b->list[data->actual])
		v.i++;
	if (v.i >= chunks.len)
		return (-1);
	smallest_bigger = INT_MAX;
	valid_found = 0;
	v.k = v.difa;
	while (v.k - v.difa < stack_a->len)
	{
		if (check_neighbors(stack_a, &v, chunks, stack_b->list[data->actual]))
		{
			valid_found = 1;
			if (stack_a->list[v.k] < smallest_bigger)
			{
				smallest_bigger = stack_a->list[v.k];
				data->big = v.k;
			}
		}
		v.k++;
	}
	if (!valid_found)
	{
		data->big = v.difa;
		return (-1);
	}
	return (0);
}
