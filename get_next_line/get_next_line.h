/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkryvono <dkryvono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:00:00 by dkryvono          #+#    #+#             */
/*   Updated: 2026/10/26 15:00:00 by dkryvono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		ft_set_end(char *buffer);
size_t	ft_line_count(char *stash);
char	*ft_create_stash(char *stash, size_t line_size);

#endif
