/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:12:25 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 15:25:41 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	posrotation(t_stack *stack_b, t_pos *pos, int count)
// {
// 	int	difb;
// 	int target_pos;
//     int current_pos;
//     int rotations_needed;

// 	difb = pos->maxlen - stack_b->len;
// 	target_pos = pos->pos;
// 	current_pos = difb;
// 	if (target_pos < current_pos)
//         rotations_needed = stack_b->len - (current_pos - target_pos);
//     else
// 	{
//         rotations_needed = target_pos - current_pos;
// 	}
// 	if ((pos->pos - difb) <= (stack_b->len / 2))
// 	{
// 		while (rotations_needed > 0)
// 		{
// 			count += rotate(stack_b, pos->maxlen, 1);
// 			rotations_needed--;
// 			pos->numb++;
// 			pos->rot = 'r';
// 		}
// 		pos->numb--;
// 	}
// 	else
// 	{
// 		rotations_needed = stack_b->len - rotations_needed;
// 		while (rotations_needed > 0)
// 		{
// 			count += reverse_rotate(stack_b, pos->maxlen, 1);
// 			rotations_needed--;
// 			pos->numb++;
// 			pos->rot = 'v';
// 		}
// 	}
// 	ft_printf("end of start posnumb : %i\n", pos->numb);
// 	return (count);
// }

// int	checkpos(t_stack *stack_a, t_stack *stack_b, int len, t_info data)
// {
// 	t_pos	pos;
// 	int		difb;

// 	difb = len - stack_b->len;
// 	pos.pos = data.small;
// 	pos.maxlen = len;
// 	data.count = 0;
// 	// if (data.small == difb)
// 	// 	return (ft_printf("2\n"), data.count += push(stack_b, stack_a, len),
// 	// 		data.count += rotate(stack_b, len, 1), data.count);;
// 	ft_printf("pos : %i\n", pos.pos - difb);
// 	pos.numb = 0;
// 	data.count += posrotation(stack_b, &pos, 0);
// 	data.count += push(stack_b, stack_a, len);
// 	difb = len - stack_b->len;
// 	while (pos.numb >= 0)
// 	{
// 		ft_printf("posnumb : %i\n", pos.numb);
// 		if (pos.rot == 'r')
// 			data.count += reverse_rotate(stack_b, len, 1);
// 		else if (pos.rot == 'v')
// 			data.count += rotate(stack_b, len, 1);
// 		pos.numb--;
// 	}
// 	return (data.count);
// }

t_check check_short(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, t_info data)
{
	t_check actual;
	t_v		v;
	int		total_moves;
	int		pos_in_b;
	int		target_pos_in_a;

	v.difa = chunks->maxlen - stack_a->len;
	v.difb = chunks->maxlen - stack_b->len;
	v.i = 0;
	actual.index = 0;
	actual.value = INT_MAX;
	// ft_printf("tab  :\ni   val  rb  dir  ra  dir  t1   big  b[i]\n");
	while (stack_b->len > v.i)
	{
		pos_in_b = v.i;
		data.actual = v.difb + v.i;
		data.big = v.difa;
		// data.small = v.difa;
		find_neighbors(stack_a, stack_b, &data, chunks->chunks);
		target_pos_in_a = data.big - v.difa;
		// ft_printf("data.actual : %i\n", stack_b->list[data.actual]);
		// ft_printf("rot b /2 : %i\n", stack_b->len - (data.actual - v.difb));
		// ft_printf("rot b : %i\n", (data.actual - v.difb)); 
		// char es = '\0';
		// if (v.i < 10)
		// 	es = ' ';
		// char es1 = '\0';
		// if (stack_b->list[v.i + v.difb] < 10)
		// 	es1 = ' ';
		// ft_printf("%i%c  %i%c", v.i, es, stack_b->list[v.i + v.difb], es1);
		// es = '\0';
		// es1 = '\0';
		if (pos_in_b <= stack_b->len / 2)
		{
			total_moves = pos_in_b;
			v.rotb = 1;
			// if (total_moves < 10)
			// 	es = ' ';
			// ft_printf("   %i%c   %c", total_moves, es, 'r');
		}
		else
		{
			total_moves = stack_b->len - pos_in_b;
			v.rotb = 0;
			// if (total_moves < 10)
			// 	es = ' ';
			// ft_printf("   %i%c   %c", total_moves, es, 'v');
		}
		// es = '\0';
		// es1 = '\0';
		if (target_pos_in_a <= stack_a->len / 2)
		{
			total_moves += target_pos_in_a;
			v.rota = 1;
			// if (target_pos_in_a < 10)
			// 	es = ' ';
			// ft_printf("   %i%c  %c", target_pos_in_a, es, 'r');
		}
		else
		{
			total_moves += stack_a->len - target_pos_in_a;
			v.rota = 0;
			// if (stack_a->len - target_pos_in_a < 10)
			// 	es = ' ';
			// ft_printf("   %i%c  %c", stack_a->len - target_pos_in_a, es, 'v');
		}
		// es = '\0';
		// es1 = '\0';
		// if (total_moves < 10)
		// 	es = ' ';
		// if ( stack_a->list[data.big] < 10)
		// 	es1 = ' ';
		// ft_printf("    %i%c   %i%c   %i\n", total_moves, es, stack_a->list[data.big], es1, data.big - v.difa);
		if (actual.value > total_moves)
		{
			actual.index = v.i;
			actual.value = total_moves;
			actual.big = data.big;
			actual.rota = v.rota;
			actual.rotb = v.rotb;
		}
		v.i++;
	}
	// ft_printf("result  :\ni rot big b[i]\n");
	// ft_printf("%i  %i  %i   %i\n",actual.index, actual.value, stack_a->list[actual.big], actual.big - v.difa);
	return (actual);
}

