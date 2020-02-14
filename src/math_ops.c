/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:21:59 by esupatae          #+#    #+#             */
/*   Updated: 2020/02/12 18:22:18 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	apply_rotation_y(t_node *node, t_mouse *mouse)
{
	float x;
	float z;

	x = (float)node->z * sin(mouse->rot_y) + (float)node->x * cos(mouse->rot_y);
	z = (float)node->z * cos(mouse->rot_y) - (float)node->x * sin(mouse->rot_y);
	node->x = x;
	node->z = z;
}

static void	apply_rotation_x(t_node *node, t_mouse *mouse)
{
	float y;
	float z;

	y = (float)node->y * cos(mouse->rot_x) - (float)node->z * sin(mouse->rot_x);
	z = (float)node->y * sin(mouse->rot_x) + (float)node->z * cos(mouse->rot_x);
	node->y = y;
	node->z = z;
}

void		interpolate(t_scope *scope)
{
	int 	i;
	int 	j;
	t_node	*node;

	i = 0;
	while (i < scope->map->row)
	{
		j = 0;
		node = scope->map->matrix3d[i];
		while (j < scope->map->col)
		{
			if (scope->mouse->x2 != scope->mouse->x1)
				apply_rotation_y(node, scope->mouse);
			if (scope->mouse->y2 != scope->mouse->y1)
				apply_rotation_x(node, scope->mouse);
			node++;
			j++;
		}
		i++;
	}
}

void		calc_rotation(t_mouse *mouse)
{
	mouse->rot_y = (float)(get_direction(mouse->x2, mouse->x1)) / 20.0;
	mouse->rot_x = (float)(get_direction(mouse->y1, mouse->y2)) / 20.0;
}
