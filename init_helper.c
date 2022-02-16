/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:13:59 by acash             #+#    #+#             */
/*   Updated: 2022/02/13 17:15:36 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_helpre(t_env *env)
{
	env->data.addr2 = NULL;
	env->data.addr = NULL;
	env->data.data = NULL;
	env->data.img2 = NULL;
	env->data.img = NULL;
	env->textures[0].addr2 = NULL;
	env->textures[1].addr2 = NULL;
	env->textures[2].addr2 = NULL;
	env->textures[3].addr2 = NULL;
	env->textures[0].addr = NULL;
	env->textures[1].addr = NULL;
	env->textures[2].addr = NULL;
	env->textures[3].addr = NULL;
	env->textures[0].data = NULL;
	env->textures[1].data = NULL;
	env->textures[2].data = NULL;
	env->textures[3].data = NULL;
	env->textures[0].img2 = NULL;
	env->textures[1].img2 = NULL;
	env->textures[2].img2 = NULL;
	env->textures[3].img2 = NULL;
	env->textures[0].img = NULL;
	env->textures[1].img = NULL;
	env->textures[2].img = NULL;
	env->textures[3].img = NULL;
}
