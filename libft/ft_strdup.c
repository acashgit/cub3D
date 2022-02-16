/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/27 22:16:14 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	size;

	size = 0;
	if (!s1)
		return (NULL);
	while (s1[size])
		size++;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!(res))
		return (NULL);
	ft_strlcpy(res, s1, size + 1);
	return (res);
}
