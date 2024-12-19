/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 09:29:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/19 18:18:05 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	shortcut_rot(t_stack *stack_a, t_chunk *chunks)
// {
// 	int	j;
// 	int	stack_len;
// 	int	middle;
// 	int	numb;

// 	j = chunks->maxlen - stack_a->len;
// 	stack_len = stack_a->len;
// 	middle = 0;
// 	numb = 0;
// 	while (j < stack_len && chunks->found < chunks->chunks.len)
// 	{
// 		// k = 0;
// 		// while (k < chunks->chunks.len && stack_a->list[j]
// 		// 	!= chunks->chunks.list[k])
// 		// 	k++;
// 		if (stack_a->list[j] == chunks->chunks.list[k])
// 		{
// 			middle += j;
// 			numb += 1;
// 		}
// 		j++;
// 	}
// 	if (middle == 0 || numb == 0)
// 		return (0);
// 	return (middle /= numb, middle);
// }

// int	find_neighbors(t_stack *stack_a, t_stack *stack_b, t_info *data)
// {
// 	int	difb;
// 	int	difa;
// 	int	count;
	
// 	count = 0;
// 	data->stop = 1;
// 	difa = data->len - stack_a->len;
// 	difb = data->len - stack_b->len;
// 	if (stack_b->len == 0)
// 		return (count);
// 	data->big = difb;
// 	while (data->big < stack_b->len 
// 		&& stack_a->list[difa] > stack_b->list[data->big])
// 		data->big++;
// 	data->small = difb;
// 	while (data->small < stack_b->len 
// 		&& stack_a->list[difa] < stack_b->list[data->small])
// 		data->small++;
// 	ft_printf("big : %i\nsmall : %i\n", data->big - difb, data->small -difb);
// 	if (data->big == difb && data->small == data->len)
// 		return (ft_printf("1\n"), count += push(stack_b, stack_a, data->len), count);
// 	if (data->small == difb)
// 		return (ft_printf("2\n"),count += push(stack_b, stack_a, data->len),
// 			count += rotate(stack_b, data->len, 1), count);
// 	if (data->big == difb && data->small == difb + 1)
// 		return (ft_printf("3\n"),count += push(stack_b, stack_a, data->len),
// 			count += swap(stack_b, data->len, 1), count);
// 	data->stop = 0;
// 	return (count);
// }

// int	find_neighbors(t_stack *stack_a, t_stack *stack_b, t_info *data, t_stack chunks)
// {
// 	int	difb;
// 	int	difa;
// 	int	count;
// 	int	i;
// 	int	j;
	
// 	count = 0;
// 	data->stop = 1;
// 	difa = data->len - stack_a->len;
// 	difb = data->len - stack_b->len;
// 	if (stack_b->len == 0)
// 		return (count);
// 	i = 0;
// 	while (chunks.list[i] != stack_a->list[difa])
// 		i++;
// 	// ft_printf("chunks.list[i] : %i\n", chunks.list[i]);
// 	j = i + 1;
// 	while (1)
// 	{
// 		data->big = difb;
// 		while (j < chunks.len && data->big <= data->len
// 			&& chunks.list[j] < stack_b->list[data->big])
// 		{
// 			// ft_printf("big : chunks.list[j] : %i ||", chunks.list[j]);
// 			// ft_printf(" stack_b->list[data->big] : %i\n", stack_b->list[data->big]);
// 			data->big++;
// 		}
// 		if (chunks.list[j] == stack_b->list[data->big])
// 			break ;
// 		if (j == chunks.len)
// 		{
// 			data->big = difb;
// 			break;
// 		}
// 		j++;
// 	}
// 	// ft_printf("big : chunks.list[j] : %i ||", chunks.list[j]);
// 	// ft_printf(" stack_b->list[data->big] : %i\n", stack_b->list[data->small]);
// 	j = i - 1;
// 	// ft_printf("chunks.list[j] : %i\n", chunks.list[j]);
// 	while (1)
// 	{
// 		data->small = difb;
// 		while (j >= 0 && data->small <= data->len
// 			&& chunks.list[j] < stack_b->list[data->small])
// 		{
// 			// ft_printf("small : chunks.list[j] : %i ||", chunks.list[j]);
// 			// ft_printf(" stack_b->list[data->small] : %i\n", stack_b->list[data->small]);
// 			data->small++;
// 		}
// 		if (chunks.list[j] == stack_b->list[data->small])
// 			break ;
// 		if (j < 0)
// 		{
// 			data->small = difb;
// 			// ft_printf("%i < 0\n", j);
// 			break;
// 		}
// 		j--;
// 	}
// 	// ft_printf("small : chunks.list[j] : %i ||", chunks.list[j]);
// 	// ft_printf(" stack_b->list[data->small] : %i\n", stack_b->list[data->small]);
// 	// ft_printf("big : %i\nsmall : %i\n", data->big - difb, data->small -difb);
// 	if (data->big == difb && data->small == difb)
// 		return (ft_printf("1\n"), count += push(stack_b, stack_a, data->len), count);
// 	if (data->big == difb && data->small == data->len)
// 		return (ft_printf("1\n"), count += push(stack_b, stack_a, data->len), count);
// 	if (data->small == difb)
// 		return (ft_printf("2\n"),count += push(stack_b, stack_a, data->len),
// 			count += rotate(stack_b, data->len, 1), count);;
// 	if (data->big == difb && data->small == difb + 1)
// 		return (ft_printf("3\n"),count += push(stack_b, stack_a, data->len),
// 			count += swap(stack_b, data->len, 1), count);
// 	data->stop = 0;
// 	return (count);
// }

