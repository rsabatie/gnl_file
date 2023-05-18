/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabatie <rsabatie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:46:09 by rafael            #+#    #+#             */
/*   Updated: 2023/05/18 18:39:24 by rsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_read_file(char **txt_save, int fd)
{
	int	i;
	char buffer[BUFFER_SIZE + 1];

	i = 1;
	if (!*txt_save)
		*txt_save = ft_calloc(1, sizeof(char));
	while (i > 0 && ft_strchr(*txt_save, '\n') == 0)
	{
	ft_bzero(buffer, BUFFER_SIZE + 1);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i < 0)
	{
		free(txt_save);
		break ;
	}
	*txt_save = ft_strjoin(*txt_save, buffer);
	}
}

static char	*ft_create_line(char *txt_save)
{
	int		i;
	char	*line;

	i = 0;
	while (txt_save[i] && txt_save[i] != '\n')
		i++;
	if (txt_save[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(txt_save), NULL);
	i = 0;
	while (txt_save[i])
	{
		if (txt_save[i] == '\n')
		{
			line[i] = txt_save[i];
			return (line);
		}
		line[i] = txt_save[i];
		i++;
	}
	return (line);
}

static void	ft_build_next(char **txt_save)
{
	char	*tmp;
	int		i;
	int		j;
	int		len_alloc;
	
	tmp = ft_strdup(*txt_save);
	free(*txt_save);
	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	len_alloc = ft_strlen(tmp) - i;
	*txt_save = ft_calloc(len_alloc + 1, sizeof(char));
	if (!txt_save)
		return ;
	while (tmp[i + j])
	{
		(*txt_save)[j] = tmp[i + j];
		j++;
	}
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char *txt_save;
	char		*line;
	
	line = NULL;
	if (fd < 0)
		return (free(txt_save), free(line), NULL);
	ft_read_file(&txt_save, fd);
	line = ft_create_line(txt_save);
	ft_build_next(&txt_save);
	return (line);
}

int ft_strchr(const char *str, int c)
{
	int		i;
	char	*buffer;

	buffer = (char *)str;
	i = 0;
	c = (char)c;
	if (!str)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	int fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("\n1st line : \n%s\n\n", get_next_line(fd));
// 	printf("\n2nd line : \n%s\n\n", get_next_line(fd));
// 	printf("\n3rd line : \n%s\n\n", get_next_line(fd));
// 	printf("\n4th line : \n%s\n\n", get_next_line(fd));
// 	printf("\n5th line : \n%s\n\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }