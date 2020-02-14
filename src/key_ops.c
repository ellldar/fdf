/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:54:17 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/31 20:54:20 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	deal_key(int key, t_scope *scope)
{
	if (key == 53)
		mlx_destroy_window(scope->mlx_ptr, scope->win_ptr);
	else if (key == 35 || key == 31)
	{
		scope->map->persp = key == 35 ? PERS : 250;
		render_image(scope);
	}
	else if (key == 15)
	{
		scope->map->cent_x = WIDTH / 2;
		scope->map->cent_y = HEIGHT / 2;
		extrapolate_file(scope, scope->file);
		render_image(scope);
	}
    return (0);
}

int key_press(int button, t_scope *scope)
{
	scope->key->pressed = 1;
	scope->key->button = button;
    deal_key(button, scope);
    return (0);
}

int key_release(int button, t_scope *scope)
{
	scope->key->pressed = 0;
	scope->key->button = 0;
    return (0);
}