/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:15:13 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 16:50:46 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

void	swap(t_stk **a)
{
	t_stk	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	if ((*a) && (*a)->next != NULL)
	{
		tmp = (*a);
		i = (*a)->data;
		j = (*a)->next->data;
		tmp = (*a);
		(*a)->data = j;
		tmp = (*a);
		(*a)->next->data = i;
		(*a) = tmp;
	}
}

t_stk	*ft_lstdel(t_stk **a, t_stk *tmp)
{
	t_stk	*ptr;

	ptr = *a;
	if (*a)
	{
		while (ptr->next != NULL)
		{
			if (ptr->next->data == tmp->data)
			{
				ptr->next = NULL;
				ptr = *a;
				return (ptr);
			}
			ptr = ptr->next;
		}
	}
	return (NULL);
}

void	r_rotate(t_stk **a, t_stk *tmp)
{
	if (*a)
	{
		tmp = (t_stk *)malloc(sizeof(t_stk));
		tmp = (*a);
		tmp = lstlast(tmp);
		*a = ft_lstdel(a, tmp);
		lstadd_front(a, tmp);
	}
}

void	rotate(t_stk **a, t_stk *tmp)
{
	if (*a)
	{
		tmp = (t_stk *)malloc(sizeof(t_stk));
		tmp->data = (*a)->data;
		tmp->next = NULL;
		(*a) = (*a)->next;
		lstadd_back(a, tmp);
	}
}

void	push(t_stk **a, t_stk **b, t_stk *tmp)
{
	if (*b == NULL && (*a))
	{
		*b = (t_stk *)malloc(sizeof(t_stk));
		(*b)->data = (*a)->data;
		(*b)->next = NULL;
		(*a) = (*a)->next;
	}
	else
	{
		if (*a)
		{
			tmp = (t_stk *)malloc(sizeof(t_stk));
			tmp->data = (*a)->data;
			tmp->next = NULL;
			lstadd_front(b, tmp);
			(*a) = (*a)->next;
		}
	}
}