int	sort_stack_b(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks)
{
	t_check shorter;
	t_info 	data;
	int 	count;
	t_v		v;
	int		rotb_count;
	int		rota_count;

	count = 0;
	while (stack_b->len > 0)
	{
		v.difb = chunks->maxlen - stack_b->len;
		v.difa = chunks->maxlen - stack_a->len;
		data.len = stack_a->len;
		shorter = check_short(stack_a, stack_b, chunks, data);
		// ft_printf("big %i\n", shorter.big - v.difa);
		if (shorter.rotb)
			rotb_count = shorter.index;// + v.difb;
		else
			rotb_count = stack_b->len - shorter.index;// + v.difb);
		// ft_printf("%i : rotcount\n", rot_count);
		if (shorter.rota)
			rota_count = shorter.big - v.difa;
		else
			rota_count = stack_a->len - (shorter.big - v.difa);
		// ft_printf("rotation_c shortex.ind : %i, %i\n", rotb_count, shorter.index);
		while (rotb_count > 0)
		{
			if (shorter.rotb)
				count += rotate(stack_b, chunks->maxlen, 1);
			else
				count += reverse_rotate(stack_b, chunks->maxlen, 1);
				// ft_printf("%i\n", shorter.index);
				// ft_printf("%i\n", v.i);
			rotb_count--;
		}
		while (rota_count > 0)
		{
			if (shorter.rota)
				count += rotate(stack_a, chunks->maxlen, 1);
			else
				count += reverse_rotate(stack_a, chunks->maxlen, 1);
			// ft_printf("%i\n",shorter.big - v.difa);
			// ft_printf("%i\n", v.i);
			rota_count--;
		}
		count += push(stack_a, stack_b, chunks->maxlen);
		// printf_all(*stack_a, *stack_b, chunks->maxlen, count);
	}
	if (stack_a->list[stack_a->len / 2] < chunks->median)
		v.n = 1;
	else
		v.n = 0;
	while (!check_sort(stack_a, stack_a->len, 0))
	{
		if (v.n)
			count += rotate(stack_a, chunks->maxlen, 1);
		else
			count += reverse_rotate(stack_a, chunks->maxlen, 1);
	}
	return (count);
}

int	found_chunk(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks)
{
	int	dif;
	int	count;

	count = 0;
	// while (stack_b->len > 0)
	// {
		dif = chunks->maxlen - stack_b->len;
		// ft_printf("________________________\n");
		// printf_all(*stack_a, *stack_b, chunks->maxlen, count);
		count += sort_stack_b(stack_a, stack_b, chunks);
		// printf_all(*stack_a, *stack_b, chunks->maxlen, count);
		// ft_printf("________________________\n\n");
		// }
		// else
		// {
		// 	if (chunks->rot == 'r')
		// 		count += rotate(stack_a, chunks->maxlen, 1);
		// 	else
		// 		count += reverse_rotate(stack_a, chunks->maxlen, 1);
		// }
	// }
	return (count);
}

int median_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, int count)
{
	int	i;
	int difa;
	int	difb;
	
	i = 0;
	while (i < chunks->maxlen)
	{
		difa = chunks->maxlen - stack_a->len;
		difb = chunks->maxlen - stack_b->len;
		if (stack_a->list[difa] == chunks->median 
			|| stack_a->list[difa] == chunks->min
			|| stack_a->list[difa] == chunks->max)
			count += rotate(stack_a, chunks->maxlen, 1);
		else if (stack_a->list[difa] > chunks->median)
		{
			count += push(stack_b, stack_a, chunks->maxlen);
			count += rotate(stack_b, chunks->maxlen, 1);
		}
		else if (stack_a->list[difa] < chunks->median)
			count += push(stack_b, stack_a, chunks->maxlen);
		i++;
	}
	return (count);
}

int	turkey_sort(t_stack *stack_a, t_stack *stack_b, t_chunk *chunks, int count)
{

	// ft_printf("TURKEY\n");
	// ft_printf("min : %i, median : %i, max : %i\n", chunks->min, chunks->median, chunks->max);
	count += median_sort(stack_a, stack_b, chunks, 0);
	count += triplet(stack_a, chunks->maxlen, 0);
	count += found_chunk(stack_a, stack_b, chunks);
	// ft_printf("check_sort = %i\n", check_sort(stack_a, 3, chunks->maxlen - stack_a->len));
	// printf_all(*stack_a, *stack_b, chunks->maxlen, count);
	// if (shortcut_rot(stack_a, chunks) <= stack_a->len / 2)
	// 	chunks->rot = 'v';
	// else
	// 	chunks->rot = 'r';
	// count += found_chunk(stack_a, stack_b, chunks);
	// while (stack_b->len > 0)
	// 	count += push(stack_a, stack_b, chunks->maxlen);
	return (count);
}
