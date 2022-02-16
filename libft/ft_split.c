/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/07 19:15:10 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_count(char *s, char c, int length)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (i <= length)
	{
		if ((s[i] == c || (s[i] == '\0' && s[i - 1] != c)) && flag)
		{
			flag = 0;
			count++;
		}
		if (s[i] != c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	prov_mem(char **res, char *s, char c, int length)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (length >= 0)
	{
		if ((*s == c || (*s == '\0' && *(s - 1) != c)) && flag)
		{
			flag = 0;
			*res = ft_calloc(count + 1, 1);
			if (!(*res))
				return (0);
			res++;
			count = 0;
		}
		if (*s != c)
		{
			flag = 1;
			count++;
		}
		s++;
		length--;
	}
	return (1);
}

static void	ft_fill(char **res, char *s, char c)
{
	int	i;
	int	n;

	n = 0;
	while (res[n])
	{
		i = 0;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			res[n][i] = *s;
			i++;
			s++;
		}
		n++;
	}
}

char	**ft_myfree(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	if (res)
		free(res);
	return (NULL);
}

char	**ft_split(char *s1, char c)
{
	int		count;
	char	**res;
	int		length;

	if (!s1)
		return (NULL);
	if (!(*s1) || !(s1))
	{
		res = (char **)malloc(sizeof(char *));
		if (!res)
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	length = ft_strlen(s1);
	count = ft_get_count(s1, c, length);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	res[count] = NULL;
	if (!(prov_mem(res, s1, c, length)))
		return (ft_myfree(res));
	else
		ft_fill(res, s1, c);
	return (res);
}
