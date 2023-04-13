/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldifino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:49:19 by ldifino           #+#    #+#             */
/*   Updated: 2023/04/13 20:53:20 by ldifino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

size_t	ft_strlen(char *str);
char	*ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_write(char *str);
char	*ft_reset(char *str);
char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);
#endif
