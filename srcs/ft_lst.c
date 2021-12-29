/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:34:41 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 17:04:43 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	lstadd_back(t_stk **lst, t_stk *new)
{
	t_stk	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	lstadd_front(t_stk **lst, t_stk *new)
{
	if (lst)
	{
		if (*lst)
			new -> next = *lst;
		*lst = new;
	}
}

t_stk	*lstlast(t_stk *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst-> next;
	}
	return (lst);
}

t_stk	*ft_lst_dup(t_stk *stk)
{
	t_stk	*tmp1;
	t_stk	*tmp2;

	tmp1 = malloc(sizeof(t_stk));
	ft_bzero(tmp1, sizeof(t_stk));
	tmp2 = tmp1;
	while (stk)
	{
		tmp1->data = stk->data;
		if (stk->next)
		{
			tmp1->next = malloc(sizeof(t_stk));
			ft_bzero(tmp1->next, sizeof(t_stk));
			tmp1 = tmp1->next;
		}
		stk = stk->next;
	}
	tmp1 = tmp2;
	return (tmp1);
}

void	add_back(t_stk **top, t_stk *new)
{
	t_stk	*tmp;

	if (*top == NULL)
		*top = new;
	else
	{
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
