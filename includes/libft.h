/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:50:45 by dwuthric          #+#    #+#             */
/*   Updated: 2022/07/11 22:00:17 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isxdigit(int c);
int		ft_isgraph(int c);
int		ft_isspace(int c);
int		ft_ispunct(int c);
int		ft_iscntrl(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

int		ft_atoi(char *str);
void	*ft_calloc(size_t n, size_t size);

void	*ft_memset(void *ptr, int c, size_t n);
void	ft_bzero(void *ptr, size_t n);
void	*ft_memchr(const void *ptr, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlen_2(const char **list);

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char *s);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int from, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char *str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_list	*ft_lstnew(void	*content);
void	ft_lstadd_front(t_list **list, t_list *new_node);
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **list, t_list *new_node);
void	ft_lstdelone(t_list *list, void (*del)(void *));
void	ft_lstclear(t_list **list, void (*del)(void *));
void	ft_lstiter(t_list *list, void (*f)(void *));
t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *));

#endif
