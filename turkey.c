/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:12:25 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/18 15:41:49 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	posrotation(t_stack *stack_a, t_stack *stack_b, t_pos *pos, int count)
{
	int	difa;
	int	difb;

	difa = pos->maxlen - stack_a->len;
	difb = pos->maxlen - stack_b->len;
	while (pos->pos != difb)
	{
		if ((pos->pos - difb) <= (stack_b->len / 2))
		{
			count += rotate(stack_b, pos->maxlen, 1);
			pos->pos--;
			pos->rot = 'r';
		}
		else
		{
			count += reverse_rotate(stack_b, pos->maxlen, 1);
			pos->pos++;
			pos->rot = 'v';
		}
		if (pos->pos > stack_b->len)
			pos->pos = difb;
		if (pos->pos < difb)
			pos->pos = difb + 1;
		pos->numb++;
	}
	return (count);
}

int	checkpos(t_stack *stack_a, t_stack *stack_b, int len, t_info data)
{
	t_pos	pos;
	int		difa;
	int		difb;

	data.count = 0;
	difa = len - stack_a->len;
	difb = len - stack_b->len;
	pos.pos = data.small;
	pos.maxlen = len;
	// if (data.small == difb)
	// 	return (ft_printf("2\n"), data.count += push(stack_b, stack_a, len),
	// 		data.count += rotate(stack_b, len, 1), data.count);;
	ft_printf("pos : %i\n", pos.pos - difb);
	pos.numb = 1;
	data.count += posrotation(stack_a, stack_b, &pos, 0);
	data.count += push(stack_b, stack_a, len);
	difb = len - stack_b->len;
	while (pos.numb > 0)
	{
		if (pos.rot == 'r')
			data.count += reverse_rotate(stack_b, len, 1);
		else if (pos.rot == 'v')
			data.count += rotate(stack_b, len, 1);
		pos.numb--;
	}
	return (data.count);
}

int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, int len, t_stack chunk)
{
	int	difa;
	int	difb;
	int count;
	t_info data;

	count = 0;
	difa = len - stack_a->len;
	difb = len - stack_b->len;
	ft_printf("12\n");
	if (stack_b->len == 0)
		return (count += push(stack_b, stack_a, len), count);
	if (stack_b->len == 1 && stack_b->list[difb] > stack_a->list[difa])
		return (count += push(stack_b, stack_a, len),
			count += rotate(stack_b, len, 1), count);
	// if (stack_b->len == 2 && stack_b->list[difb] > stack_a->list[difa] 
	// 	&& stack_b->list[difb + 1] > stack_a->list[difa])
	// 	return (count += reverse_rotate(stack_b, len, 1),
	// 		count += push(stack_b, stack_a, len),
	// 		count += rotate(stack_b, len, 1), count);
	data.len = len;
	count += find_neighbors(stack_a, stack_b, &data, chunk);
	// ft_printf("small %i, len %i\n", data.small - difb, stack_b->len);
	if (data.small - difb == stack_b->len)
		return (count += push(stack_b, stack_a, len),
			count += rotate(stack_b, len, 1), count);
	if (data.stop == 0)
		count += checkpos(stack_a, stack_b, len, data);
	// difb = len - stack_b->len;
	// if (stack_b->list[difb] < stack_b->list[stack_b->len])
	// 	return (count += reverse_rotate(stack_b, len, 1),
	// 		count += swap(stack_b, len, 1),
	// 		count += rotate(stack_b, len, 1), count);
	return (count);
}

int	found_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks)
{
	int	j;
	int	k;
	int	dif;
	int	count;
	int	stack_len;

	count = 0;
	j = 0;
	stack_len = stack_a->len;
	chunks->found = 0;
	while (j < stack_len && chunks->found < chunks->chunks.len)
	{
		dif = chunks->maxlen - stack_a->len;
		k = 0;
		while (k < chunks->chunks.len
			&& stack_a->list[dif] != chunks->chunks.list[k])
			k++;
		if (k < chunks->chunks.len)
		{
			ft_printf("________________________\n");
			printf_all(*stack_a, *stack_b, chunks->maxlen, count);
			count += sort_stack_b(stack_a, stack_b, 
				chunks->maxlen, chunks->chunks);
			printf_all(*stack_a, *stack_b, chunks->maxlen, count);
			ft_printf("________________________\n\n");
			chunks->found++;
		}
		else
		{
			if (chunks->rot == 'r')
				count += rotate(stack_a, chunks->maxlen, 1);
			else
				count += reverse_rotate(stack_a, chunks->maxlen, 1);
		}
		j++;
	}
	return (count);
}

int	turkey_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, int count)
{
	ft_printf("TURKEY\n");
	if (shortcut_rot(stack_a, chunks) <= stack_a->len / 2)
		chunks->rot = 'v';
	else
		chunks->rot = 'r';
	count += found_chunk(stack_a, stack_b, chunks);
	while (stack_b->len > 0)
		count += push(stack_a, stack_b, chunks->maxlen);
	return (count);
}
