/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:16:56 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/23 19:16:58 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line(t_scope *scope, int x0, int y0, int x1, int y1)
{
	int i;

	i = 0;
	while(i < 100)
	{
		mlx_pixel_put(scope->mlx_ptr, scope->win_ptr, x0 + i, y0 + i, 0xFFFFFF);
		i++;
	}
}

void	draw_circle(t_scope *scope, int x, int y, int r)
{
	int x0;
	int y0;

	x0 = -r;
	while (x0 < r)
	{
		y0 = (int)sqrt((double)(pow(r, 2) - pow(x0, 2)));
		mlx_pixel_put(scope->mlx_ptr, scope->win_ptr, x + x0, y + y0, 0xFFFFFF);
		mlx_pixel_put(scope->mlx_ptr, scope->win_ptr, x + x0, y - y0, 0xFFFFFF);
		x0++;
	}
};