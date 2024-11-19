/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:06 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:07 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int analyst(t_bint *list_a, t_bint *list_b, int intlen)
{
    int i;

    i = 0;
    while (i < intlen)
    {
        if (list_b[i].null_check == 1 || list_b[i].value != 0)
            return (0);
        i++;
    }
    i = 0;
    while (i < intlen - 1)
    {
        if (list_a[i].value > list_a[i + 1].value)
            return (0);
        i++;
    }

    return (1);
}

int little_analyst(t_bint *list_a, t_bint *list_b, int intlen)
{
	int	i;
	int	j;

	i = 0;
	while (i < intlen - 1)
	{
		j = 1;
		while(i + j < intlen - 1 && list_a[i + j].null_check == 1)
			j++;	
		if (list_a[i].value > list_a[i + j].value)
			return (0);
		i += j;
	}
	i = 0;
	while (i < intlen - 1)
	{
		j = 1;
		while(i + j < intlen - 1 && list_b[i + j].null_check == 1)
			j++;	
		if (list_b[i].value < list_b[i + j].value)
			return (0);
		i += j;
	}
	return (1);
}

int check_little(t_bint	*list, int intlen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < intlen - 1)
	{
		if (list[j].value > list[i].value)
			j = i;
		i++;
	}
	return (j);
}

void printlist(t_bint *list_a, t_bint *list_b, int intlen, int numb)
{
	int	i;

	i = 0;
	ft_printf("\n Turn : %i\n", numb);
	while (i < intlen)
	{
		ft_printf("%i  %i  |  %i  %i\n", list_a[i].value, list_b[i].value, list_a[i].null_check, list_b[i].null_check);
		i++;		
	}
	ft_printf("\n________\n");
}

// int	commander(t_bint **list_a, t_bint **list_b, int intlen)
// {

// }


int	push_swap(int *stack)
{
	t_bint *list_a;
    t_bint *list_b;
	int numb;
	int len;
	int	ind;

	len = intlen(stack);
	list_a = build_bint(stack, len, 0);
	list_b = build_bint(stack, len, 1);
    while (analyst(list_a, list_b, len) == 0) 
	{
		ind = check_little(list_a, len);
        while (ind > 0) 
		{
            // if (index_min < len / 2)
            rotate(list_a, list_b, 1, len);
			numb++;
			ind--;
            // else
            //     rotation_gauche(list_a);
        }
        push(list_a, list_b, 2, len);
		numb++;
    }
    return (numb);
}

int main(void)
{
	int	stack[] = {4,6,1,3,9,2,'\0'};
	// int	stack[] = {1,2,3,4,5,6,'\0'};

	push_swap(stack);
	return (0);
}

// t_bint	*list_a;
//     t_bint	*list_b;
// 	int numb;
// 	int len;
// 	int i = 0;

// 	len = intlen(stack);

// 	while (analyst(list_a, list_b, len) == 0 && i++ < 1000000)
// 	{
// 		numb = commander(&list_a, &list_b, len);
// 		if (numb == 9)
// 		{
// 			printf("ok");
// 			break;
// 		}
// 	}
// 	stack = build_int(stack, &list_a, len);
// 	free(list_b);
// 	return (numb);