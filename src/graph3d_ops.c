/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph3d_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:38:26 by esupatae          #+#    #+#             */
/*   Updated: 2020/02/09 14:39:42 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	project_3d_to_2d(t_map *map)
{
	t_node	**map2d;
	t_node	**map3d;
	int 	i;
	int 	j;

	map2d = map->matrix2d;
	map3d = map->matrix3d;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map2d[i][j].x = CENT_X + 700 * map3d[i][j].x / (25 * map->scale - map3d[i][j].z);
			map2d[i][j].y = CENT_Y + 700 * map3d[i][j].y / (25 * map->scale - map3d[i][j].z);
			j++;
		}
		i++;
	}
}

static void	draw_frame(t_scope *scope, t_map *map)
{
	int 	i;
	int 	j;
	t_node	**node;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		node = map->matrix2d;
		while (j < map->col)
		{
			if (i != map->row - 1)
				draw_line(scope, node[i][j].x, node[i][j].y, node[i + 1][j].x, node[i + 1][j].y, 0xFFFFFF);
			if (j != map->col - 1)
				draw_line(scope, node[i][j].x, node[i][j].y, node[i][j + 1].x, node[i][j + 1].y, 0xFFFFFF);
			if (i != map->row - 1 && j != map->col - 1)
				draw_line(scope, node[i][j].x, node[i][j].y, node[i + 1][j + 1].x, node[i + 1][j + 1].y, 0xFFFFFF);
			if (i != map->row - 1 && j > 0)
				draw_line(scope, node[i][j].x, node[i][j].y, node[i + 1][j - 1].x, node[i + 1][j - 1].y, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void		draw_3d_obj(t_scope *scope)
{
	project_3d_to_2d(scope->map);
	draw_frame(scope, scope->map);
}

void 		render_image(t_scope *scope)
{
	clear_image(scope);
	calc_rotation(scope->mouse);
	interpolate(scope);
	draw_3d_obj(scope);
	mlx_put_image_to_window(scope->mlx_ptr, scope->win_ptr, scope->image->ptr, 0, 0);
}

void		clear_image(t_scope *scope)
{
	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
}