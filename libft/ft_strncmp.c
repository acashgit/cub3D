/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/04 12:20:42 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	if (!s1 || !s2)
	{
		if ((!s1 && s2) || (!s2 && s1))
			return (1);
		else
			return (0);
	}
	while (sc1[i] && sc2[i] && i < n)
	{
		if (sc1[i] == sc2[i])
			i++;
		else
			return (sc1[i] - sc2[i]);
	}
	if (i == n)
		return (0);
	return (sc1[i] - sc2[i]);
}
