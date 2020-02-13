/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esupatae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:49:59 by esupatae          #+#    #+#             */
/*   Updated: 2020/01/22 21:50:00 by esupatae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	count_col(const char *line)
{
	int	count;
	char **arr;

	count = 0;
	arr = ft_strsplit(line, ' ');
	while (*arr++)
		count++;
	return (count);
}

static int	*read_row(const char *line)
{
	char 	**arr;
	char 	**ptr1;
	int 	*ans;
	int 	*ptr2;
	int		count;

	count = 0;
	arr = ft_strsplit(line, ' ');
	ptr1 = arr;
	while (*ptr1++)
		count++;
	ans = (int*)malloc(sizeof(int) * count);
	ptr2 = ans;
	while (*arr)
		*ptr2++ = ft_atoi(*arr++);
	return(ans);
}

static void	add_row_to_list(t_file *file, char *line)
{
	t_list	*list;
	int 	i = 0;
	int 	*arr;
	int 	val;

	list = file->list;
	arr = read_row(line);
	if (list)
	{
		list->next = ft_lstnew(arr, sizeof(int) * file->col);
		file->list = list->next;
		file->row++;
	}
	else
	{
		file->list = ft_lstnew(arr, sizeof(int) * file->col);
		file->head = file->list;
		file->row = 1;
	}
	free(arr);
}

static void	extrapolate_file(t_scope *scope, t_file *file)
{
	int 	i;
	int 	j;
	t_list 	*curr;
	int 	*row;
	t_map	*map;

	i = 0;
	curr = file->head;
	map = scope->map;
	while (i < map->row)
	{
		j = 0;
		row = (int*)(curr->content);
		while (j < map->col)
		{
			map->matrix3d[i][j].x = scope->width / 2 -
					(map->col * map->scale / 2) + j * map->scale;
			map->matrix3d[i][j].y = scope->height / 2 -
					(map->row * map->scale / 2) + i * map->scale;
			map->matrix3d[i][j].z = (row[j] * map->scale) - 200;
			j++;
		}
		curr = curr->next;
		i++;
	}
}

static void	print_map(t_map *map)
{
	int 	i;
	int 	j;
	t_node	**arr;
	t_node	node;

	i = 0;
	arr = map->matrix3d;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			node = arr[i][j];
			printf("(%i, %i, %i)\n", node.x, node.y, node.z);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		read_map(t_scope *scope, const int fd)
{
	int		ret;
	char 	*line;
	t_file	*file;

	file = (t_file*)malloc(sizeof(t_file));
	file->list = NULL;
	file->col = 0;
	while((ret = get_next_line(fd, &line)))
	{
		if (!file->col)
			file->col = count_col(line);
		add_row_to_list(file, line);
		free(line);
	}
	scope->map = init_map(scope, file);
	extrapolate_file(scope, file);
	print_map(scope->map);
}