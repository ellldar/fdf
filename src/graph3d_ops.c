/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph3d_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:38:26 by esupatae          #+#    #+#             */
/*   Updated: 2020/02/14 12:04:19 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	project_3d_to_2d(t_map *map)
{
	t_node	**map2d;
	t_node	**map3d;
	int		i;
	int		j;
	int		p;

	map2d = map->matrix2d;
	map3d = map->matrix3d;
	p = map->persp;
	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			map2d[i][j].x = get_2d_coord(map, map->cent_x,
					map3d[i][j].x, map3d[i][j].z);
			map2d[i][j].y = get_2d_coord(map, map->cent_y,
					map3d[i][j].y, map3d[i][j].z);
			map2d[i][j].z = map3d[i][j].z < map->scale * p ? 1 : 0;
			j++;
		}
		i++;
	}
}

static void	draw_frame(t_scope *scope, t_map *map)
{
	int		i;
	int		j;
	t_node	**pt;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		pt = map->matrix2d;
		while (++j < map->col)
		{
			if (i != map->row - 1)
				draw_line(scope, make_line(scope->line,
						pt[i][j], pt[i + 1][j]));
			if (j != map->col - 1)
				draw_line(scope, make_line(scope->line,
						pt[i][j], pt[i][j + 1]));
			if (i != map->row - 1 && j != map->col - 1)
				draw_line(scope, make_line(scope->line, pt[i][j],
						pt[i + 1][j + 1]));
			if (i != map->row - 1 && j > 0)
				draw_line(scope, make_line(scope->line, pt[i][j],
						pt[i + 1][j - 1]));
		}
	}
}

void		draw_3d_obj(t_scope *scope)
{
	int	x;

	project_3d_to_2d(scope->map);
	draw_frame(scope, scope->map);
}

void		render_image(t_scope *scope)
{
	t_mouse	*mouse;

	clear_image(scope);
	mouse = scope->mouse;
	mouse->rot_y = (float)(get_direction(mouse->x2, mouse->x1)) / 20.0;
	mouse->rot_x = (float)(get_direction(mouse->y1, mouse->y2)) / 20.0;
	interpolate(scope);
	draw_3d_obj(scope);
	mlx_put_image_to_window(scope->mlx_ptr, scope->win_ptr,
			scope->image->ptr, 0, 0);
}

void		clear_image(t_scope *scope)
{
	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
}
