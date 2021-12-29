/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:26:29 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/23 16:10:20 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t	i;

	i = 0;
	if (!source && !destination)
		return (NULL);
	while (num > i)
	{
		*(char *)(destination + i) = *(char *)(source + i);
		i++;
	}
	return (destination);
}
