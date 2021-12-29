/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:41:02 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 16:41:39 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

t_stk	*ft_lstsort(t_stk *stk)
{
	t_stk	*base;
	t_stk	*tmp;
	t_stk	*cmp;

	base = NULL;
	base = stk;
	tmp = NULL;
	cmp = NULL;
	while (base->next)
	{
		cmp = base;
		tmp = base->next;
		while (tmp)
		{
			if (cmp->data > tmp->data)
				cmp = tmp;
			tmp = tmp->next;
		}
		ft_lstswp(base, cmp);
		base = base->next;
	}
	return (stk);
}

int	ft_lstnbr(t_stk **stk, int idx)
{
	t_stk	*tmp;
	int		i;

	i = 0;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (i == idx)
			return (tmp->data);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	ft_lstswp(t_stk *x, t_stk *y)
{
	int	tmp;

	tmp = x->data;
	x->data = y->data;
	y->data = tmp;
}
