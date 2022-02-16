/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _malloc_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:14:01 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/13 19:14:01 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_add_string(char **arr, char *str)
{
	int		n;
	char	**result;

	n = 0;
	while (arr && arr[n])
		n++;
	result = ft_calloc(n + 1 + (str != NULL), sizeof(char *));
	if (!result)
		return (NULL);
	result[n + (str != NULL)] = NULL;
	n = 0;
	while (arr && arr[n])
	{
		result[n] = arr[n];
		n++;
	}
	if (str)
		result[n] = str;
	if (arr)
		free(arr);
	return (result);
}

char	***ft_add_splited(char ***arr, \
	char **splited)
{
	int		n;
	char	***result;

	n = 0;
	while (arr && arr[n])
		n++;
	result = ft_calloc(n + 1 + (splited != NULL), sizeof(char **));
	if (!result)
		return (NULL);
	result[n + (splited != NULL)] = NULL;
	n = 0;
	while (arr && arr[n])
	{
		result[n] = arr[n];
		n++;
	}
	if (splited)
		result[n] = splited;
	if (arr)
		free(arr);
	return (result);
}

int	ft_addstr_mem(t_env *env, char *str, char **splited)
{
	char	**res;
	char	***res2;

	if (str)
	{
		res = ft_add_string(env->mem.alloc_mem, str);
		if (!res)
			return (0);
		env->mem.alloc_mem = res;
	}
	if (splited)
	{
		res2 = ft_add_splited(env->mem.alloc_for_split, splited);
		if (!res2)
			return (0);
		env->mem.alloc_for_split = res2;
	}
	return (1);
}

char	*ft_malloc(int size, int len, t_env *env)
{
	char	**res;
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(len, size);
	if (!str)
		return (NULL);
	res = ft_add_string(env->mem.alloc_mem, str);
	env->mem.alloc_mem = res;
	while (res[i])
		i++;
	return (res[i - 1]);
}

int	ft_free_all_alloc(t_env *env)
{
	int	i;

	i = 0;
	if (env->mem.alloc_mem)
	{
		while (env->mem.alloc_mem[i])
			free(env->mem.alloc_mem[i++]);
		free(env->mem.alloc_mem);
	}
	if (env->map.map)
		ft_myfree(env->map.map);
	return (1);
}
