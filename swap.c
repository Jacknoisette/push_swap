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

void	swap(t_bint *list_a, t_bint *list_b, int mod)
{
	t_bint temp;

	if (mod == 1 || mod == 3)
	{
		temp = list_a[0];
		list_a[0] = list_a[1];
		list_a[1] = temp;
	}
	if (mod == 2 || mod == 3)
	{
		temp = list_b[0];
		list_b[0] = list_b[1];
		list_b[1] = temp;
	}
	return ;
}

// int main(void)
// {
// 	t_bint	list_a[] = {{4,0},{6,0},{1,0},{3,0},{9,0},{2,0}};
// 	t_bint	list_b[6] = {{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}};
// 	int	i;

// 	swap(list_a, list_b, 1);
// 	i = 0;
// 	while (i++ < 6)
// 	{
// 		ft_printf("%i  %i   |", list_a[i - 1].value, list_b[i - 1].value);
// 		ft_printf("   %i  %i\n", list_a[i - 1].null_check, list_b[i - 1].null_check);
// 	}
// 	ft_printf("a  b   |   a  b\n\n");
// 	ft_printf("_____\n\n");
// 	return (0);
// }