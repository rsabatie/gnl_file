/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsabatie <rsabatie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:46:12 by rafael            #+#    #+#             */
/*   Updated: 2023/05/16 19:17:20 by rsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int  i;
	int  j;
	int	len1;
	int	len2;
	char	*s1_et_s2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s1_et_s2 = ft_calloc((len1 + len2 + 1), sizeof(char));
	if (!s1_et_s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s1_et_s2[i] = s1[i];
		i++;
	}
	while (s2[j])
		s1_et_s2[++i] = s2[j++];
	return (s1_et_s2);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
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