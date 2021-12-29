/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:08:27 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/23 18:17:17 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	i = ft_strlen(src);
	if (!dstsize || !src)
		return (i);
	while (src[k] && j < dstsize - 1)
	{
		dst[j] = src[k];
		j++;
		k++;
	}
	dst[j] = 0;
	return (i);
}
