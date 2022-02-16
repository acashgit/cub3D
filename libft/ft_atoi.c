/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/09 21:05:34 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_paces(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	get_max_min(int currentValue, int currNum, int sign)
{
	if ((currentValue > 214748364)
		|| (currentValue == 214748364 && currNum > 8))
	{
		if (sign > 0)
			return (-1);
		if (sign < 0)
			return (0);
	}
	if (currentValue <= 214748364 && currNum <= 7)
		return ((currentValue * 10 + currNum) * sign);
	if (currentValue == 214748364 && currNum == 8)
	{
		if (sign > 0)
			return ((currentValue * 10 + 7) * sign);
		if (sign < 0)
			return ((currentValue * 10 + currNum) * sign);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	value;
	int	sign;

	sign = 1;
	value = 0;
	while (ft_is_paces(*str) && *str != '\0')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = sign * (-1);
	if (!*str)
		return (-1);
	if (*str >= '0' && *str <= '9')
	{
		while (*str && (*str >= '0' && *str <= '9'))
		{
			if (value <= 214748364)
				value = value * 10 + (*str - '0');
			else
				return (value = get_max_min(value, *str - '0', sign));
			str++;
		}
	}
	return (value * sign);
}
