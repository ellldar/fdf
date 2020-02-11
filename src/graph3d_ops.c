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

void	draw_3d_obj(t_scope *scope, t_map *map)
{
	int center_x;
	int center_y;
	int i, j;
	int x;
	int y;
	t_node	*node;

	center_x = scope->width / 2;
	center_y = scope->height / 2;
	i = 0;
	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
	while (i < map->row)
	{
		j = 0;
		node = map->matrix2d[i];
		while (j < map->col)
		{
			x = (center_x - (map->col * map->scale / 2) + node[j].x * map->scale);
			y = (center_y - (map->row * map->scale / 2) + node[j].y * map->scale);
			if (i != map->row - 1)
				draw_line(scope, x, y, x, y + map->scale, 0xFFFFFF);
			if (j != map->col - 1)
				draw_line(scope, x, y, x + map->scale, y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	render_image(scope);
}

void	interpolate(t_scope *scope, t_map *map, int x1, int y1)
{

}