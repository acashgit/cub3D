/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/07 19:16:56 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;
	size_t		len_str;

	i = 0;
	if (!(s))
		return (NULL);
	len_str = ft_strlen(s);
	if (start >= len_str)
		return (ft_calloc(1, 1));
	if (len >= ft_strlen(s + start))
		res = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
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
