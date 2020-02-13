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

static void	apply_rotation(t_node *src, t_node *dst, t_mouse *mouse)
{
	/* --------------   Rotating along the Y-axis -------------------- */
	dst->x = (float)src->z * sin(mouse->rot_y) + (float)src->x * cos(mouse->rot_y);
	dst->z = (float)src->y * cos(mouse->rot_y) - (float)src->x * sin(mouse->rot_y);

	/* --------------   Rotating along the X-axis -------------------- */
	dst->y = (float)src->y * cos(mouse->rot_x) - (float)src->z * sin(mouse->rot_x);
	dst->z = (float)src->y * sin(mouse->rot_x) + (float)src->z * cos(mouse->rot_x);
//	ft_putstr("(");
//	ft_putnbr(dst->x);
//	ft_putstr(", ");
//	ft_putnbr(dst->y);
//	ft_putstr(", ");
//	ft_putnbr(dst->z);
//	ft_putstr(")\n");
}

void		interpolate(t_scope *scope)
{
	int 	i;
	int 	j;
	t_node	**map;
	t_node	**tmp;

	map = scope->map->matrix3d;
	tmp = scope->map->matrix3d_temp;
	i = 0;
	while (i < scope->map->row)
	{
		j = 0;
		while (j < scope->map->col)
		{
//			ft_putstr("(");
//			ft_putnbr(map[i][j].x);
//			ft_putstr(", ");
//			ft_putnbr(map[i][j].y);
//			ft_putstr(", ");
//			ft_putnbr(map[i][j].z);
//			ft_putstr(") => ");
			apply_rotation(&map[i][j], &tmp[i][j], scope->mouse);
			j++;
		}
		i++;
	}
	printf("interpolating!\n");
}

void		calc_rotation(t_mouse *mouse)
{
	mouse->dx = mouse->x2 - mouse->x1;
	mouse->dy = mouse->y2 - mouse->y1;
	mouse->rot_y = M_PI * (float)(mouse->dx % 180) / 180.0;
	mouse->rot_x = M_PI * (float)(mouse->dy % 180) / 180.0;
}