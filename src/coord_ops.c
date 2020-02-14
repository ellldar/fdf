/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:30:49 by esupatae          #+#    #+#             */
/*   Updated: 2020/02/14 03:30:53 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			validate_points(t_line *line)
{
//	if (line->x >= 0 && x < WIDTH && *y >= 0 && *y < HEIGHT)
//		return (1);
//	if (*x1 >= 0 && *x1 < WIDTH && *y1 >= 0 && *y1 < HEIGHT)
//		return (1);
	return (1);
}

t_line		*make_line(t_line *line, t_node node1, t_node node2)
{
	line->x1 = node1.x;
	line->y1 = node1.y;
	line->x2 = node2.x;
	line->y2 = node2.y;
	return (line);
}