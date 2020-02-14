/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:30:49 by esupatae          #+#    #+#             */
/*   Updated: 2020/02/14 03:30:53 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			validate_points(t_line *line)
{
	if (is_confined(line->x1, line->y1) || is_confined(line->x2, line->y2))
		return (1);
	return (0);
}

t_line		*make_line(t_line *line, t_node node1, t_node node2)
{
	line->x1 = node1.x;
	line->y1 = node1.y;
	line->x2 = node2.x;
	line->y2 = node2.y;
	line->valid = node1.z > 0 ? 1 : 0;
	return (line);
}

float		get_2d_coord(t_map *map, int center, float axis, float z)
{
	int		persp;
	int		scale;
	int		denom;
	float	ans;

	persp = map->persp;
	scale = map->scale;
	denom = (persp * scale - z);
	denom = denom == 0 ? 1 : denom;
	ans = center + scale * persp * axis / denom;
	return (ans);
}
