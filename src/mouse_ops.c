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

int mouse_press(int button, int x, int y, t_scope *scope)
{
	t_mouse	*mouse;

	mouse = scope->mouse;
	printf("Mouse Button: %i\n", mouse->button);
	mouse->pressed = 1;
	mouse->x1 = x;
	mouse->y1 = y;
	if (button == 1)
		mouse->button = button;
	else if (button == 2)
		clear_image(scope);
	ft_putstr("pressed a mouse button\n");
	return (0);
}

int mouse_release(int button, int x, int y, t_scope *scope)
{
	size_t	size;
	t_mouse	*mouse;
	t_node	**map;
	t_node	**tmp;

	map = scope->map->matrix3d;
	tmp = scope->map->matrix3d_temp;
	mouse = scope->mouse;
	size = scope->map->row * scope->map->col;
	if (button == 1)
		ft_memcpy(map, tmp, sizeof(t_node) * size);
	mouse->pressed = 0;
	mouse->button = 0;
	ft_putstr("release a mouse button\n");
	return (0);
}

int mouse_move(int x, int y, t_scope *scope)
{
	size_t	size;
	t_mouse	*mouse;
	t_node	**map;
	t_node	**tmp;

	map = scope->map->matrix3d;
	tmp = scope->map->matrix3d_temp;
	size = scope->map->row * scope->map->col;
	ft_memcpy(tmp, map, sizeof(t_node) * size);
	mouse = scope->mouse;
	mouse->x2 = x;
	mouse->y2 = y;
	calc_rotation(mouse);
	if (is_confined(scope, x, y) && mouse->pressed)
	{
		if (scope->mouse->button == 1)
		{
			interpolate(scope);
			draw_3d_obj(scope);
		}
		printf("(%i, %i, %i, %i)\n", mouse->x1, mouse->y1, mouse->x2, mouse->y2);
	}
	return (0);
}
