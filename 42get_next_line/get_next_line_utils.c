/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoprak <stoprak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:43:01 by stoprak           #+#    #+#             */
/*   Updated: 2022/12/18 17:43:04 by stoprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *snt_str, char *buff)
{
	int			i;
	int			j;
	char		*str;

	if (!snt_str)
	{
		snt_str = (char *)malloc(1 * sizeof(char));
		snt_str[0] = '\0';
	}
	if (!snt_str || !buff)
		return (NULL);
	str = (char *)malloc(ft_strlen(snt_str) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (snt_str[++i] != 0)
		str[i] = snt_str[i];
	j = -1;
	while (buff[++j] != 0)
	{
		str[i + j] = buff[j];
	}
	str[i + j] = 0;
	free(snt_str);
	return (str);
}
