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
		scope->x = x;
		scope->y = y;
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
	static t_map	*tmp = NULL;

	if (!tmp)
		tmp = (t_map*)malloc(sizeof(scope->map));
	if (is_confined(scope, x, y))
	{
//		tmp = ft_memcpy(tmp, scope->map->data, sizeof(scope->map->data));
//		if (scope->mouse_pressed && scope->mouse_button == 1)
//		{
//			interpolate(scope, tmp, x, y);
//			draw_3d_obj(scope, tmp);
//		}
	}
	return (0);
}
