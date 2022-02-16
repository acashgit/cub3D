/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/07 19:15:55 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	i;

	len_needle = ft_strlen(needle);
	i = 0;
	if (len_needle > ft_strlen(haystack))
		return (NULL);
	if (len_needle == 0)
		return ((char *)&haystack[i]);
	if (len == 0)
		return (NULL);
	while (i <= (len - len_needle) && haystack[i])
	{
		if (ft_strncmp(&haystack[i], needle, len_needle) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
