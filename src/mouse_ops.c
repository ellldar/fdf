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

static void	mouse_set(int x, int y, t_mouse *mouse)
{
	mouse->x1 = x;
	mouse->x2 = x;
	mouse->y1 = y;
	mouse->y2 = y;
}

int 		mouse_press(int button, int x, int y, t_scope *scope)
{
	scope->mouse->pressed = 1;
	if (button == 1)
	{
		scope->mouse->x1 = x;
		scope->mouse->y1 = y;
		scope->mouse->button = button;
	}
	else if (button == 5)
	{
		scope->map->scale -= 2;
		render_image(scope);
	}
	else if (button == 4)
	{
		scope->map->scale += 2;
		render_image(scope);
	}
	return (0);
}

int 		mouse_release(int button, int x, int y, t_scope *scope)
{
	scope->mouse->pressed = 0;
	scope->mouse->button = 0;
	mouse_set(x, y, scope->mouse);
	return (0);
}

int 		mouse_move(int x, int y, t_scope *scope)
{
	if (is_confined(scope, x, y) && scope->mouse->pressed && scope->mouse->button == 1)
	{
		scope->mouse->x2 = scope->mouse->x1;
		scope->mouse->y2 = scope->mouse->y1;
		scope->mouse->x1 = x;
		scope->mouse->y1 = y;
		render_image(scope);
	}
	return (0);
}