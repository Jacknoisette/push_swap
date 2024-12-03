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
void	reverse_rotate(t_stack *stack, int maxlen)
{
	int	i;
	int temp;
	int	dif;

	if (stack->len < 2)
		return ;
	dif = maxlen - stack->len;
	i = maxlen - 1;
	temp = stack->list[maxlen - 1];
	while (i > dif)
	{
		stack->list[i] = stack->list[i - 1];
		i--;
	}
	stack->list[dif] = temp;
}

void	rreverse_rotate(t_stack *stack_1, t_stack *stack_2, int maxlen)
{
	reverse_rotate(stack_1, maxlen);
	reverse_rotate(stack_2, maxlen);
}