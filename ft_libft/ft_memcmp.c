/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:28:42 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/23 16:08:20 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*dest1;
	const unsigned char	*dest2;
	size_t				i;

	dest1 = (const unsigned char *)str1;
	dest2 = (const unsigned char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((dest1[i] != dest2[i]))
			return (dest1[i] - dest2[i]);
		i++;
	}
	if (i == n)
		i--;
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }

   return(0);
}*/
