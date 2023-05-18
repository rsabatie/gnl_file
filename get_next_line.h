/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabatie <rsabatie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:46:03 by rafael            #+#    #+#             */
/*   Updated: 2023/05/16 20:01:07 by rsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4

char	*ft_get_next_line(int fd);
void	ft_read_file(char **txt_save, int fd);
char	*ft_create_line(char **txt_save);
void	ft_build_next(char **txt_save);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_calloc(int nmemb, int size);
void	ft_bzero(void *s, int n);
int		ft_strchr(const char *str, int c);

# endif
#endif