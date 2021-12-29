/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 08:58:00 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/23 16:11:46 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char			*dest;
	const char		*src;
	unsigned int	i;

	dest = (char *)str1;
	src = (const char *)str2;
	if (dest > src)
	{
		i = n;
		while (i-- > 0)
		{
			dest[i] = src[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main () {
   char dest[] = "oldstring";
   const char src[]  = "newstring";

	ft_memmove(dest, src, 7);
   printf("f_memmove dest = %s, src = %s\n", dest, src);
   memmove(dest, src, 10);
   printf("memmove dest = %s, src = %s\n", dest, src);

   return(0);
}*/
