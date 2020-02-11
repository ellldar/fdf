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

static void	put_pixel(t_scope *scope, int x, int y, int color)
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

static void	calc_linevar(t_line *var, int x, int y, int x1, int y1)
{
	var->step = abs(x1 - x) >= abs(y1 - y) ? abs(x1 - x) : abs(y1 - y);
	var->dx = (x1 - x) / (float)var->step;
	var->dy = (y1 - y) / (float)var->step;
	var->x = (float)x;
	var->y = (float)y;
	var->alpha = 0;
}

static void	calc_antialias(t_line *var, int color)
{
	int alpha;

	alpha = color;
	if (fabsf(var->dx) >= fabsf(var->dy))
		var->ratio = var->y - (float)round(var->y);
	else
		var->ratio = var->x - (float)round(var->x);
	if (fabsf(var->ratio) > 0.02)
	{
		alpha = (int)(round(0x7F * fabs(var->ratio / 0.5)));
		var->reverse_alpha = ((0xFF - alpha) << 24) + color;
		var->alpha = (alpha << 24) + color;
	}
	else
	{
		var->alpha = alpha;
		var->reverse_alpha = 0;
	}
}

static void	put_second_pixel(t_scope *scope)
{
	t_line	*line;
	int 	offset;
	int 	x;
	int 	y;

	line = scope->line;
	x = round(line->x);
	y = round(line->y);
	offset = get_direction(0, (int)(line->ratio * 1000));
	if (fabsf(line->dx) >= fabsf(line->dy))
		put_pixel(scope, x, y + offset, line->reverse_alpha);
	else
		put_pixel(scope, x + offset, y, line->reverse_alpha);
}

void		draw_line(t_scope *scope, int x, int y, int x1, int y1, int color)
{
	t_line	*line;
	int		i;

//	ft_bzero(scope->image->addr, scope->height * scope->image->line_size);
	i = 0;
	line = scope->line;
	calc_linevar(line, x, y, x1, y1);
	while (i <= line->step)
	{
		calc_antialias(line, color);
		if (line->alpha != color && !is_endpoint(line, x, y, x1, y1))
		{
			put_pixel(scope, round(line->x), round(line->y), line->alpha);
			put_second_pixel(scope);
		}
		else
			put_pixel(scope, round(line->x), round(line->y), color);
		line->x += line->dx;
		line->y += line->dy;
		i++;
	}
//	render_image(scope);
}


