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
void swap(t_stack *stack, int maxlen)
{
    int temp;
    int dif;

    if (stack->len < 2)
		return ;
    dif = maxlen - stack->len;
    temp = stack->list[dif];
    stack->list[dif] = stack->list[dif + 1];
    stack->list[dif + 1] = temp;
}