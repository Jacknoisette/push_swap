/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push,c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42,fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:35 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//stack_1 <- stack_2
void	push(t_stack *stack_1, t_stack *stack_2, int maxlen)
{
	int	dif1;
	int	dif2;
	
	if (stack_2->len <= 0)
		return ;
	dif1 = maxlen - stack_1->len - 1;
	dif2 = maxlen - stack_2->len;
	stack_1->list[dif1] = stack_2->list[dif2];
	stack_2->list[dif2] = '\0';
	stack_1->len += 1;
	stack_2->len -= 1;
}