int	find_neighbors(t_stack *stack_a, t_stack *stack_b, t_info *data, t_stack chunks)
{
	int	i;
	int	j;

	i = 0;
	// ft_printf("big : %i\nsmall : %i\n", data->big - (chunks.len - stack_a->len), data->small - (chunks.len - stack_a->len));
	// ft_printf("chunks.len %i\n", chunks.len);
	while (i < chunks.len && chunks.list[i] < stack_b->list[data->actual])
		i++;
	j = i + 1;
	// ft_printf("FIND_BIG for %i\n", stack_b->list[data->actual]);
	while (data->big - (chunks.len - stack_a->len) < stack_a->len)
	{
		// ft_printf("COND 1 : j < chunks.len : %i because j = %i and chunks.len = %i\n", j < chunks.len, j, chunks.len);
		// ft_printf("COND 2 :data->big < stack_a->len : %i because big = %i and stacklen = %i\n", data->big < stack_a->len, data->big, stack_a->len);
		// ft_printf("COND 3 :chunks.list[j] < stack_a->list[data->big] : %i because chunklistj = %i && stack list = %i\n", chunks.list[j] < stack_a->list[data->big], chunks.list[j], stack_a->list[data->big]);
		// ft_printf("big %i, stacklen %i, j %i\n\n", data->big  - (chunks.len - stack_a->len), stack_a->len, j);
		// data->big = chunks.len - stack_a->len;
		j = i + 1;
		while (j < chunks.len)
		{
		// 	ft_printf("big : chunks.list[j] : %i ||", chunks.list[j]);
		// 	ft_printf(" stack_b->list[data->big] : %i\n", stack_a->list[data->big]);
			// ft_printf("j : %i, big : %i\n", chunks.list[j],  stack_a->list[data->big]);
			if (chunks.list[j] == stack_a->list[data->big])
				break ;
			j++;
		}
		if (chunks.list[j] == stack_a->list[data->big])
				break ;
		data->big++;
		// ft_printf("big : %i -> %i\n", data->big - (chunks.len - stack_a->len), stack_a->len);
	}
	// ft_printf("________\n\n");
	// ft_printf("big : chunks.list[j] : %i ||", chunks.list[j]);
	// ft_printf(" stack_b->list[data->big] : %i\n", stack_b->list[data->small]);
	j = i - 1;
	// ft_printf("chunks.list[j] : %i\n", chunks.list[j]);
	while (j)
	{
		while (j >= 0 && data->small - (chunks.len - stack_a->len) 
			< stack_a->len && chunks.list[j] > stack_a->list[data->small])
		{
			// ft_printf("small : chunks.list[j] : %i ||", chunks.list[j]);
			// ft_printf(" stack_b->list[data->small] : %i\n", stack_b->list[data->small]);
			data->small++;
		}
		if (chunks.list[j] == stack_a->list[data->small])
			break ;
		if (j < 0)
		{
			data->small = chunks.len - stack_a->len;
			// ft_printf("%i < 0\n", j);
			break;
		}
		j--;
	}
	// ft_printf("small : chunks.list[j] : %i ||", chunks.list[j]);
	// ft_printf(" stack_b->list[data->small] : %i\n", stack_b->list[data->small]);
	// ft_printf("big : %i\nsmall : %i\n", data->big - (chunks.len - stack_a->len), data->small - (chunks.len - stack_a->len));
	return (0);
}
