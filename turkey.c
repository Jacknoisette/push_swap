/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:12:25 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/19 18:33:21 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	posrotation(t_stack *stack_b, t_pos *pos, int count)
// {
// 	int	difb;
// 	int target_pos;
//     int current_pos;
//     int rotations_needed;

// 	difb = pos->maxlen - stack_b->len;
// 	target_pos = pos->pos;
// 	current_pos = difb;
// 	if (target_pos < current_pos)
//         rotations_needed = stack_b->len - (current_pos - target_pos);
//     else
// 	{
//         rotations_needed = target_pos - current_pos;
// 	}
// 	if ((pos->pos - difb) <= (stack_b->len / 2))
// 	{
// 		while (rotations_needed > 0)
// 		{
// 			count += rotate(stack_b, pos->maxlen, 1);
// 			rotations_needed--;
// 			pos->numb++;
// 			pos->rot = 'r';
// 		}
// 		pos->numb--;
// 	}
// 	else
// 	{
// 		rotations_needed = stack_b->len - rotations_needed;
// 		while (rotations_needed > 0)
// 		{
// 			count += reverse_rotate(stack_b, pos->maxlen, 1);
// 			rotations_needed--;
// 			pos->numb++;
// 			pos->rot = 'v';
// 		}
// 	}
// 	ft_printf("end of start posnumb : %i\n", pos->numb);
// 	return (count);
// }

// int	checkpos(t_stack *stack_a, t_stack *stack_b, int len, t_info data)
// {
// 	t_pos	pos;
// 	int		difb;

// 	difb = len - stack_b->len;
// 	pos.pos = data.small;
// 	pos.maxlen = len;
// 	data.count = 0;
// 	// if (data.small == difb)
// 	// 	return (ft_printf("2\n"), data.count += push(stack_b, stack_a, len),
// 	// 		data.count += rotate(stack_b, len, 1), data.count);;
// 	ft_printf("pos : %i\n", pos.pos - difb);
// 	pos.numb = 0;
// 	data.count += posrotation(stack_b, &pos, 0);
// 	data.count += push(stack_b, stack_a, len);
// 	difb = len - stack_b->len;
// 	while (pos.numb >= 0)
// 	{
// 		ft_printf("posnumb : %i\n", pos.numb);
// 		if (pos.rot == 'r')
// 			data.count += reverse_rotate(stack_b, len, 1);
// 		else if (pos.rot == 'v')
// 			data.count += rotate(stack_b, len, 1);
// 		pos.numb--;
// 	}
// 	return (data.count);
// }

t_check check_short(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, t_info data)
{
	int	i;
	t_check actual;
	int difa;
	int difb;
	int	n;

	difa = chunks->maxlen - stack_a->len;
	difb = chunks->maxlen - stack_b->len;
	i = 0;
	data.actual = difb;
	actual.index = 0;
	actual.value = INT_MAX;
	while (stack_b->len > i)
	{
		n = 0;
		ft_printf("data.actual : %i\n", stack_b->list[data.actual]);
		ft_printf("rot b /2 : %i\n", stack_b->len - (data.actual - difb));
		ft_printf("rot b : %i\n", (data.actual - difb));
		actual.rotb = (data.actual - difb) < stack_b->len / 2;
		if (actual.rotb)
			n += (data.actual - difb);
		else
			n += stack_b->len - (data.actual - difb);
		data.big = difa;
		data.small = difa;
		find_neighbors(stack_a, stack_b, &data, chunks->chunks);
		ft_printf("big %i\n", data.big - difa);
		ft_printf("rot a /2 : %i\n", (data.big  - difa) - 1);
		ft_printf("rot a: %i\n", stack_a->len - (data.big  - difa) + 1) ;
		actual.rota = (data.big - difa) < stack_a->len / 2;
		if (actual.rota) //here
			n += (data.big  - difa) - 1;
		else
			n += stack_a->len - (data.big  - difa) + 1;
		if (actual.value > n)
		{
			actual.index = (data.actual - difb);
			actual.value = n;
			actual.big = data.big;
		}
		i++;
		data.actual++;
	}
	return (actual);
}

