/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:49:44 by acash             #+#    #+#             */
/*   Updated: 2022/02/13 20:06:09 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_name(t_env *env, char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i < 5)
		ft_err_spl(env, "Wrong name");
	if (i == 5)
		if (path[0] == '.')
			ft_err_spl(env, "Wrong name");
	if (!path)
		ft_err_spl(env, "Wrong name");
	if (path[i - 1] != 'b' || path[i - 2] != 'u'
		|| path[i - 3] != 'c' || path[i - 4] != '.')
		ft_err_spl(env, "Wrong name");
}

int	main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	ft_init(&env);
	ft_get_instr_map(&env, argv[1]);
	env.plr.x = env.plr.x * 32 + 16;
	env.plr.y = env.plr.y * 32 + 16;
	ft_initdir(&env);
	start_game(&env);
	ft_free_all_alloc(&env);
	return (0);
}
