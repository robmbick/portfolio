/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:52:20 by bnetschu          #+#    #+#             */
/*   Updated: 2019/03/07 11:46:49 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_mlist
{
	char			*content;
	int				fd;
	struct s_mlist	*next;
}				t_mlist;
typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
char			*ft_concat_params(int argc, char **argv);
void			ft_cat(int argc, char **argv);
int				ft_sqrt(int nb);
void			ft_str_capitalizer(int argc, char **argv);
int				ft_strword(char *s, char c);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list			*ft_lstnew(void	const	*content, size_t content_size);
void			ft_strclr(char *s);
void			*ft_memccpy(void *dst, const void *src,
		int c, size_t n);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalpha(int c);
void			*ft_memchr(const void *s, int ch, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src,
		size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *str, int ch);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *source);
char			*ft_strdup(const char *src);
size_t			ft_strlcat(char *dest, const char *src,
		size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *dest, const char *src,
		size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *str, int ch);
char			*ft_strstr(const char *str, const char *to_find);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int nb);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				get_next_line(const int fd, char **line);
#endif
