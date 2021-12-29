/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:46:25 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/23 18:21:57 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (!s2[0])
		return ((char *)s1);
	while ((s1[i] != '\0') && (i + 1) <= n)
	{
		j = 0;
		while (s1[i + j] && s2[j] && i + j < n && s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*#include<stdio.h>

int main()
{
	 char *s ="Aymane become the correction";
     char *d ="the";
    size_t i = 10;
    printf("%s", ft_strnstr(s,d,i));
}*/
