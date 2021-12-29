/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:44:35 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/11/25 20:50:53 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd)
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
}
/*#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<fcntl.h> 

int main()
{
int fd = open("test.txt", O_CREAT | O_WRONLY ,0644);
	if (fd < 0) 
{ 
    perror("r1"); 
    exit(1); 
} 
	char *str = "Hello Aymane are you okay";
	ft_putstr_fd(str,fd);
	close(fd);
}*/
