/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts.student@codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 22:15:31 by alkrusts      #+#    #+#                 */
/*   Updated: 2020/11/23 13:18:18 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_lstsize(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_putlst(t_list *list);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_putstr(const char *str);
void			ft_putchar(char c);
int				ft_intlen(int nr);
int				ft_longlen(long nr);
int				ft_compare(const char c, const char *z);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strnlen(const char *s, size_t maxlen);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr_fd(const char *str, int fd);
void			ft_bzero(void *b, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_putendl_fd(char const *s, int fd);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_itoa(int nbr);
char			*ft_uitoa(long n);
char			**ft_split(char const *s, char c);
char			**ft_free_2dim_array(char ***ptr);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_memrcpy(char *dest, const char *src, size_t x);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *src);
char			*ft_strncat(char *dest, const char *src, size_t nb);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strchr(const char *str, int c);

#endif
