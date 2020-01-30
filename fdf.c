/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 00:53:12 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/18 00:54:35 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_hooks(t_scope *scope, t_key *key, t_mouse *mouse)
{
	mlx_do_key_autorepeatoff(scope->mlx_ptr);
	mlx_hook(scope->win_ptr, 2, 0, key_press, scope);
	mlx_hook(scope->win_ptr, 3, 0, key_release, scope);
	mlx_hook(scope->win_ptr, 4, 0, mouse_press, scope);
	mlx_hook(scope->win_ptr, 5, 0, mouse_release, scope);
	mlx_hook(scope->win_ptr, 6, 0, motion_track, scope);
	mlx_hook(scope->win_ptr, 12, 0, expose_hook, scope);
	mlx_hook(scope->win_ptr, 17, 0, exit_hook, scope);
}

static void	init_event_handler(t_scope *scope)
{
	void	*img_ptr;
	t_key	*key;
	t_mouse	*mouse;

	img_ptr = mlx_new_image(mlx_ptr, win_ptr, 1200, 800);
	scope->img_ptr = img_ptr;
	init_hooks(scope, key, mouse);
}

int			main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int 	fd;
	int 	***data;
	t_scope	*scope;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) <= 0)
			return (0);
		data = read_data(fd);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 1200, 800, "FDF");
		scope = init_scope(mlx_ptr, wintr, 600, 400);
		init_event_handler(scope);
		mlx_loop(mlx_ptr);
	}
	else
		ft_putstr("usage: ./fdf [source_file]\n");
	return (0);
}
