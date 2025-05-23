/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvvz <lvvz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:20:49 by hounajar          #+#    #+#             */
/*   Updated: 2025/04/01 17:57:12 by lvvz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isascii(int c);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_bzero(void *s, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int n, size_t c);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
long int	ft_atoi(const char *nptr);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
t_stack		*ft_lstnew(int content);
int			ft_lstsize(t_stack *lst);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstdelone(t_stack *lst, void (*del)(int));
void		ft_lstclear(t_stack **lst, void (*del)(int));
void		ft_lstiter(t_stack *lst, void (*f)(int));
t_stack		*ft_lstmap(t_stack *lst, void *(*f)(int), void (*del)(int));
#endif
