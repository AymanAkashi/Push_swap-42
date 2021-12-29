/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:34:28 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 16:30:37 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	case_with_10(t_stk **a, t_stk **b, int len, t_var *v)
{
	int		i;
	int		min;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i > 3)
	{
		min = get_min(*a);
		tmp1 = (*a)->next;
		if ((*a)->data == get_max(*a))
			pick_case(a, b, RA, v);
		if ((*a))
			if ((*a)->data != min && tmp1 && tmp1->data == min)
				pick_case(a, b, SA, v);
		while (min != (*a)->data)
			normalize(a, b, v, min);
		if (min == (*a)->data)
		{
			tmp2 = *a;
			pick_case(a, b, PB, v);
			free(tmp2);
			i--;
		}
	}
}

void	pick_case(t_stk **a, t_stk **b, int c, t_var *v)
{
	if (c == 1)
	{
		ft_putstr_fd("sa\n", v->fd);
		swap(a);
	}
	if (c == 2)
	{
		ft_putstr_fd("sb\n", v->fd);
		swap(b);
	}
	else
		next_case(a, b, c, v);
}

void	next_case(t_stk **a, t_stk **b, int c, t_var *v)
{
	t_stk	*tmp;

	tmp = NULL;
	if (c == 3)
	{
		ft_putstr_fd("pa\n", v->fd);
		push(b, a, tmp);
		free(tmp);
	}
	if (c == 4)
	{
		ft_putstr_fd("pb\n", v->fd);
		push(a, b, tmp);
		free(tmp);
	}
	next_next_case(a, b, c, v);
}

void	next_next_case(t_stk **a, t_stk **b, int c, t_var *v)
{
	t_stk	*tmp;

	tmp = NULL;
	if (c == 5)
	{
		ft_putstr_fd("ra\n", v->fd);
		rotate(a, tmp);
		free(tmp);
	}
	if (c == 6)
	{
		ft_putstr_fd("rb\n", v->fd);
		rotate(b, tmp);
		free(tmp);
	}
	else
		next_next_next_case(a, b, c, v);
}

void	next_next_next_case(t_stk **a, t_stk **b, int c, t_var *v)
{
	t_stk	*tmp;

	tmp = NULL;
	if (c == 7)
	{
		ft_putstr_fd("rra\n", v->fd);
		r_rotate(a, tmp);
		free(tmp);
	}
	if (c == 8)
	{
		ft_putstr_fd("rrb\n", v->fd);
		r_rotate(b, tmp);
		free(tmp);
	}
}
