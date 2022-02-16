/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:48:32 by acash             #+#    #+#             */
/*   Updated: 2022/02/13 19:16:54 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./minilibx_opengl/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# define SCALE 16
# define W 13
# define S 1
# define A 0
# define D 2
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef struct s_img
{
	void		*img;
	void		*img2;
	int			*data;
	int			*addr;
	int			*addr2;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}	t_img;

typedef struct s_mem
{
	char	**alloc_mem;
	char	***alloc_for_split;
}	t_mem;

typedef struct s_ceil
{
	int	r;
	int	g;
	int	b;
}	t_ceil;

typedef struct s_floor
{
	int	r;
	int	g;
	int	b;
}	t_floor;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		dwn;
	int		up;
	char	player;
	char	**map;
	t_floor	floor;
	t_ceil	ceil;
}	t_map;

typedef struct s_ray
{
	double	dirr;
	double	len;
	double	xe;
	double	ye;
	char	w_type;
	double	size;
	double	size2;
	int		flag;
}	t_ray;

typedef struct s_plr
{
	double	x;
	double	y;
	double	dir;
	double	start;
	double	end;
	double	rdir;
}	t_plr;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_mem	mem;
	t_plr	plr;
	t_img	textures[4];
	t_img	data;
	t_ray	ray;
	t_ray	*mr;
	int		size;
	int		tmp;
	int		vz_prev;
	int		vz;
	int		a;
}	t_env;

int		ft_init(t_env *env);
void	get_modif_map(t_env *env);
void	ft_check_map(t_env *env);
void	ft_check_down(t_env *env);
void	ft_check_up(t_env *env);
void	ft_check_right_side(t_env *env);
void	ft_check_left_side(t_env *env);
char	*ft_check_path(char *tmp, t_env *env);
void	ft_edit_field(t_env *env, char *tmp, char **field);
void	ft_set_inform(t_env *env, int x, int y, int *count_p);
void	set_first_last(t_env *env, int i, int len);
char	*get_new_elem(char *str, int len, t_env *env);
int		get_max_len(char **map);
void	ft_checkduplicate(t_env *env, char *instr, int index);
void	ft_check_file(t_env *env);
int		ft_maplen(char *lines);
char	*ft_del_tabs(char *lines, t_env *env);
char	**ft_getall(char *lines, t_env *env);
void	ft_get_instr(char *lines, int index, t_env *env);
void	ft_get_ceiling(t_env *env, char *tmp);
void	ft_get_floor(t_env *env, char *tmp);
void	ft_set_f_c(t_env *env);
void	ft_get_oriented(t_env *env);
int		ft_get_index(t_env *env, int i, int j);
void	ft_raycast_init(t_env *env);
int		ft_raycasting(t_env *env);
char	*ft_malloc(int size, int len, t_env *env);
int		ft_addstr_mem(t_env *env, char *str, char **splited);
char	**ft_add_string(char **arr, char *str);
int		ft_free_all_alloc(t_env *env);
void	ft_error_read(char *str);
void	ft_err_spl(t_env *env, char *str);
void	start_game(t_env *env);
int		keyb_hook(int key, t_env *env);
int		end_hook(t_env *env);
void	ft_draw_wall(t_env *env);
void	ft_get_instr_map(t_env *env, char *file);
void	ft_move(t_env *env, int code);
void	ft_strafe(t_env *env, int code);
void	ft_rotate(t_env *env, int code);
void	ft_ray(t_env *env);
void	ft_repixput(t_env *env, int x, int y);
void	ft_error(void);
int		check_wall(t_env *env, double dir, int code);
void	ft_initdir(t_env *env);
void	ft_initmr(t_env *env);
void	set_size(t_env *env, int i);
void	ft_init_helpre(t_env *env);
void	check_map_name(t_env *env, char *path);

#endif
