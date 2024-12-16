/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:23:31 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/16 12:30:02 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	triplet(t_stack *stack, int len, int count)
{
	int dif;
    int mid;
    int end;

	dif = stack->list[len - stack->len];
	mid = stack->list[len - stack->len + 1];
	end = stack->list[len - stack->len + 2];
	if (dif > mid && mid < end && end > dif)
        count += swap(stack, len, 1);
    else if (dif > mid && mid > end)
    {
        count += swap(stack, len, 1);
        count += reverse_rotate(stack, len, 1);
    }
    else if (dif > mid && mid < end && end < dif)
        count += rotate(stack, len, 1);
    else if (dif < mid && mid > end && end > dif)
    {
        count += swap(stack, len, 1);
        count += rotate(stack, len, 1);
    }
    else if (dif < mid && mid > end && end < dif)
		count += reverse_rotate(stack, len, 1);
	return (count);
}

int	revtriplet(t_stack *stack, int len, int count)
{
	int dif;
    int mid;
    int end;

	dif = stack->list[len - stack->len];
	mid = stack->list[len - stack->len + 1];
	end = stack->list[len - stack->len + 2];
	if (dif < mid && mid > end && end < dif)
        count += swap(stack, len, 1);
    else if (dif < mid && mid < end)
    {
        count += swap(stack, len, 1);
        count += reverse_rotate(stack, len, 1);
    }
    else if (dif < mid && mid > end && end > dif)
        count += rotate(stack, len, 1);
    else if (dif > mid && mid < end && end < dif)
    {
        count += swap(stack, len, 1);
        count += rotate(stack, len, 1);
    }
    else if (dif > mid && mid < end && end > dif)
		count += reverse_rotate(stack, len, 1);
	return (count);
}

	// if (!check_sort(stack, 3))
	// {
	// 	if (check_sort(stack, 2))
	// 	{
	// 		if (check_little(stack, 3) == 0)
	// 		{
	// 			count += rotate(stack, len, 1);
	// 			count += swap(stack, len, 1);
	// 		}
	// 		count += reverse_rotate(stack, len, 1);
	// 		return (count);
	// 	}
	// 	if (check_little(stack, 3) == 1)
	// 	{
	// 		if (check_big(stack, 3) == 0)
	// 			count += rotate(stack, len, 1);
	// 		else if (check_big(stack, 3) == 2)
	// 			count += swap(stack, len, 1);
	// 		return (count);
	// 	}
	// 	count += rotate(stack, len, 1);
	// 	count += swap(stack, len, 1);
	// 	return (count);
	// }