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
#include <stdio.h>

void	put_pixel(t_scope *scope, int x, int y, int color)
{
	t_image	*image;
	char	*addr;
	int 	pos;

	image = scope->image;
	addr = image->addr;
	pos = y * image->line_size + x * (image->bits_ppxl / 8);
	addr += pos;
	*(unsigned int*)addr = color;
}

void	draw_line(t_scope *scope, int x, int y, int x1, int y1, int color)
{
	float	dx;
	float	dy;
	int		step;
	float	x0;
	float	y0;
	int		i;
	int 	alpha;
	int 	rev_alpha;
	float	ratio;

	if (x1 > 0 && x1 < scope->width && y1 > 0 && y1 < scope->height)
	{
		ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
		dx = x1 - x;
		dy = y1 - y;
		if (ft_abs(dx) >= ft_abs(dy))
			step = ft_abs(dx) * 2;
		else
			step = ft_abs(dy) * 2;
		dx = dx / (float)step;
		dy = dy / (float)step;
		x0 = (float)x;
		y0 = (float)y;
		i = 0;
		alpha = 0;
		while (i <= step)
		{
			ratio = ft_abs(dx) >= ft_abs(dy) ? (y0 - (float)round(y0)) : (x0 - (float)round(x0));
			if (ratio != 0.0 && ((x0 != x && x0 != x1) || (y0 != y && y0 != y1)))
			{
				alpha = ft_abs(round(0x7F * (ratio / 0.5)));
				rev_alpha = ((0xFF - alpha) << 24) + color;
				put_pixel(scope, round(x0), round(y0), (alpha << 24) + color);
				if (ft_abs(dx) >= ft_abs(dy))
					put_pixel(scope, round(x0), round(y0) + get_direction(0, (int)(ratio * 1000)), rev_alpha);
				else
					put_pixel(scope, round(x0) + get_direction(0, (int)(ratio * 1000)), round(y0), rev_alpha);
			}
			else
				put_pixel(scope, round(x0), round(y0), color);
			x0 += dx;
			y0 += dy;
			i++;
		}
		render(scope);
	}
}

void 	render(t_scope *scope)
{
	t_image	*img;

	img = scope->image;
	mlx_put_image_to_window(scope->mlx_ptr, scope->win_ptr, img->ptr, 0, 0);
}