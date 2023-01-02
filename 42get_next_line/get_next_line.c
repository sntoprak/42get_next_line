/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoprak <stoprak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:23:57 by stoprak           #+#    #+#             */
/*   Updated: 2022/12/18 22:13:01 by stoprak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//tonewline_in_array
char	*ft_get_line(char *snt_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!snt_str[i])
		return (NULL);
	while (snt_str[i] && snt_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (snt_str[i] && snt_str[i] != '\n')
	{
		str[i] = snt_str[i];
		i++;
	}
	if (snt_str[i] == '\n')
	{
		str[i] = snt_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//forleftchar_size_and_addmore
char	*ft_new_str(char *snt_str)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	while (snt_str[i] && snt_str[i] != '\n')
		i++;
	if (!snt_str[i])
	{
		free(snt_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(snt_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (snt_str[i])
		str[j++] = snt_str[i++];
	str[j] = '\0';
	free(snt_str);
	return (str);
}

//size-read-join
char	*ft_read_to_str(int fd, char *snt_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(snt_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		snt_str = ft_strjoin(snt_str, buff);
	}
	free(buff);
	return (snt_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*snt_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	snt_str = ft_read_to_str(fd, snt_str);
	if (!snt_str)
		return (NULL);
	line = ft_get_line(snt_str);
	snt_str = ft_new_str(snt_str);
	return (line);
}

/* int	main()
{
	int	fd = open("open.txt", O_RDONLY);
	char *a;
	while (a != 0)
	{
	printf("%s", a);
	a = get_next_line(fd);
	}
} */
