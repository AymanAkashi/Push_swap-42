/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggoujj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:24:23 by aaggoujj          #+#    #+#             */
/*   Updated: 2021/12/03 14:09:56 by aaggoujj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void*));

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstadd_back(t_list **lst, t_list *new);

t_list			*ft_lstlast(t_list *lst);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new);

unsigned int	ft_strlcat(char *dest, char const *src, unsigned int size);

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			**ft_split(char const *s, char c);

char			*ft_itoa(int n);

void			ft_putnbr_fd(int n, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putchar_fd(char c, int fd);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_substr(char const *s, unsigned int start, size_t len);

void			*ft_calloc( size_t num, size_t size );

int				ft_memcmp(const void *str1, const void *str2, size_t n);

void			*ft_memchr(const void *str, int c, size_t n);

void			*ft_memmove(void *str1, const void *str2, size_t n);

void			*ft_memcpy(void *destination, const void *source, size_t num );

void			*ft_memset(void *s, int c, size_t n);

char			*ft_strdup(const char *s1);

int				ft_tolower(int ch);

int				ft_toupper(int ch);

char			*ft_strnstr(const char *s1, const char *s2, size_t n);

char			*ft_strrchr(const char *str, int c);

int				ft_atoi(char const *str);

int				ft_isalnum(int l);

void			ft_bzero(void *s, size_t n);

int				ft_isalpha(int c);

int				ft_isascii(int a);

int				ft_isdigit(int n);

int				ft_isprint(int c);

char			*ft_strchr(const char *s, int c);

size_t			ft_strlen(char const *str);

int				ft_strlcpy(char *dst, const char *src, size_t dstsize);

int				ft_strncmp(char const *s1, char const *s2, unsigned int n);

#endif
