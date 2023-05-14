/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:46:09 by rafael            #+#    #+#             */
/*   Updated: 2023/05/14 20:41:08 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_read_file(char **txt_save, fd)
{
	int	i;
	char buffer[BUFFER_SIZE + 1];

	i = 1;
	if (i < 0 && !*txt_save)
	{
		free(&txt_save);
		break ;
	}
	while (i > 0)
	{
	ft_bzero(buffer, BUFFER_SIZE);
	i = read(fd, buffer, BUFFER_SIZE);
	*txt_save = ft_strjoin(*txt_save, buffer);
	}
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
