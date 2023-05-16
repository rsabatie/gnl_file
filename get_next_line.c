/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:46:09 by rafael            #+#    #+#             */
/*   Updated: 2023/05/15 22:37:42 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_file(char **txt_save, fd)
{
	int	i;
	char buffer[BUFFER_SIZE + 1];

	if (!txt_save)
		*
	i = 1;
	if (i < 0 && !*txt_save)
	{
		free(&txt_save);
		break ;
	}
	while (i > 0)
	{
	ft_bzero(buffer, BUFFER_SIZE + 1);
	i = read(fd, buffer, BUFFER_SIZE);
	*txt_save = ft_strjoin(*txt_save, buffer);
	}
}

char	*ft_make_line(char **txt_save)
{
	int	i;
	char *line;

	i = 0;
	while (txt_save[i] && *txt_save[i] != '\n')
		i++;
	if (*txt_save[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (free(txt_save), NULL);
	i = 0;
	while (txt_save[i])
	{
		if (*txt_save[i++] == '\n')
		{
			line[i] = *txt_save[i]
			return (line);
		}
		line[i] = *txt_save[i];
		i++;
	}
	return (line);
}

void	ft_build_next(char **txt_save)
{
	char *tmp;
	
	tmp = ft_strdup(*txt_save);
	
}

int main(void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("\n1st line : \ns\n\n", ft_get_next_line(fd));
	printf("\n2nd line : \ns\n\n", ft_get_next_line(fd));
	printf("\n3rd line : \ns\n\n", ft_get_next_line(fd));
	printf("\n4th line : \ns\n\n", ft_get_next_line(fd));
	printf("\n5th line : \ns\n\n", ft_get_next_line(fd));
	close(fd);
	return (0);
}
