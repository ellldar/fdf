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

int	deal_mouse(int button, int x, int y, t_scope *scope)
{
	return (0);
}

int mouse_press(int button, int x, int y, t_scope *scope)
{
	int color;

	scope->mouse_button = button;
	scope->mouse_pressed = 1;
	printf("Mouse Button: %i\n", button);
	if (button == 1)
	{
//		scope->color = ((rand() % 0xFF) << 16) + ((rand() % 0xFF) << 8) + (rand() % 0xFF);
		draw_line(scope, 600, 400, x, y, scope->color);
	}
	else if (button == 2)
		clear_image(scope);
	ft_putstr("pressed a mouse button\n");
	return (0);
}

int mouse_release(int button, int x, int y, t_scope *scope)
{
	scope->mouse_pressed = 0;
	scope->mouse_button = 0;
	ft_putstr("release a mouse button\n");
	return (0);
}

int mouse_move(int x, int y, t_scope *scope)
{
	if (is_inbound(x, y, scope))
	{
		if (scope->mouse_pressed && scope->mouse_button == 1)
			draw_line(scope, 600, 400, x, y, scope->color);
	}
	return (0);
}
