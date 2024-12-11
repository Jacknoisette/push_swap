/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:50 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:52 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate 1 -> 2
int	reverse_rotate(t_stack *stack, int maxlen, int print)
{
	int	i;
	int temp;
	int	dif;

	if (print)
		ft_printf("rr%c\n", stack->letter);
	if (stack->len < 2)
		return (1);
	dif = maxlen - stack->len;
	i = maxlen - 1;
	temp = stack->list[maxlen - 1];
	while (i > dif)
	{
		stack->list[i] = stack->list[i - 1];
		i--;
	}
	stack->list[dif] = temp;
	return (1);
}

//rotate 1 -> 2
int	rreverse_rotate(t_stack *stack_1, t_stack *stack_2, int maxlen)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_1, maxlen, 0);
	reverse_rotate(stack_2, maxlen, 0);
	return (1);
}