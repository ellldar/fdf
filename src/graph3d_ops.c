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

static void	project_3d_to_2d(t_scope *scope, t_map *map)
{
	t_node	**map2d;
	t_node	**map3d;
	int		size;

	size = map->row * map->col;
	map2d = ft_memcpy(map2d, map3d, sizeof(t_node) * size);
}

static void	draw_frame(t_scope *scope, t_map *map)
{
	int 	i;
	int 	j;
	t_node	*node;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		node = map->matrix2d[i];
		while (j < map->col)
		{
			if (i != map->row - 1)
				draw_line(scope, node[j].x, node[j].y, node[j].x, node[j + 1].y, 0xFFFFFF);
			if (j != map->col - 1)
				draw_line(scope, node[j].x, node[j].y, node[j + 1].x, node[j].y, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void		draw_3d_obj(t_scope *scope)
{
	t_map	*map;

	map = scope->map;
	clear_image(scope);
	project_3d_to_2d(scope, map);
	draw_frame(scope, map);
	render_image(scope);
}

void 		render_image(t_scope *scope)
{
	t_image	*img;

	img = scope->image;
	mlx_put_image_to_window(scope->mlx_ptr, scope->win_ptr, img->ptr, 0, 0);
}

void		clear_image(t_scope *scope)
{
	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
}