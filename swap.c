/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:57 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:58 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap 1 <-> 2
int swap(t_stack *stack, int maxlen, int print)
{
    int temp;
    int dif;

    if (print)
		ft_printf("s%c\n", stack->letter);
	if (stack->len < 2)
		return (1);
    dif = maxlen - stack->len;
    temp = stack->list[dif];
    stack->list[dif] = stack->list[dif + 1];
    stack->list[dif + 1] = temp;
	return (1);
}

//swap 1 <-> 2
int sswap(t_stack *stack_1, t_stack *stack_2, int maxlen)
{
	ft_printf("ss\n");
	swap(stack_1, maxlen, 0);
	swap(stack_2, maxlen, 0);
	return (1);
}