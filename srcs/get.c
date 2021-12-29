/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:34:54 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 16:37:37 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	get_pivot(t_stk *stk)
{
	t_stk	*tmp;
	int		len;
	int		pvt;

	pvt = 0;
	len = 0;
	tmp = NULL;
	len = ft_list_size(stk);
	tmp = ft_lstsort(stk);
	if (len <= 10)
		pvt = ft_abs(len / 2);
	else if (len > 10 && len < 200)
		pvt = ft_abs(len / 4);
	else if (len >= 200)
		pvt = ft_abs(len / 8);
	return (ft_lstnbr(&tmp, pvt));
}

int	get_idx(t_stk *stk, int data, int flag)
{
	int	i;

	i = 1;
	if (flag == 1)
	{
		while (stk)
		{
			if (stk->data <= data)
				return (i);
			stk = stk->next;
			i++;
		}
	}
	if (flag == 2)
	{
		while (stk)
		{
			if (stk->data >= data)
				return (i);
			stk = stk->next;
			i++;
		}
	}
	return (-1);
}

int	get_max(t_stk *a)
{
	int	max;

	max = a->data;
	while (a->next != NULL)
	{
		a = a->next;
		if (a->data > max)
			max = a->data;
	}
	return (max);
}

int	get_min(t_stk *a)
{
	int	min;

	min = a->data;
	while (a->next != NULL)
	{
		a = a->next;
		if (a->data < min)
			min = a->data;
	}
	return (min);
}
