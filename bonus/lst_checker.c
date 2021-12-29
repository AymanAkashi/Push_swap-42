/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:52:42 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/28 11:52:46 by aaggoujj         ###   ########.fr       */
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
