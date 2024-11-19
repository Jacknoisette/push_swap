/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:35 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:38 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_null(t_bint *list, int intlen)
{
    int i;
	int	check;

    while (i < intlen - 1)
    {
        if (list[i].null_check == 1)
            check++;
        i++;
    }
	if (check == intlen)
		return (0);
    return(1);
}

void	push(t_bint *list_a, t_bint *list_b, int mod, int intlen)
{
	if (mod == 1 && check_null(list_b, intlen))
	{
		reverse_rotate(list_a, list_b, 1, intlen);
		list_a[0] = list_b[0];
		list_b[0].value = 0;
		list_b[0].null_check = 1;
		rotate(list_a, list_b, 2, intlen);
	}
	if (mod == 2 && check_null(list_a, intlen))
	{
		reverse_rotate(list_a, list_b, 2, intlen);
		list_b[0] = list_a[0];
		list_a[0].value = 0;
		list_a[0].null_check = 1;
		rotate(list_a, list_b, 1, intlen);
	}
}

// int main(void)
// {
// 	t_bint	list_a[] = {{4,0},{6,0},{1,0},{3,0},{9,0},{2,0}};
// 	t_bint	list_b[6] = {{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}};
// 	int	i;
// 	int	j;

// 	while (j++ < 7)
// 	{
// 		i = 0;
// 		while (i++ < 6)
// 		{
// 			ft_printf("%i  %i   |", list_a[i - 1].value, list_b[i - 1].value);
// 			ft_printf("   %i  %i\n", list_a[i - 1].null_check, list_b[i - 1].null_check);
// 		}
// 		ft_printf("a  b \n\n");
// 		ft_printf("_____\n\n");
// 		push(list_a, list_b, 2, 6);
// 	}
// 	return (0);
// }
