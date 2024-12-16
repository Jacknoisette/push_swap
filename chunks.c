/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:10:28 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/16 12:14:36 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **chunks)
{
	int	i;

	i = 0;
	while (chunks[i]->list != NULL)
	{
		free(chunks[i]->list);
		i++;
	}
	free(chunks);
}

t_stack	tempchunk_alloc(t_stack *stack, int len, int start)
{
	int	i;
	t_stack temp_chunk;

	i = 0;
	temp_chunk.list = malloc((len + 1) * sizeof(int));
	if (temp_chunk.list == NULL)
		return(ft_printf("Error\n"), temp_chunk);
	temp_chunk.len = len;
	temp_chunk.letter = 't';
	while (i < len && stack->list[start] != '\0')
	{
		temp_chunk.list[i] = stack->list[start];
		i++;
		start++;
	}
	temp_chunk.list[i] = '\0';
	return (temp_chunk);
}

t_chunk	chunks_alloc(t_stack *temp_chunk, int *error, int chunks_count)
{
	t_chunk	chunks;
	t_stack	schunk;
	int	i;
	int	j;

	chunks.len = temp_chunk->len / chunks_count;
	chunks.chunks = malloc(chunks.len * sizeof(t_stack));
	if (chunks.chunks == NULL)
		return (ft_printf("Error\n"), chunks);
	i = 0;
	j = 0;
	while (i < chunks.len)
	{
		if (i == 0 && temp_chunk->len % chunks_count != 0)
		{
			schunk = tempchunk_alloc(temp_chunk, 
				chunks.len + temp_chunk->len % chunks_count, j);
			j += temp_chunk->len % chunks_count;
		}
		else
			schunk = tempchunk_alloc(temp_chunk, chunks.len, j);
		chunks.chunks[i] = schunk;
		if (schunk.list == NULL)
			return (ft_printf("Error\n"), *error = i, chunks);
		i++;
		j += chunks.len;
	}
	return (chunks);
}

int	tempchunk_sort(t_stack *temp_chunk, int	len)
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
	t_stack temp_chunk;
	t_chunk	chunks;
	int	error;
	int chunks_count;

	temp_chunk = tempchunk_alloc(stack_a, stack_a->len, 0);
	if (temp_chunk.list == NULL)
		return (free(temp_chunk.list), -1);
	tempchunk_sort(&temp_chunk, len);
	error = 0;
	if (temp_chunk.len <= 50)
		chunks_count = 3;
	else if (temp_chunk.len <= 100)
		chunks_count = temp_chunk.len / 25;
	else if (temp_chunk.len <= 300)
		chunks_count = temp_chunk.len / 25;
	else if (temp_chunk.len <= 500)
		chunks_count = temp_chunk.len / 25;
	else
		chunks_count = temp_chunk.len / 30;
	chunks = chunks_alloc(&temp_chunk, &error, chunks_count);
	if (chunks.chunks == NULL)
		return (-1);
	if (chunks.chunks[error].list == NULL)
		return (free_all(&chunks.chunks), -1);
	chunks.maxlen = temp_chunk.len;
	chunks.chunks_count = chunks_count;
	free(temp_chunk.list);
	count += turkey_sort(stack_a, stack_b, &chunks, 0);
	return (count);
}
