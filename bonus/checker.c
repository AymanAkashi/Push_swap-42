/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:08:41 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/28 12:03:55 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

char	*get_next_line(int fd)
{
	char	str[8000000];
	int		i;
	char	buff[1];
	int		byte;

	byte = read(fd, buff, 1);
	i = 0;
	while (byte > 0)
	{
		str[i++] = buff[0];
		if (buff[0] == '\n')
			break ;
		byte = read(fd, buff, 1);
	}
	str[i] = '\0';
	if (str[0] == '\0')
		return (0);
	return (ft_strdup(str));
}

void	checker_2(t_stk **a, t_stk **b, char *str)
{
	t_stk	*stk;

	stk = NULL;
	if (!ft_strcmp("pa\n", str))
		push(b, a, stk);
	else if (!ft_strcmp("rrr\n", str))
	{
		r_rotate(a, stk);
		r_rotate(b, stk);
	}
	else if (!ft_strcmp("ss\n", str))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp("rr\n", str))
	{
		rotate(a, stk);
		rotate(b, stk);
	}
	else
		ft_exit_ps("Error\n", 1);
	free(stk);
}

void	checker(t_stk **a, t_stk **b, t_stk *stk)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!ft_strcmp("rra\n", str))
			r_rotate(a, stk);
		else if (!ft_strcmp("ra\n", str))
			rotate(a, stk);
		else if (!ft_strcmp("sa\n", str))
			swap(a);
		else if (!ft_strcmp("rrb\n", str))
			r_rotate(b, stk);
		else if (!ft_strcmp("rb\n", str))
			rotate(b, stk);
		else if (!ft_strcmp("sb\n", str))
			swap(b);
		else if (!ft_strcmp("pb\n", str))
			push (a, b, stk);
		else
			checker_2(a, b, str);
		free(stk);
		str = get_next_line(0);
	}
}

t_var	*varia(t_var *v, int ac, char **av, t_stk *stk)
{
	v->spl = search_arg(v, ac, av);
	ft_checkarg(v->spl);
	ft_check2arg(v->spl);
	v->len = ft_list_size(v->a);
	v->a = ft_stklst(v, v->spl, stk);
	free(stk);
	return (v);
}

int	main(int ac, char **av)
{
	int		i;
	t_var	*v;
	t_stk	*stk;

	stk = NULL;
	v = NULL;
	v = inis(v);
	i = 0;
	if (ac < 2)
		ft_exit_ps("Error\n", 1);
	v = varia(v, ac, av, stk);
	checker(&v->a, &v->b, stk);
	if (check_sort(&v->a, ft_list_size(v->a)) && !v->b)
	{
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
		return (0);
	}
}
