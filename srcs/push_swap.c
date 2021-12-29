/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:40:34 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/28 12:07:09 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	ft_list_size(t_stk *a)
{
	int	len;

	len = 0;
	while (a)
	{
		a = a->next;
		len++;
	}
	return (len);
}

t_stk	*ft_stklst(t_var *v, char **av, t_stk *stk)
{
	int	i;

	i = 0;
	while (av[i])
	{
		stk = malloc(sizeof(t_stk));
		if (stk == NULL)
			return (NULL);
		stk->data = ft_atoi(av[i]);
		if (stk->data > 2147483647 || stk->data < -2147483648)
			return (NULL);
		stk->next = NULL;
		add_back(&v->a, stk);
		stk = NULL;
		i++;
	}
	return (v->a);
}

char	**search_arg(t_var *v, int ac, char **av)
{
	if (ac == 2)
		v->spl = ft_split(av[1], ' ');
	else
	v->spl = &av[1];
	return (v->spl);
}

void	push_swap(t_var *v, int ac, char **av)
{
	t_stk	*stk;

	stk = NULL;
	v->spl = search_arg(v, ac, av);
	ft_checkarg(v->spl);
	ft_check2arg(v->spl);
	v->a = ft_stklst(v, v->spl, stk);
	if (check_sort(&v->a, ft_list_size(v->a)) == 1)
		return ;
	v->len = ft_list_size(v->a);
	if (v->len <= 15)
		sort_short(&v->a, &v->b, v->len, v);
	else
		sort_bigger(&(v->a), &(v->b), v->len, v);
	if (ac == 2 || (ac == 3 && v->fd != 1))
		ft_free_array(v->spl);
	close(v->fd);
}

int	main(int ac, char **av)
{
	int		i;
	t_var	*v;

	i = 1;
	v = NULL;
	if (ac < 2)
		exit(1);
	else
	{
		v = inis(v);
		push_swap(v, ac, av);
		free(v);
		v = NULL;
	}
}
