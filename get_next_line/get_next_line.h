/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiteri <lspiteri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:12:51 by lspiteri          #+#    #+#             */
/*   Updated: 2025/01/16 19:40:56 by lspiteri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# if BUFFER_SIZE > 8000000 || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

void	ft_free(char **str);
ssize_t	ft_strlen(const char *s);
ssize_t	ft_findchr(const char *str0, int c0);
ssize_t	ft_strlcpy(char *dst0, const char *src0, ssize_t dstsize);
void	ft_bzero(void *s, ssize_t n);

#endif
