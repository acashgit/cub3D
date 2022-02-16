/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:37:05 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 21:44:24 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char	*ft_strchr_gnl(char *s, int c)
{
	while (s && *s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	acc;

	acc = 0;
	while (s && s[acc])
		acc++;
	return (acc);
}

char	*read_file(char *residue, int fd)
{
	int		ret;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	buff[BUFFER_SIZE] = '\0';
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret && !ft_strchr_gnl(residue, '\n'))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = '\0';
		residue = ft_strjoin_gnl(residue, buff);
	}
	free(buff);
	return (residue);
}

char	*get_next_line(int fd)
{
	static char	*residue;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	residue = read_file(residue, fd);
	line = get_result(residue);
	residue = get_residue(residue);
	return (line);
}
