#ifndef	LIBFT_H
# define	LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>

#define	BUFFER_SIZE 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

int		ft_atoi(const char *s);
void	*ft_memset(void *str, char c, size_t l);
int		ft_strlen(char *str);
char	*ft_substr(char *str, int begg, int l);
char	**ft_strsplit(char const *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnew(size_t size);
void	ft_putstr(char const *s);
void    ft_putchar(char c);
int		ft_isspace(char c);
void	ft_strclr(char *s);
int		ft_wrdcnt(const char *str, char c);
int		ft_strexist(char *s, char c);
int		has_newline(char *str);
int		get_next_line(int fd, char **line);

#endif
