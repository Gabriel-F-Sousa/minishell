/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:46 by gabferna          #+#    #+#             */
/*   Updated: 2024/12/29 17:20:48 by gabferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_isalpha(int cha);
int				ft_isdigit(int cha);
int				ft_isalnum(int cha);
int				ft_isascii(int cha);
int				ft_isprint(int cha);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *str, int c, size_t size);
void			ft_bzero(void *s, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t len);
void			*ft_memmove(void *dest, const void *src, size_t len);
int				ft_strlcpy(char *dst, const char *src, size_t size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_toupper(int str);
int				ft_tolower(int str);
char			*ft_strchr(const char *cha, int find);
char			*ft_strrchr(const char *cha, int find);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
void			*ft_memchr(const void *s, int c, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
char			*ft_strnstr(const char *big, const char *little, size_t size);
long			ft_atoi(const char *str);
void			*ft_calloc(size_t nitems, size_t size);
char			*ft_strdup(char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
	void (*del)(void *));

char			*get_next_line(int fd);
void			free_line(int fd);
char			*ft_line_strjoin(char *sbuffer, char *tmpline);
char			*ft_line_strchr(char *str, char c);

int				ft_max(int num_a, int num_b);
char			*ft_strsep(char **stringp, const char *delim);

#endif
