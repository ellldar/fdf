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

void	draw_3d_obj(t_scope *scope, int *map[])
{
	int center_x;
	int center_y;
	int z_distance = 100;
	int n = 5;
	int i, j;
	int scale;
	int x;
	int y;

	center_x = scope->width / 2;
	center_y = scope->height / 2;
	i = 0;
	scale = 100;
	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
	while (i <= n)
	{
		j = 0;
		while (j <= n)
		{
			x = (center_x - (n * scale / 2) + j * scale);
			y = (center_y - (n * scale / 2) + i * scale);
			if (i != n)
				draw_line(scope, x, y, x, y + scale, 0xFFFFFF);
			if (j != n)
				draw_line(scope, x, y, x + scale, y, 0xFFFFFF);
			j++;
		}
		i++;
	}
	render_image(scope);
}
