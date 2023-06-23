/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:56:03 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/13 20:53:34 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

size_t	lstrlen(char *str);
char	*lstrchr(char *s);
char	*lstrjoin(char *s1, char *s2);
char	*ft_write(char *str);
char	*ft_reset(char *str);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
#endif
