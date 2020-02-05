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
#include <time.h>

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
	float	ratio;

	if (x1 > 0 && x1 < scope->width && y1 > 0 && y1 < scope->height)
	{
		ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
		dx = x1 - x;
		dy = y1 - y;
		if (ft_abs(dx) >= ft_abs(dy))
			step = ft_abs(dx);
		else
			step = ft_abs(dy);
		dx = dx / (float)step;
		dy = dy / (float)step;
		x0 = x;
		y0 = y;
		i = 0;
		alpha = 0;
		while (i <= step)
		{
			ratio = 0.5 - dy / 2;
			alpha = (int)(255 * (ratio / 0.5));
			put_pixel(scope, round(x0), round(y0), (ft_abs(alpha) << 24) + 0x00FFFFFF);
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