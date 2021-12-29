/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:42:13 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/28 12:07:23 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include"../ft_libft/libft.h"

# define SA 1
# define SB 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6 
# define RRA 7
# define RRB 8

typedef struct s_stk
{
	int				data;
	struct s_stk	*next;
}				t_stk;

typedef struct s_var
{
	t_stk	*a;
	t_stk	*b;
	int		ac;
	int		fd;
	int		len;
	char	**av;
	char	**spl;

}	t_var;

void		sort_3(t_stk **a, t_stk **b, t_var *v, int op);

void		lstadd_back(t_stk **lst, t_stk *new);

void		lstadd_front(t_stk **lst, t_stk *new);

t_stk		*lstlast(t_stk *lst);

int			ft_strcmp(char *str, char *str2);

void		ft_check2arg(char **str);

void		ft_checkarg(char **str);

t_stk		*ft_stklst(t_var *v, char **av, t_stk *stk);

void		add_back(t_stk **top, t_stk *new);

char		**search_arg(t_var *v, int ac, char **av);

void		ft_exit_ps(char *arg, int err);

int			ft_list_size(t_stk *a);

t_var		*inis(t_var *v);

void		swap(t_stk **a);

t_stk		*ft_lstdel(t_stk **a, t_stk *tmp);

void		r_rotate(t_stk **a, t_stk *tmp);

void		rotate(t_stk **a, t_stk *tmp);

void		push(t_stk **a, t_stk **b, t_stk *tmp);

void		case_with_3(t_stk **a, t_stk **b, t_var *v);

void		case_with_10(t_stk **a, t_stk **b, int len, t_var *v);

void		normalize(t_stk **a, t_stk **b, t_var *v, int min);

void		first_sort(t_stk **a, t_stk **b, int len, t_var *v);

void		second_sort(t_stk **a, t_stk **b, int len, t_var *v);

void		third_sort(t_stk **a, t_stk **b, int len, t_var *v);

void		free_stk(t_stk **stk);

void		sort_bigger(t_stk **a, t_stk **b, int len, t_var *v);

void		ft_free_array(char **array);

int			ft_checksort(t_stk **a, int len);

int			check_overflow(char *arg);

int			get_pivot(t_stk *stk);

int			check_pivot(t_stk *a, int pvt, int flag);

void		normalize_a(t_stk **a, t_stk **b, t_var *v, int pvt);

void		normalize_b(t_stk **a, t_stk **b, t_var *v, int pvt);

int			get_min(t_stk *a);

int			get_max(t_stk *a);

void		pick_case(t_stk **a, t_stk **b, int c, t_var *v);

int			get_idx(t_stk *stk, int data, int flag);

t_stk		*ft_lst_dup(t_stk *stk);

int			check_sort(t_stk **a, int len);

int			ft_abs(int nb);

void		ft_lstswp(t_stk *x, t_stk *y);

int			ft_lstnbr(t_stk **stk, int idx);

t_stk		*ft_lstsort(t_stk *stk);

int			find_mid_3(t_stk *a);

void		next_case(t_stk **a, t_stk **b, int c, t_var *v);

void		next_next_case(t_stk **a, t_stk **b, int c, t_var *v);

void		next_next_next_case(t_stk **a, t_stk **b, int c, t_var *v);

void		sort_short(t_stk **a, t_stk **b, int len, t_var *v);

long long	ft_atoi_long(const char *str);

void		case_with_3(t_stk **a, t_stk **b, t_var *v);

char		*get_next_line(int fd);

#endif
