/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:51:21 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 16:51:36 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	normalize(t_stk **a, t_stk **b, t_var *v, int min)
{
	int	idx;
	int	num;

	idx = get_idx((*a), min, 1);
	num = (ft_list_size((*a)) / 2);
	if (num > idx)
		pick_case(a, b, RA, v);
	else
		pick_case(a, b, RRA, v);
}

void	normalize_a(t_stk **a, t_stk **b, t_var *v, int pvt)
{
	int	idx;
	int	num;

	idx = get_idx((*a), pvt, 1);
	num = (ft_list_size((*a)) / 2);
	if (idx < num)
		pick_case(a, b, RA, v);
	else
		pick_case(a, b, RRA, v);
}

void	normalize_b(t_stk **a, t_stk **b, t_var *v, int pvt)
{
	int	idx;
	int	num;

	idx = get_idx((*b), pvt, 2);
	num = ft_abs((ft_list_size((*b)) / 2));
	if (idx < num && *b)
		pick_case(a, b, RB, v);
	else if (*b)
		pick_case(a, b, RRB, v);
}
