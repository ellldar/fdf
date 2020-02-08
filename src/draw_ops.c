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
	t_line	*line;
	int		i;
	int 	alpha;
	int 	rev_alpha;
	float	ratio;

//	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
	line = scope->line;
	calc_linevar(line, x, y, x1, y1);
	i = 0;
	alpha = 0;
	while (i <= line->step)
	{
		if (line->ratio != 0.0 && ((x0 != x && x0 != x1) || (y0 != y && y0 != y1)))
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
	render_image(scope);
}

void	calc_linevar(t_line *var, int x, int y, int x1, int y1)
{
	var->step = abs(x1 - x) >= abs(y1 - y) ? abs(x1 - x) : abs(y1 - y);
	var->dx = (x1 - x) / (float)var->step;
	var->dy = (y1 - y) / (float)var->step;
	var->x = (float)x;
	var->y = (float)y;
}

void	calc_antialias(t_line *var)
{
	if (abs(var->dx) >= abs(var->dy))
		var->ratio = var->y - (float)round(var->y);
	else
		var->ratio = var->x - (float)round(var->x);
}