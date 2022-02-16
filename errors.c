/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acash <acash@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:48:17 by acash             #+#    #+#             */
/*   Updated: 2022/02/10 15:48:26 by acash            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(void)
{
	ft_putstr_fd("Error.\n", 1);
	exit(1);
}

void	ft_error_read(char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("Error.\n", 1);
	exit(1);
}

void	ft_err_spl(t_env *env, char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	ft_free_all_alloc(env);
	exit(1);
}
