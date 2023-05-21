/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabatie <rsabatie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:46:09 by rafael            #+#    #+#             */
/*   Updated: 2023/05/21 17:19:27 by rsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_file(char *txt_save, int fd)
{
	int		i;
	char	buffer[BUFFER_SIZE + 1];
	char	*update;

	if (!txt_save)
		txt_save = ft_calloc(1, sizeof(char));
	update = ft_strdup(txt_save);
	i = 1;
	while (i > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(update), NULL);
		update = ft_strjoin(update, buffer);
		if (update[0] == '\0')
			return (free(update), NULL);
		if (ft_strchr(update, '\n') > 0)
			break ;
	}
	return (update);
}

static char	*ft_create_line(char *txt_save)
{
	int		i;
	char	*line;

	if (!txt_save)
		return (NULL);
	if (ft_strchr(txt_save, '\n') > 0)
		i = ft_strchr(txt_save, '\n');
	else
		i = ft_strlen(txt_save);
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

static char	*ft_build_next(char *txt_save)
{
	char	*tmp;
	int		i;
	int		j;

	if (!txt_save)
		return (NULL);
	tmp = ft_strdup(txt_save);
	if (ft_strchr(tmp, '\n') > 0)
		i = ft_strchr(tmp, '\n');
	else
		i = ft_strlen(tmp);
	txt_save = ft_calloc((ft_strlen(tmp) - i) + 1, sizeof(char));
	if (!txt_save && tmp)
		return (free(tmp), NULL);
	j = 0;
	while (tmp[i + j])
	{
		txt_save[j] = tmp[i + j];
		j++;
	}
	free(tmp);
	return (txt_save);
}

char	*get_next_line(int fd)
{
	static char	*txt_save[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(txt_save[fd]);
		txt_save[fd] = NULL;
		return (NULL);
	}
	txt_save[fd] = ft_read_file(txt_save[fd], fd);
	if (!txt_save[fd])
		return (NULL);
	if (txt_save[fd][0] == '\0')
		return (free(txt_save[fd]), NULL);
	line = ft_create_line(txt_save[fd]);
	txt_save[fd] = ft_build_next(txt_save[fd]);
	return (line);
}

int	ft_strchr(const char *str, int c)
{
	int		i;
	char	*buffer;

	buffer = (char *)str;
	i = 0;
	c = (char)c;
	if (!str)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == c)
		{
			i++;
			return (i);
		}
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