/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triplet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:07:08 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/17 12:19:29 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	triplet(t_stack *stack, int len, int count)
{
	int	dif;
	int	mid;
	int	end;

	ft_printf("TRIPLET\n");
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
