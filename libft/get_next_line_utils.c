/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:37:38 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/07 19:17:24 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		n;

	if (!(s2))
		return (NULL);
	res = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!(res))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
		res[i++] = s2[n++];
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}

char	*ft_strdup_gnl(char *s1)
{
	char	*res;
	size_t	size;
	int		i;

	size = 0;
	while (s1[size])
		size++;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!(res))
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;
	size_t		len_str;

	i = 0;
	if (!(s))
		return (NULL);
	len_str = ft_strlen_gnl(s);
	if (start >= len_str)
		return (ft_strdup_gnl(""));
	if (len >= ft_strlen_gnl(s + start))
		res = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s + start) + 1));
	else
		res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	while (i < len && i < len_str)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_result(char *line)
{
	char		*res;
	int			i;

	i = 0;
	res = NULL;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		res = ft_substr_gnl(line, 0, i + 1);
	else if (line[0])
		res = ft_substr_gnl(line, 0, i);
	return (res);
}

char	*get_residue(char *line)
{
	char		*res;
	int			i;

	i = 0;
	res = NULL;
	if (!line)
		return (NULL);
	while (line[i])
		if (line[i++] == '\n')
			break ;
	if (ft_strchr_gnl(line, '\n'))
		res = ft_substr_gnl(line, i, ft_strlen_gnl(line + i));
	free(line);
	return (res);
}
