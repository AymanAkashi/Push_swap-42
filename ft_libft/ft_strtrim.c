/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:03:56 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/23 18:25:05 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_checkchr(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && ft_checkchr(s1[i], set))
		i++;
	while (len > i && ft_checkchr(s1[len - 1], set))
		len--;
	str = (char *)malloc(sizeof(char) * (len - i) + 1);
	if (!str)
		return (NULL);
	while (len > i)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*#include<stdio.h>
int main()
{
	char *str;
	str = ft_strtrim("   xxxtripouillexxx    ", " x ");
	printf("%s\n", str);
}*/
