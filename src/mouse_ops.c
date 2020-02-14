/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 19:18:32 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/23 19:18:42 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	mouse_set_xy(int x, int y, t_mouse *mouse)
{
	mouse->x1 = x;
	mouse->x2 = x;
	mouse->y1 = y;
	mouse->y2 = y;
}

static void	mouse_reset(t_mouse *mouse)
{
	mouse->pressed = 0;
	mouse->button = 0;
}

int			mouse_press(int button, int x, int y, t_scope *scope)
{
	scope->mouse->pressed = 1;
	scope->mouse->button = button;
	if (button == 1)
	{
		scope->mouse->x1 = x;
		scope->mouse->y1 = y;
	}
	else if (button == 4 || button == 5)
	{
		mouse_reset(scope->mouse);
		resize_map(scope, button == 4 ? 1 : -1);
	}
	return (0);
}

int			mouse_release(int button, int x, int y, t_scope *scope)
{
	mouse_reset(scope->mouse);
	mouse_set_xy(x, y, scope->mouse);
	return (0);
}

int			mouse_move(int x, int y, t_scope *scope)
{
	if (is_confined(x, y) && scope->mouse->pressed &&
		scope->mouse->button == 1)
	{
		if (scope->key->pressed && (scope->key->button == 257 ||
									scope->key->button == 258))
		{
			scope->map->cent_x += (x - scope->mouse->x1);
			scope->map->cent_y += (y - scope->mouse->y1);
			mouse_set_xy(x, y, scope->mouse);
		}
		else
		{
			scope->mouse->x2 = scope->mouse->x1;
			scope->mouse->y2 = scope->mouse->y1;
			scope->mouse->x1 = x;
			scope->mouse->y1 = y;
		}
		render_image(scope);
	}
	return (0);
}
