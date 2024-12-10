/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:23:31 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/02 17:23:34 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	triplet(t_stack *stack, int len, int count)
{
	int top;
    int mid;
    int bot;

	top = stack->list[len - stack->len];
	mid = stack->list[len - stack->len + 1];
	bot = stack->list[len - stack->len + 2];
	if (top > mid && mid < bot && bot > top)
        count += swap(stack, len, 1);
    else if (top > mid && mid > bot)
    {
        count += swap(stack, len, 1);
        count += reverse_rotate(stack, len, 1);
    }
    else if (top > mid && mid < bot && bot < top)
        count += rotate(stack, len, 1);
    else if (top < mid && mid > bot && bot > top)
    {
        count += swap(stack, len, 1);
        count += rotate(stack, len, 1);
    }
    else if (top < mid && mid > bot && bot < top)
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