int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks)
{
	t_check shorter;
	t_info 	data;
	int 	count;
	t_v		v;

	v.i = 0;
	count = 0;
	while (stack_b->len > 0)
	{
		v.difb = chunks->maxlen - stack_b->len;
		v.difa = chunks->maxlen - stack_a->len;
		data.len = stack_a->len;
		shorter = check_short(stack_a, stack_b, chunks, data);
		ft_printf("shorter : index %i rot value : %i so : %i\n", shorter.index, shorter.value, stack_b->list[chunks->maxlen - stack_b->len + shorter.index]);
		ft_printf("big %i\n", shorter.big - v.difa);
		v.i = v.difb;
		if (shorter.rotb)
		{
			while (v.i < shorter.index)
			{
				ft_printf("%i\n", shorter.index);
				ft_printf("%i\n", v.i);
				count += reverse_rotate(stack_b, chunks->maxlen, 1);
				v.i++;
			}
		}
		else
		{
			while (v.i < stack_a->len - shorter.index)
			{
				ft_printf("%i\n", shorter.index);
				ft_printf("%i\n", v.i);
				count += rotate(stack_b, chunks->maxlen, 1);
				v.i++;
			}
		}
		count += push(stack_a, stack_b, chunks->maxlen);
		v.i = 0;
		if (shorter.rota)
		{
			while (v.i < shorter.big)
			{
				ft_printf("%i\n",shorter.big - v.difa);
				ft_printf("%i\n", v.i);
				count += reverse_rotate(stack_a, chunks->maxlen, 1);
				v.i++;
			}
		}
		else
		{
			while (v.i < stack_a->len - shorter.big)
			{
				ft_printf("%i\n", shorter.big);
				ft_printf("%i\n", v.i);
				count += rotate(stack_a, chunks->maxlen, 1);
				v.i++;
			}
		}
		printf_all(*stack_a, *stack_b, chunks->maxlen, count);
		v.j++;
	}
	return (count);
}

int	found_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks)
{
	int	dif;
	int	count;

	count = 0;
	// while (stack_b->len > 0)
	// {
		dif = chunks->maxlen - stack_b->len;
		ft_printf("________________________\n");
		printf_all(*stack_a, *stack_b, chunks->maxlen, count);
		count += sort_stack_b(stack_a, stack_b, chunks);
		printf_all(*stack_a, *stack_b, chunks->maxlen, count);
		ft_printf("________________________\n\n");
		// }
		// else
		// {
		// 	if (chunks->rot == 'r')
		// 		count += rotate(stack_a, chunks->maxlen, 1);
		// 	else
		// 		count += reverse_rotate(stack_a, chunks->maxlen, 1);
		// }
	// }
	return (count);
}

int median_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, int count)
{
	int	i;
	int difa;
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

	ft_printf("TURKEY\n");
	ft_printf("min : %i, median : %i, max : %i\n", chunks->min, chunks->median, chunks->max);
	count += median_sort(stack_a, stack_b, chunks, 0);
	count += triplet(stack_a, chunks->maxlen, 0);
	count += found_chunk(stack_a, stack_b, chunks);
	ft_printf("check_sort = %i\n", check_sort(stack_a, 3, chunks->maxlen - stack_a->len));
	printf_all(*stack_a, *stack_b, chunks->maxlen, count);
	// if (shortcut_rot(stack_a, chunks) <= stack_a->len / 2)
	// 	chunks->rot = 'v';
	// else
	// 	chunks->rot = 'r';
	// count += found_chunk(stack_a, stack_b, chunks);
	// while (stack_b->len > 0)
	// 	count += push(stack_a, stack_b, chunks->maxlen);
	return (count);
}
