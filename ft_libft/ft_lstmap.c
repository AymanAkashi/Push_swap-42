/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:56:02 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/25 14:25:30 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*res;

	res = NULL;
	while (lst)
	{
		new_lst = (t_list *)malloc(sizeof(t_list));
		if (!new_lst)
		{
			ft_lstclear(&res, del);
			new_lst = NULL;
		}
		new_lst->content = f(lst->content);
		new_lst->next = NULL;
		ft_lstadd_back(&res, new_lst);
		lst = lst->next;
	}
	return (res);
}
