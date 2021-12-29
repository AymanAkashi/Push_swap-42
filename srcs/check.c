/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:16:54 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 16:35:36 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	ft_check2arg(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (!ft_strcmp(str[i], str[j]))
				ft_exit_ps("Error\n", 1);
			j++;
		}
		i++;
	}
}

void	ft_checkarg(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		if (check_overflow(str[i]) == 0)
			ft_exit_ps("Error\n", 1);
		while (str[i][j])
		{
			if ((str[i][j] >= '0' && str[i][j] <= '9') || str[i][j] == '-')
				j++;
			else
				ft_exit_ps("Error\n", 1);
		}
		i++;
	}
}

int	check_sort(t_stk **a, int len)
{
	t_stk	*tmp;

	if (ft_list_size(*a) != len)
		return (0);
	(void)len;
	tmp = *a;
	while (tmp && tmp->next)
	{
		if ((tmp)->next != NULL && ((tmp)->data < (tmp)->next->data))
			(tmp) = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	check_overflow(char *arg)
{
	long long	tmp;

	tmp = ft_atoi_long(arg);
	if (tmp >= -2147483648 && tmp <= 2147483647 && ft_strlen(arg) < 12)
		return (1);
	return (0);
}

int	check_pivot(t_stk *a, int pvt, int flag)
{
	while (a)
	{
		if (flag == 1)
		{
			if (a->data <= pvt)
				return (1);
			a = a->next;
		}
		if (flag == 2)
		{
			if (a->data == pvt)
				return (1);
			a = a->next;
		}
	}
	return (0);
}
