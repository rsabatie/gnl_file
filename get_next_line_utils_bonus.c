/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabatie <rsabatie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:46:12 by rafael            #+#    #+#             */
/*   Updated: 2023/05/21 17:14:50 by rsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s1_et_s2;

	if (!s1 || !s2)
		return (NULL);
	s1_et_s2 = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s1_et_s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s1_et_s2[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		s1_et_s2[i + j] = s2[j];
		j++;
	}
	return (s1_et_s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	free (s1);
	res[i] = '\0';
	return (res);
}

void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;

	if ((nmemb * size) == 0 && nmemb != 0 && size != 0)
		return (0);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, size * nmemb);
	return (ptr);
}

void	ft_bzero(void *s, int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		*ptr = '\0';
		ptr++;
	}
}
