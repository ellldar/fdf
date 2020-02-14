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
	char	*addr;

	if (is_confined(scope, x, y))
	{
		addr = scope->image->addr;
		addr += y * scope->image->line_size +
				x * (scope->image->bits_ppxl / 8);
		*(unsigned int*)addr = color;
	}
}

static void	calc_linevar(t_line *line, float *x, float *y)
{
	line->alpha = 0;
	line->step = fabsf(line->x2 - line->x1) >= fabsf(line->y2 - line->y1)
			? fabsf(line->x2 - line->x1) : fabsf(line->y2 - line->y1);
	line->dx = (line->x2 - line->x1) / line->step;
	line->dy = (line->y2 - line->y1) / line->step;
	*x = line->x1;
	*y = line->y1;
}

static void	calc_antialias(t_line *line, int color)
{
	int alpha;

	alpha = color;
	if (fabsf(line->dx) >= fabsf(line->dy))
		line->ratio = line->y1 - round(line->y1);
	else
		line->ratio = line->x1 - round(line->x1);
	if (fabsf(line->ratio) > 0.02)
	{
		alpha = (int)(round(0x7F * fabs(line->ratio / 0.5)));
		line->reverse_alpha = ((0xFF - alpha) << 24) + color;
		line->alpha = (alpha << 24) + color;
	}
	else
	{
		line->alpha = alpha;
		line->reverse_alpha = 0;
	}
}

static void	put_second_pixel(t_scope *scope, float x, float y)
{
	t_line	*line;
	int 	offset;

	line = scope->line;
	x = round(x);
	y = round(y);
	offset = get_direction(0, (int)(line->ratio * 1000));
	if (fabsf(line->dx) >= fabsf(line->dy))
		put_pixel(scope, x, y + offset, line->reverse_alpha);
	else
		put_pixel(scope, x + offset, y, line->reverse_alpha);
}

void		draw_line(t_scope *scope, t_line *line)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	if (validate_points(line))
	{
		calc_linevar(line, &x, &y);
		while (i <= line->step)
		{
			calc_antialias(line, scope->color);
			if (line->alpha != scope->color && !is_endpoint(line, x, y))
			{
				put_pixel(scope, round(x), round(y), line->alpha);
				put_second_pixel(scope, round(x), round(y));
			}
			else
				put_pixel(scope, round(x), round(y), scope->color);
			x += line->dx;
			y += line->dy;
			i++;
		}
	}
}


