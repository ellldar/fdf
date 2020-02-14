/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:32:33 by esupatae          #+#    #+#             */
/*   Updated: 2020/02/07 23:32:35 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		get_direction(int n1, int n2)
{
	if (n1 > n2)
		return (-1);
	else if (n1 < n2)
		return (1);
	return (0);
}

int		is_confined(int x, int y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

int		is_endpoint(t_line *line, int x, int y)
{
	return ((x == line->x1 && y == line->y1) ||
	(x == line->x2 && y == line->y2));
}

int		calc_scale(t_scope *scope, int row, int col)
{
	float	scale_x;
	float	scale_y;
	float	scale_z;
	float	ans;

	scale_x = (float)WIDTH * 0.8 / (float)col;
	scale_y = (float)HEIGHT * 0.8 / (float)row;
	ans = scale_x < scale_y ? (int)scale_x : (int)scale_y;
	scale_z = (scope->z_range->max - scope->z_range->min) / 40;
	return (scale_z > 3 ? ans / scale_z : ans);
}

void	resize_map(t_scope *scope, int incr)
{
	int		i;
	int		j;
	t_node	**map;
	float	rescale;

	i = 0;
	map = scope->map->matrix3d;
	rescale = incr > 0 ? 1.05 : 0.95;
	while (i < scope->map->row)
	{
		j = 0;
		while (j < scope->map->col)
		{
			map[i][j].x *= rescale;
			map[i][j].y *= rescale;
			map[i][j].z *= rescale;
			j++;
		}
		i++;
	}
	render_image(scope);
}
