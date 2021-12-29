/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:34:19 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/28 12:04:49 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	first_sort(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		i;
	int		pvt;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i >= ft_abs(len / 16))
	{
		tmp1 = ft_lst_dup(*a);
		pvt = get_pivot(tmp1);
		while (check_pivot((*a), pvt, 1) && (*a))
		{
			if ((*a)->data <= pvt)
			{
				tmp2 = *a;
				pick_case(a, b, PB, v);
				i--;
				free(tmp2);
			}
			else
				normalize_a(a, b, v, pvt);
		}
		free_stk(&tmp1);
	}
}

void	second_sort(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		min;
	t_stk	*tmp;

	tmp = NULL;
	while (*a && !check_sort(a, len))
	{
		min = get_min(*a);
		tmp = (*a)->next;
		if ((*a)->data == get_max(*a))
			pick_case(a, b, RA, v);
		while ((*a)->data != min && tmp && tmp->data == min)
			pick_case(a, b, SA, v);
		while (ft_list_size(*a) && check_pivot((*a), min, 1))
		{
			if ((*a)->data == min)
			{
				tmp = *a;
				pick_case(a, b, PB, v);
				free(tmp);
				len--;
			}
			else
				normalize_a(a, b, v, min);
		}
	}
}

void	third_sort(t_stk **a, t_stk **b, int max, t_var *v)
{
	t_stk	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = get_max(*b);
		while (check_pivot((*b), max, 2))
		{
			max = get_max(*b);
			tmp = (*b)->next;
			while ((*b)->data != max && tmp && tmp->data == max)
				pick_case(a, b, SB, v);
			while (((*b)->data != max) && *b)
				normalize_b(a, b, v, max);
			while (*b && (*b)->data == max)
			{
				tmp = *b;
				max = get_max(*b);
				pick_case(a, b, PA, v);
				free(tmp);
			}
		}
	}
}

void	sort_bigger(t_stk **a, t_stk **b, int len, t_var *v)
{
	int	max;

	max = 0;
	first_sort(a, b, len, v);
	second_sort(a, b, len, v);
	third_sort(a, b, max, v);
	free_stk(a);
	free_stk(b);
}
