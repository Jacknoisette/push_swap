/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:29:26 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/19 12:51:48 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int median(t_stack *temp_chunk)
{
	int median;

	median = temp_chunk->list[temp_chunk->len / 2];
	return (median);
}

t_stack	tempchunk_alloc(t_stack *stack, int len)
{
	t_stack	temp_chunk;
	int		i;

	i = 0;
	temp_chunk.list = malloc((len + 1) * sizeof(int));
	if (temp_chunk.list == NULL)
		return (ft_printf("Error\n"), temp_chunk);
	temp_chunk.len = len;
	temp_chunk.letter = 't';
	while (i < len)
	{
		temp_chunk.list[i] = stack->list[i];
		i++;
	}
	temp_chunk.list[i] = '\0';
	return (temp_chunk);
}

t_chunk	chunks_alloc(t_stack *temp_chunk)
{
	t_chunk	chunks;
	t_stack	schunk;

	chunks.len = temp_chunk->len;
	schunk = tempchunk_alloc(temp_chunk, chunks.len);
	chunks.chunks = schunk;
	if (schunk.list == NULL)
		return (ft_printf("Error\n"), chunks);
	return (chunks);
}

int	tempchunk_sort(t_stack *temp_chunk, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < temp_chunk->len && !check_sort(temp_chunk, len, 0))
	{
		j = 1;
		while (j < temp_chunk->len)
		{
			if (temp_chunk->list[j - 1] > temp_chunk->list[j])
			{
				temp = temp_chunk->list[j - 1];
				temp_chunk->list[j - 1] = temp_chunk->list[j];
				temp_chunk->list[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	chunk_sort(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
	t_stack	temp_chunk;
	t_chunk	chunks;

	temp_chunk = tempchunk_alloc(stack_a, stack_a->len);
	if (temp_chunk.list == NULL)
		return (free(temp_chunk.list), -1);
	tempchunk_sort(&temp_chunk, len);
	chunks = chunks_alloc(&temp_chunk);
	if (chunks.chunks.list == NULL)
		return (free(chunks.chunks.list), -1);
	chunks.min = stack_a->list[check_little(stack_a, stack_a->len, 0)];
	chunks.max = stack_a->list[check_big(stack_a, stack_a->len, 0)];
	chunks.median = median(&temp_chunk);
	chunks.maxlen = temp_chunk.len;
	free(temp_chunk.list);
	count += turkey_sort(stack_a, stack_b, &chunks, 0);
	return (count);
}
