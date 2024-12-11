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
int	rotate(t_stack *stack, int maxlen, int print)
{
	int	i;
	int temp;
	int	dif;

	if (print)
		ft_printf("r%c\n", stack->letter);
	if (stack->len < 2)
		return (1);
	dif = maxlen - stack->len;
	i = 0;
	temp = stack->list[dif];
	while (i < maxlen)
	{
		stack->list[i] = stack->list[i + 1];
		i++;
	}
	stack->list[maxlen - 1] = temp;
	return (1);
}

//rotate 1 <- 2
int	rrotate(t_stack *stack_1, t_stack *stack_2, int maxlen)
{
	ft_printf("rr\n");
	rotate(stack_1, maxlen, 0);
	rotate(stack_2, maxlen, 0);
	return (1);
}





// void	rrotate(t_stack *stack_1, t_stack *stack_2, int maxlen)
// {
// 	int	i;

// }