/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:14:08 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:14:09 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_len(char **map)
{
	int		y;
	size_t	max_len;

	y = -1;
	max_len = 0;
	while (map[++y])
		if (ft_strlen(map[y]) > max_len)
			max_len = ft_strlen(map[y]);
	return (max_len);
}

char	*get_new_elem(char *str, int len, t_env *env)
{
	int		i;
	char	*dupstr;

	i = -1;
	dupstr = malloc(len + 3);
	if (!dupstr)
		ft_err_spl(env, "failed to allocate memory");
	dupstr[0] = ' ';
	dupstr[len + 1] = ' ';
	dupstr[len + 2] = '\0';
	while (str[++i] && str[i] != '\n')
		dupstr[i + 1] = str[i];
	i++;
	while (i < len + 1)
		dupstr[i++] = ' ';
	return (dupstr);
}

void	set_first_last(t_env *env, int i, int len)
{
	char	*last;
	char	*first;
	char	**map;
	int		acc;

	first = malloc(len);
	last = malloc(len);
	map = malloc(sizeof(char *) * (i + 3));
	if (!first || !last || !map)
		ft_err_spl(env, "failed to allocate memory");
	ft_memset(last, ' ', len);
	last[len - 1] = '\0';
	ft_memset(first, ' ', len);
	first[len - 1] = '\0';
	map[i + 2] = NULL;
	map[0] = first;
	map[i + 1] = last;
	acc = -1;
	while (++acc < i)
		map[acc + 1] = ft_strdup(env->map.map[acc]);
	ft_myfree(env->map.map);
	env->map.map = map;
}

void	get_modif_map(t_env *env)
{
	int		i;
	int		len;
	char	**tmp;
	int		size;

	i = -1;
	size = 0;
	len = get_max_len(env->map.map);
	while (env->map.map[size])
		size++;
	tmp = malloc(sizeof(char *) * (size + 1));
	tmp[size] = 0;
	while (env->map.map[++i])
		tmp[i] = get_new_elem(env->map.map[i], len, env);
	ft_myfree(env->map.map);
	env->map.map = tmp;
	set_first_last(env, i, len + 2);
}

int	ft_maplen(char *lines)
{
	int	i;
	int	acc;
	int	flag;

	i = 0;
	acc = 0;
	flag = 1;
	while (lines[i] && lines[i] == '\n')
		i++;
	while (lines[i])
	{
		if (i && lines[i] == '\n' && lines[i - 1] == 'q')
		{
			lines[i] = '\n';
			flag = 0;
		}
		if (lines[i] == '\n' && flag)
		{
			lines[i] = 'q';
			acc++;
		}
		flag = 1;
		i++;
	}
	return (acc);
}
