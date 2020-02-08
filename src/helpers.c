/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:32:33 by esupatae          #+#    #+#             */
/*   Updated: 2020/02/07 23:32:35 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		get_direction(int n1, int n2)
{
	if (n1 > n2)
		return (-1);
	else if (n1 < n2)
		return (1);
	return (0);
}

int		is_confined(t_scope *scope, int x, int y)
{
	return(x >= 0 && x < scope->width && y >= 0 && y < scope->height);
}

int		is_endpoint(t_line *var, int x, int y, int x1, int y1)
{
	float	x0;
	float	y0;

	x0 = var->x;
	y0 = var->y;
	return ((x0 == x && y0 != y) || (x0 == x1 && y0 == y1));
}