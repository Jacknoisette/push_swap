/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:24:46 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/16 15:47:24 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	posrotation(t_stack *stack_a, t_stack *stack_b, t_pos *pos, int count)
{
	int	difa;
	int difb;

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
		if (pos->pos >= stack_b->len)
   			pos->pos = difb;
		if (pos->pos < difb)
			pos->pos = stack_b->len;
		pos->numb++;
	}
	return (count);
}

int	checkpos(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
	t_pos	pos;
	int	difa;
	int difb;

	difa = len - stack_a->len;
	difb = len - stack_b->len;
	pos.pos = difb + 1;
	pos.maxlen = len;
	while (pos.pos < stack_b->len && !(stack_a->list[difa] < 
		stack_b->list[pos.pos + 1] && stack_a->list[difa] >
		stack_b->list[pos.pos]))
		pos.pos++;
	ft_printf("pos : %i\n", pos.pos - difb);
	pos.numb = 0;
	count += posrotation(stack_a, stack_b, &pos, 0);
	count += push(stack_b, stack_a, len);
	while (pos.numb > 0)
	{
		if (pos.rot == 'r')
			count += reverse_rotate(stack_b, len, 1);
		else if (pos.rot == 'v')
			count += rotate(stack_b, len, 1);
		pos.numb--;
	}
	return (count);
}

int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
	int	difa;
	int difb;
	int big;
	int	small;

	difa = len - stack_a->len;
	difb = len - stack_b->len;
	if (stack_b->len == 0)
		return (count += push(stack_b, stack_a, len), count);
	if (stack_b->len == 1 && stack_b->list[difb] > stack_a->list[difa])
		return (count += push(stack_b, stack_a, len), 
			count += rotate(stack_b, len, 1), count);
	big = difb;
	while (stack_a->list[difa] > stack_b->list[big])
		big++;
	small = difb;
	while (stack_a->list[difa] < stack_b->list[small])
		small++;
	if (small == difb)
		return (count += push(stack_b, stack_a, len), count);
	if (big == difb && small == len)
	{
		return (count += push(stack_b, stack_a, len),
			count += rotate(stack_b, len, 1), count);
	}
	count += checkpos(stack_a, stack_b, len, 0);
	return (count);
}

int	found_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, int i)
{
	int	j;
	int	k;
	int	dif;
	int count;
	int	stack_len;

	count = 0;
	j = 0;
	stack_len = stack_a->len;
	chunks->found = 0;
	while (j < stack_len && chunks->found < chunks->chunks[i].len)
	{
		dif = chunks->maxlen - stack_a->len;
		k = 0;
		while (k < chunks->chunks[i].len && 
			stack_a->list[dif] !=  chunks->chunks[i].list[k])
		{
			if (stack_a->list[dif] == chunks->chunks[i].list[k])
				break ;
			k++;
		}
		if (stack_a->list[dif] == chunks->chunks[i].list[k])
		{
			ft_printf("________________________\n");
			printf_all(*stack_a, *stack_b, chunks->maxlen, count);
			count += sort_stack_b(stack_a, stack_b, chunks->maxlen, 0);
			printf_all(*stack_a, *stack_b, chunks->maxlen, count);
			ft_printf("________________________\n\n");
			chunks->found ++;
		}
		else
			count += rotate(stack_a, chunks->maxlen, 1);
		j++;
	}
	return (count);
}

int turkey_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, int count)
{
	int i;

	i = 0;
	while (i < chunks->chunks_count)
	{
		count += found_chunk(stack_a, stack_b, chunks, i);
		i++;
	}
	i = 0;
	while (stack_b->len > 0)
		count += push(stack_a, stack_b, chunks->maxlen);
	return (count);
}
