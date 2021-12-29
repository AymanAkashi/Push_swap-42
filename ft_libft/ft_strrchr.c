/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:21:30 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/23 18:23:00 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	if (str[0] == (unsigned char)c)
		return ((char *)str);
	return (0);
}
/*#include<string.h>
#include<stdio.h>
 
int main()
  {
      char *s ="2@cd ada";
      char *d ="adasdaaa";
       size_t i = 97;
      printf("%s", strrchr(s,i));
 }*/
