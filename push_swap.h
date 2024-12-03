/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:34:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:34:17 by jdhallen         ###   ########.fr       */
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
	int	*list;
	int	len;
}	t_stack;

void	push(t_stack *stack_1, t_stack *stack_2, int maxlen);
void	rrotate(t_stack *stack_1, t_stack *stack_2, int maxlen);
void	rotate(t_stack *stack, int maxlen);
void	rreverse_rotate(t_stack *stack_1, t_stack *stack_2, int maxlen);
void	reverse_rotate(t_stack *stack, int maxlen);
void 	swap(t_stack *stack, int maxlen);
int	push_swap(int *stack, int len);
int	check_sort(int *stack, int len);

#endif
