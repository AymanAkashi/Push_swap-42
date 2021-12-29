/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:41:35 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/23 16:47:13 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/*#include<stdio.h> 
#include <fcntl.h> 
int main() 
{ 
int sz; 
  
int fd = open("foo.txt", O_WRONLY); 
if (fd < 0) 
{ 
    perror("r1"); 
    exit(1); 
} 
  
ft_putendl_fd("hello geeks", fd); 
   
close(fd); 
}*/