/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:49:51 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 18:17:06 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_value(t_short *s, t_stack *stack_a, t_stack *stack_b)
{
	if (s->shorter.rotb)
		s->r_count.rotb_count = s->shorter.index;
	else
		s->r_count.rotb_count = stack_b->len - s->shorter.index;
	if (s->shorter.rota)
		s->r_count.rota_count = s->shorter.big - s->v.difa;
	else
		s->r_count.rota_count = stack_a->len - (s->shorter.big - s->v.difa);
}

int	do_rot(t_short *s, t_stack *stack_a, t_stack *stack_b, int len)
{
	int	count;

	count = 0;
	while (s->r_count.rotb_count > 0)
	{
		if (s->shorter.rotb)
			count += rotate(stack_b, len, 1);
		else
			count += reverse_rotate(stack_b, len, 1);
		s->r_count.rotb_count--;
	}
	while (s->r_count.rota_count > 0)
	{
		if (s->shorter.rota)
			count += rotate(stack_a, len, 1);
		else
			count += reverse_rotate(stack_a, len, 1);
		s->r_count.rota_count--;
	}
	return (count);
}

void	optimize_rotate(t_optirot *op, t_stack *stack_a, t_stack *stack_b)
{
	if (op->pos_in_b <= stack_b->len / 2)
	{
		op->total_moves = op->pos_in_b;
		op->rotb = 1;
	}
	else
	{
		op->total_moves = stack_b->len - op->pos_in_b;
		op->rotb = 0;
	}
	if (op->target_pos_in_a <= stack_a->len / 2)
	{
		op->total_moves += op->target_pos_in_a;
		op->rota = 1;
	}
	else
	{
		op->total_moves += stack_a->len - op->target_pos_in_a;
		op->rota = 0;
	}
}

void	actualize(t_check *actual, t_optirot op, t_v v, t_info data)
{
	actual->index = v.i;
	actual->value = op.total_moves;
	actual->big = data.big;
	actual->rota = op.rota;
	actual->rotb = op.rotb;
}
