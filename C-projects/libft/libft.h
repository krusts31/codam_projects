/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                             :+:    :+:           */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts.student@codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 22:15:31 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/05/29 01:08:37 by alkrusts        ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <emscripten.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

EMSCRIPTEN_KEEPALIVE int				ft_lstsize(t_list *lst);
EMSCRIPTEN_KEEPALIVE t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
EMSCRIPTEN_KEEPALIVE void			ft_lstiter(t_list *lst, void (*f)(void *));
EMSCRIPTEN_KEEPALIVE void			ft_lstclear(t_list **lst, void (*del)(void*));
EMSCRIPTEN_KEEPALIVE void			ft_lstadd_back(t_list **lst, t_list *new);
EMSCRIPTEN_KEEPALIVE void			ft_lstdelone(t_list *lst, void (*del)(void*));
EMSCRIPTEN_KEEPALIVE void			ft_putlst(t_list *list);
EMSCRIPTEN_KEEPALIVE void			ft_lstadd_front(t_list **lst, t_list *new);
EMSCRIPTEN_KEEPALIVE t_list			*ft_lstnew(void *content);
EMSCRIPTEN_KEEPALIVE t_list			*ft_lstlast(t_list *lst);
EMSCRIPTEN_KEEPALIVE void			ft_putstr(const char *str);
EMSCRIPTEN_KEEPALIVE void			ft_putchar(char c);
EMSCRIPTEN_KEEPALIVE int				ft_intlen(int nr);
EMSCRIPTEN_KEEPALIVE int				ft_longlen(long nr);
EMSCRIPTEN_KEEPALIVE int				ft_compare(const char c, const char *z);
EMSCRIPTEN_KEEPALIVE int				ft_atoi(const char *nptr);
EMSCRIPTEN_KEEPALIVE int				ft_isdigit(int c);
EMSCRIPTEN_KEEPALIVE int				ft_isalnum(int c);
EMSCRIPTEN_KEEPALIVE int				ft_isascii(int c);
EMSCRIPTEN_KEEPALIVE int				ft_isprint(int c);
EMSCRIPTEN_KEEPALIVE int				ft_isalpha(int c);
EMSCRIPTEN_KEEPALIVE int				ft_toupper(int c);
EMSCRIPTEN_KEEPALIVE int				ft_tolower(int c);
EMSCRIPTEN_KEEPALIVE int				ft_strcmp(const char *s1, const char *s2);
EMSCRIPTEN_KEEPALIVE int				ft_strncmp(const char *s1, const char *s2, size_t n);
EMSCRIPTEN_KEEPALIVE int				ft_memcmp(const void *s1, const void *s2, size_t n);
EMSCRIPTEN_KEEPALIVE size_t			ft_strnlen(const char *s, size_t maxlen);
EMSCRIPTEN_KEEPALIVE size_t			ft_strlcat(char *dest, const char *src, size_t size);
EMSCRIPTEN_KEEPALIVE size_t			ft_strlen(const char *str);
EMSCRIPTEN_KEEPALIVE size_t			ft_strlcpy(char *dst, const char *src, size_t size);
EMSCRIPTEN_KEEPALIVE void			ft_putchar_fd(char c, int fd);
EMSCRIPTEN_KEEPALIVE void			ft_putnbr_fd(int nb, int fd);
EMSCRIPTEN_KEEPALIVE void			ft_putstr_fd(const char *str, int fd);
EMSCRIPTEN_KEEPALIVE void			ft_bzero(void *b, size_t n);
EMSCRIPTEN_KEEPALIVE void			*ft_memcpy(void *dst, const void *src, size_t n);
EMSCRIPTEN_KEEPALIVE void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
EMSCRIPTEN_KEEPALIVE void			*ft_memmove(void *dst, const void *src, size_t len);
EMSCRIPTEN_KEEPALIVE void			*ft_calloc(size_t nmemb, size_t size);
EMSCRIPTEN_KEEPALIVE void			*ft_memchr(const void *s, int c, size_t n);
EMSCRIPTEN_KEEPALIVE void			ft_putendl_fd(char const *s, int fd);
EMSCRIPTEN_KEEPALIVE void			*ft_memset(void *s, int c, size_t n);
EMSCRIPTEN_KEEPALIVE char			*ft_itoa(int nbr);
EMSCRIPTEN_KEEPALIVE char			*ft_uitoa(long n);
EMSCRIPTEN_KEEPALIVE char			**ft_split(char const *s, char c);
EMSCRIPTEN_KEEPALIVE char			**ft_free_2dim_array(char ***ptr);
EMSCRIPTEN_KEEPALIVE char			*ft_strchr(const char *s, int c);
EMSCRIPTEN_KEEPALIVE char			*ft_strrchr(const char *s, int c);
EMSCRIPTEN_KEEPALIVE char			*ft_memrcpy(char *dest, const char *src, size_t x);
EMSCRIPTEN_KEEPALIVE char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
EMSCRIPTEN_KEEPALIVE char			*ft_strsub(char const *s, unsigned int start, size_t len);
EMSCRIPTEN_KEEPALIVE char			*ft_strjoin(char const *s1, char const *s2);
EMSCRIPTEN_KEEPALIVE char			*ft_strcpy(char *dest, const char *src);
EMSCRIPTEN_KEEPALIVE char			*ft_strdup(const char *src);
EMSCRIPTEN_KEEPALIVE char			*ft_strncat(char *dest, const char *src, size_t nb);
EMSCRIPTEN_KEEPALIVE char			*ft_strstr(const char *str, const char *to_find);
EMSCRIPTEN_KEEPALIVE char			*ft_substr(char const *s, unsigned int start, size_t len);
EMSCRIPTEN_KEEPALIVE char			*ft_strncpy(char *dest, const char *src, size_t n);
EMSCRIPTEN_KEEPALIVE char			*ft_strnstr(const char *str, const char *to_find, size_t len);
EMSCRIPTEN_KEEPALIVE char			*ft_strtrim(char const *s1, char const *set);
EMSCRIPTEN_KEEPALIVE char			*ft_strchr(const char *str, int c);
EMSCRIPTEN_KEEPALIVE char			*ft_cpystr(char *dst, const char *src);
EMSCRIPTEN_KEEPALIVE int			ft_longlen(long nr);
#endif
