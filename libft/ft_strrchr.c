/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/07 19:16:16 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_copy;

	s_copy = s;
	while (*s_copy != '\0')
		s_copy++;
	while (s_copy != s)
	{
		if (*s_copy == (unsigned char)c)
			return ((char *)s_copy);
		s_copy--;
	}
	if (*s_copy == (unsigned char)c)
		return ((char *)s_copy);
	return (NULL);
}
