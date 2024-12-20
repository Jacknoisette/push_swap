/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quintuplet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:23:25 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 17:03:52 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quintuplet(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
	int	dif;

	dif = len - stack_a->len;
	if (check_sort(stack_a, len, dif))
		return (count);
	while (stack_a->len > 3)
	{
		if ((check_seclittle(stack_a, len, dif) == dif && stack_a->len > 4)
			|| check_little(stack_a, len, dif) == dif)
		{
			count += push(stack_b, stack_a, len);
			dif += 1;
		}
		else
			count += rotate(stack_a, len, 1);
	}
	count += triplet(stack_a, len, 0);
	count += push(stack_a, stack_b, len);
	dif -= 1;
	count += push(stack_a, stack_b, len);
	dif -= 1;
	if (check_little(stack_a, len, dif) != dif)
		swap(stack_a, len, 1);
	return (count);
}
