/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_oriented.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:13:56 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:13:56 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_right_side(t_env *env)
{
	int	x;
	int	y;
	int	max_x;

	y = 0;
	max_x = ft_strlen(env->map.map[y]);
	y = -1;
	while (env->map.map[++y])
	{
		x = 0;
		while (++x < max_x - 1)
		{
			if (env->map.map[y][x] == '1')
			{
				if (env->map.map[y][x - 1] == '0')
					env->map.map[y][x] = 'W';
			}
		}
	}
}

void	ft_set_left_side(t_env *env)
{
	size_t	x;
	int		y;

	y = -1;
	while (env->map.map[++y])
	{
		x = ft_strlen(env->map.map[y]) - 1;
		while (x >= 1)
		{
			if (env->map.map[y][x] == '1')
			{
				if (env->map.map[y][x + 1] == '0')
					env->map.map[y][x] = 'E';
			}
			x--;
		}
	}
}

void	ft_set_down(t_env *env)
{
	size_t	x;
	int		y;
	int		max_y;
	size_t	max_len;

	max_y = 0;
	while (env->map.map[max_y])
		max_y++;
	x = -1;
	max_len = ft_strlen(env->map.map[0]);
	while (++x < max_len - 1)
	{
		y = 0;
		while (++y < max_y - 1)
		{
			if (env->map.map[y][x] == '1')
			{
				if (env->map.map[y - 1][x] == '0')
					env->map.map[y][x] = 'N';
			}
		}
	}
}

void	ft_set_up(t_env *env)
{
	size_t	x;
	int		y;
	int		max_y;
	size_t	max_len;

	max_y = 0;
	while (env->map.map[max_y])
		max_y++;
	x = -1;
	max_len = ft_strlen(env->map.map[0]);
	while (++x < max_len - 1)
	{
		y = max_y - 1;
		while (--y > 0)
		{
			if (env->map.map[y][x] == '1')
			{
				if (env->map.map[y + 1][x] == '0')
					env->map.map[y][x] = 'S';
			}
		}
	}
}

void	ft_get_oriented(t_env *env)
{
	ft_set_right_side(env);
	ft_set_left_side(env);
	ft_set_down(env);
	ft_set_up(env);
}
