/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:12:25 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 18:21:15 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_check	check_short(t_stack *stack_a, t_stack *stack_b,
		t_chunk *chunks, t_info data)
{
	t_optirot	op;
	t_check		actual;
	t_v			v;

	v.difa = chunks->maxlen - stack_a->len;
	v.difb = chunks->maxlen - stack_b->len;
	v.i = 0;
	actual.index = 0;
	actual.value = INT_MAX;
	while (stack_b->len > v.i)
	{
		op.pos_in_b = v.i;
		data.actual = v.difb + v.i;
		data.big = v.difa;
		find_neighbors(stack_a, stack_b, &data, chunks->chunks);
		op.target_pos_in_a = data.big - v.difa;
		optimize_rotate(&op, stack_a, stack_b);
		if (actual.value > op.total_moves)
			actualize(&actual, op, v, data);
		v.i++;
	}
	return (actual);
}

int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks)
{
	t_short	s;

	s.count = 0;
	while (stack_b->len > 0)
	{
		s.v.difb = chunks->maxlen - stack_b->len;
		s.v.difa = chunks->maxlen - stack_a->len;
		s.data.len = stack_a->len;
		s.shorter = check_short(stack_a, stack_b, chunks, s.data);
		rot_value(&s, stack_a, stack_b);
		s.count += do_rot(&s, stack_a, stack_b, chunks->maxlen);
		s.count += push(stack_a, stack_b, chunks->maxlen);
	}
	if (stack_a->list[stack_a->len / 2] < chunks->median)
		s.v.n = 1;
	else
		s.v.n = 0;
	while (!check_sort(stack_a, stack_a->len, 0))
	{
		if (s.v.n)
			s.count += rotate(stack_a, chunks->maxlen, 1);
		else
			s.count += reverse_rotate(stack_a, chunks->maxlen, 1);
	}
	return (s.count);
}

int	found_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks)
{
	int	dif;
	int	count;

	count = 0;
	dif = chunks->maxlen - stack_b->len;
	count += sort_stack_b(stack_a, stack_b, chunks);
	return (count);
}

int	median_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, int count)
{
	int	i;
	int	difa;
	int	difb;

	i = 0;
	while (i < chunks->maxlen)
	{
		difa = chunks->maxlen - stack_a->len;
		difb = chunks->maxlen - stack_b->len;
		if (stack_a->list[difa] == chunks->median
			|| stack_a->list[difa] == chunks->min
			|| stack_a->list[difa] == chunks->max)
			count += rotate(stack_a, chunks->maxlen, 1);
		else if (stack_a->list[difa] > chunks->median)
		{
			count += push(stack_b, stack_a, chunks->maxlen);
			count += rotate(stack_b, chunks->maxlen, 1);
		}
		else if (stack_a->list[difa] < chunks->median)
			count += push(stack_b, stack_a, chunks->maxlen);
		i++;
	}
	return (count);
}

int	turkey_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, int count)
{
	count += median_sort(stack_a, stack_b, chunks, 0);
	count += triplet(stack_a, chunks->maxlen, 0);
	count += found_chunk(stack_a, stack_b, chunks);
	return (count);
}
