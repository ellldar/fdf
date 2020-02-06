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
    return (0);
}

int key_press(int button, t_scope *scope)
{
	scope->key_pressed = 1;
    ft_putstr("pressed a key button\n");
    deal_key(button, scope);
    return (0);
}

int key_release(int button, t_scope *scope)
{
	scope->key_pressed = 0;
    ft_putstr("release a key button\n");
    return (0);
}