/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:00:20 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 17:47:32 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	case_with_3(t_stk **a, t_stk **b, t_var *v)
{
	if ((*a)->data == get_max(*a) && (*a)->next->data == get_min(*a))
		pick_case(a, b, RA, v);
	else if ((*a)->data == get_min(*a) && (*a)->next->data == get_max(*a))
	{
		pick_case(a, b, RRA, v);
		pick_case(a, b, SA, v);
	}
	else if ((*a)->data == get_max(*a) && (*a)->next->data == find_mid_3(*a))
	{
		pick_case(a, b, SA, v);
		pick_case(a, b, RRA, v);
	}
	else if ((*a)->data == find_mid_3(*a) && (*a)->next->data == get_min(*a))
		pick_case(a, b, SA, v);
	else if ((*a)->data == find_mid_3(*a) && (*a)->next->data == get_max(*a))
		pick_case(a, b, RRA, v);
}

int	find_mid_3(t_stk *a)
{
	if (a->data == get_max(a) && a->next->data == get_min(a))
		return (a->next->next->data);
	else if (a->next->next->data == get_max(a) && a->next->data == get_min(a))
		return (a->data);
	else if (a->data == get_min(a) && a->next->data == get_max(a))
		return (a->next->next->data);
	else if (a->next->next->data == get_min(a) && a->next->data == get_max(a))
		return (a->data);
	else
		return (a->next->data);
}

void	sort_3(t_stk **a, t_stk **b, t_var *v, int op)
{
	pick_case(a, b, SA, v);
	pick_case(a, b, op, v);
}

void	sort_short(t_stk **a, t_stk **b, int len, t_var *v)
{
	t_stk	*tmp;

	tmp = NULL;
	if (len == 2 && (*a)->data > (*a)->next->data)
		pick_case(a, b, SA, v);
	if (len <= 3)
		case_with_3(a, b, v);
	else if (len > 3)
	{
		case_with_10(a, b, len, v);
		case_with_3(a, b, v);
		while ((*b))
		{
			tmp = *b;
			pick_case(a, b, PA, v);
			free(tmp);
		}
		free_stk(b);
	}
	free_stk(a);
}
