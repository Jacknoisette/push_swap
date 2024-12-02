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

typedef struct s_bint
{
    int value;
    int null_check;
}   t_bint;

t_bint	*build_bint(int *stack, int intlen, int exist);
void	reverse_rotate(t_bint *list_a, t_bint *list_b, int mod, int intlen);
void	rotate(t_bint *list_a, t_bint *list_b, int mod, int intlen);
void	push(t_bint *list_a, t_bint *list_b, int mod, int intlen);
void	swap(t_bint *list_a, t_bint *list_b, int mod);
int	    *build_int(int *stack, t_bint **bint_list, int intlen);
int	    push_swap(int *stack);
int	    intlen(int *stack);

#endif


