/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:34:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/12 10:52:56 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/ft_libft/ft_libft.h"
# include "Libft/ft_printf/ft_printf.h"
# include "Libft/get_next_line/get_next_line.h"
# include <limits.h>

typedef struct	s_stack
{
	char	letter;
	int		*list;
	int		len;
}	t_stack;

int radix_sort(t_stack *stack_a, t_stack *stack_b, int len, int count);
int	push(t_stack *stack_1, t_stack *stack_2, int maxlen);
int	rrotate(t_stack *stack_1, t_stack *stack_2, int maxlen);
int	rotate(t_stack *stack, int maxlen, int print);
int	rreverse_rotate(t_stack *stack_1, t_stack *stack_2, int maxlen);
int	reverse_rotate(t_stack *stack, int maxlen, int print);
int sswap(t_stack *stack_1, t_stack *stack_2, int maxlen);
int swap(t_stack *stack, int maxlen, int print);
int quintuplet(t_stack *stack_a, t_stack *stack_b, int len, int count);
int	triplet(t_stack *stack, int len, int count);
int	push_swap(int *stack, int len);
int	check_sort(t_stack *stack, int len, int start);
int	check_little(t_stack *stack, int len, int start);
int	check_seclittle(t_stack *stack, int len, int start);
int	check_big(t_stack *stack, int len, int start);

void	printf_all(t_stack stack_a, t_stack stack_b, int len, int count);

#endif
