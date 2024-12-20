/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:34:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 18:21:28 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/ft_libft/ft_libft.h"
# include "Libft/ft_printf/ft_printf.h"
# include "Libft/get_next_line/get_next_line.h"
# include <limits.h>

typedef struct s_rot
{
	int	rotb_count;
	int	rota_count;
}	t_rot;

typedef struct s_v
{
	int	i;
	int	j;
	int	k;
	int	n;
	int	difa;
	int	difb;
}	t_v;

typedef struct s_optirot
{
	int	total_moves;
	int	pos_in_b;
	int	target_pos_in_a;
	int	rota;
	int	rotb;
}	t_optirot;

typedef struct s_check
{
	int	rota;
	int	rotb;
	int	dira;
	int	dirb;
	int	index;
	int	value;
	int	big;
}	t_check;

typedef struct s_info
{
	int	actual;
	int	big;
	int	small;
	int	count;
	int	len;
	int	stop;
}	t_info;

typedef struct s_short
{
	t_check	shorter;
	t_info	data;
	t_rot	r_count;
	t_v		v;
	int		count;
}	t_short;

typedef struct s_stack
{
	char	letter;
	int		*list;
	int		len;
}	t_stack;

typedef struct s_chunk
{
	t_stack	chunks;
	char	rot;
	int		len;
	int		maxlen;
	int		found;
	int		median;
	int		min;
	int		max;
}	t_chunk;

void	printf_all(t_stack stack_a, t_stack stack_b, int len, int count);

void	actualize(t_check *actual, t_optirot op, t_v v, t_info data);
void	optimize_rotate(t_optirot *op, t_stack *stack_a, t_stack *stack_b);
void	rot_value(t_short *s, t_stack *stack_a, t_stack *stack_b);
long	ft_atol(const char *nptr, int *error, int i, int s);
int		find_neighbors(t_stack *stack_a, t_stack *stack_b,
			t_info *data, t_stack chunks);
int		chunk_sort(t_stack *stack_a, t_stack *stack_b, int len, int count);
int		turkey_sort(t_stack *stack_a, t_stack *stack_b,
			t_chunk *chunks, int count);
int		push(t_stack *stack_1, t_stack *stack_2, int maxlen);
int		rrotate(t_stack *stack_1, t_stack *stack_2, int maxlen);
int		rotate(t_stack *stack, int maxlen, int print);
int		rreverse_rotate(t_stack *stack_1, t_stack *stack_2, int maxlen);
int		reverse_rotate(t_stack *stack, int maxlen, int print);
int		sswap(t_stack *stack_1, t_stack *stack_2, int maxlen);
int		swap(t_stack *stack, int maxlen, int print);
int		quintuplet(t_stack *stack_a, t_stack *stack_b, int len, int count);
int		triplet(t_stack *stack, int len, int count);
int		push_swap(int *stack, int len, int count);
int		check_sort(t_stack *stack, int len, int start);
int		check_revsort(t_stack *stack, int len, int start);
int		check_little(t_stack *stack, int len, int start);
int		check_seclittle(t_stack *stack, int len, int start);
int		check_big(t_stack *stack, int len, int start);
int		median(t_stack *temp_chunk);
int		do_rot(t_short *s, t_stack *stack_a, t_stack *stack_b, int len);

#endif
