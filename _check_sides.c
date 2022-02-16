/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _check_sides.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:12:07 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:12:07 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_forbidden_simb(char c)
{
	if ((c == '0' || c == 'N' \
	|| c == 'S' || c == 'W' \
	|| c == 'E'))
		return (1);
	return (0);
}

void	ft_check_left_side(t_env *env)
{
	int	x;
	int	y;
	int	max_x;

	y = 0;
	max_x = 0;
	while (env->map.map[y][max_x])
		max_x++;
	y = -1;
	while (env->map.map[++y])
	{
		x = -1;
		while (++x < max_x - 1)
		{
			if (env->map.map[y][x] == ' ')
			{
				if (ft_check_forbidden_simb(\
				env->map.map[y][x + 1]))
					ft_err_spl(env, "hole in the left wall");
			}
		}
	}
}

void	ft_check_right_side(t_env *env)
{
	size_t	x;
	int		y;

	y = -1;
	while (env->map.map[++y])
	{
		x = ft_strlen(env->map.map[y]);
		while (x >= 1)
		{
			if (env->map.map[y][x] == ' ')
			{
				if (ft_check_forbidden_simb(\
				env->map.map[y][x - 1]))
					ft_err_spl(env, "hole in the right wall");
			}
			x--;
		}
	}
}

void	ft_check_up(t_env *env)
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
		y = -1;
		while (++y < max_y - 1)
		{
			if (env->map.map[y][x] == ' ')
			{
				if (ft_check_forbidden_simb(\
				env->map.map[y + 1][x]))
					ft_err_spl(env, "hole in the upper wall");
			}
		}
	}
}

void	ft_check_down(t_env *env)
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
		y = max_y;
		while (--y > 0)
		{
			if (env->map.map[y][x] == ' ')
			{
				if (ft_check_forbidden_simb(\
				env->map.map[y - 1][x]))
					ft_err_spl(env, "hole in the bottom wall");
			}
		}
	}
}
