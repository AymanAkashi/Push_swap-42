/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:35:00 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/26 16:55:15 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/push_swap.h"

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i] && str[i] == str2[i])
		i++;
	return (str[i] - str2[i]);
}

long long	ft_atoi_long(const char *str)
{
	int					i;
	long				n;
	unsigned long long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
			n *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * n);
}

void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

t_var	*inis(t_var *v)
{
	v = (t_var *)malloc(sizeof(t_var));
	if (!v)
		exit(1);
	v->a = NULL;
	v->b = NULL;
	v->spl = NULL;
	v->len = 0;
	v->fd = 1;
	return (v);
}
