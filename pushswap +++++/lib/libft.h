/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrubio <vrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:57:20 by vrubio            #+#    #+#             */
/*   Updated: 2022/03/27 13:07:02 by vrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

typedef struct s_array_info
{
	int		mean;
	int		min;
	int		max;
}				t_ainfo;

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
	bool	sorted;
	t_ainfo	*inf;
	int		c;
}				t_stack;

int		ft_atoi(const char *s);
void	ft_bzero(void *str, size_t l);
int		ft_counter(int n);
int		ft_is_n_or_a(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);
int		ft_isupper(int c);
void	*ft_memccpy(void *dest, const void *src, int c, size_t l);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, char c, size_t l);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_strlen(char *str);
char	*ft_substr(char *str, int begg, int l);
char	**ft_strsplit(char const *str, char c);
void	ft_strclr(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strnew(size_t size);
int		ft_strexist(char *s, char c);
char	*ft_str_offset(char *str, int i);
void	ft_strfree(char **str);
char	*ft_strnstr(const char	*str, const char *find, size_t len);
int		ft_wrdcnt(const char *str, char c);
int		count_words(char *str, char c);
int		has_newline(char *str);
int		get_next_line(int fd, char **line);
t_node	*ft_rt_node(int i);
t_node	*rt_ll_head(t_node *n);
t_node	*rt_ll_tail(t_node *n);
bool	ll_desc(t_stack *l);
int		ll_size(t_stack *l);
int		ll_max(t_stack *l);
void	ft_lst_clear(t_node *n);

void	ft_mmm(t_stack *l);
int		ft_check_ll(t_stack *l);
int		head_or_tail(t_stack *l, int nb);
int		*ft_opt_arr(t_stack *l, int *arr);
int		*ll_to_arr(t_stack *l, int *arr);
void	ft_ar_to_ll(t_stack *l, int *a, int size);
int		arr_sorted(int *arr, int size);
void	ptr_to_ptr(t_node *a, t_node *b);

#endif
