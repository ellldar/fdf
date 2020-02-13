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
    return (0);
}

int key_press(int button, t_scope *scope)
{
	scope->key->pressed = 1;
    printf("Pressed a key #%i button\n", button);
    deal_key(scope->key->button, scope);
    return (0);
}

int key_release(int button, t_scope *scope)
{
	scope->key->pressed = 0;
    printf("Released a key\n");
    return (0);
}