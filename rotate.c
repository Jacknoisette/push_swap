/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:45 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:46 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate 1 <- 2
void	rotate(t_stack *stack, int maxlen)
{
	int	i;
	int temp;
	int	dif;

	if (stack->len < 2)
		return ;
	dif = maxlen - stack->len;
	i = 0;
	temp = stack->list[dif];
	while (i < maxlen)
	{
		stack->list[i] = stack->list[i + 1];
		i++;
	}
	stack->list[maxlen - 1] = temp;
}

void	rrotate(t_stack *stack_1, t_stack *stack_2, int maxlen)
{
	rotate(stack_1, maxlen);
	rotate(stack_2, maxlen);
}





// void	rrotate(t_stack *stack_1, t_stack *stack_2, int maxlen)
// {
// 	int	i;

// }