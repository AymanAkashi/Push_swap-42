/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:54:01 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/03 12:10:23 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_checksize(int n)
{
	int			i;
	long int	j;

	i = 0;
	j = n;
	if (j == 0)
		i++;
	if (j < 0)
	{
		i++;
		j *= -1;
	}
	while (j >= 2147483648)
			j--;
	while (j > 0)
	{
		j /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	j;

	j = n;
	size = ft_checksize(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (j < 0)
	{
		str[0] = '-';
		j *= -1;
	}
	str[size] = '\0';
	size--;
	while (j >= 10)
	{
		str[size] = ((j % 10) + '0');
		j /= 10;
		size--;
	}
	str[size] = j + 48;
	return (str);
}
/*#include<stdio.h>

int main()
{
	int i = -2147483648;
	printf("%d\n", ft_checksize(i));
	printf("%s", ft_itoa(i));
}*/
