/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:56:05 by lspiteri          #+#    #+#             */
/*   Updated: 2025/05/20 01:17:45 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_realloc(char *str, int size);
int		ft_isalnum(int var);
int		ft_isalpha(int str);
int		ft_isascii(int var);
int		ft_isdigit(int num);
int		ft_isprint(int var);
char	*ft_itoa(int n0);
void	*ft_memchr(const void *str0, int c0, size_t n);
int		ft_memcmp(const void *first0, const void *second0, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst0, const void *src0, size_t len);
void	*ft_memset(void *b0, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);
char	**ft_split(const char *s, char c);
void	ft_free_arrstr(char ***arr, int i);
char	*ft_strchr(const char *str0, int c);
int		ft_findchr(const char *str, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst0, const char *src0, size_t dstsize);
size_t	ft_strlcpy(char *dst0, const char *src0, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str0, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c0);
int		ft_toupper(int c0);

#endif
