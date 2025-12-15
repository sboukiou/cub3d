/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:38:36 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/14 15:07:38 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/types.h"
#include "../../lib/libft/libft.h"

t_element	*creat_node(t_type type, char *content)
{
	t_element	*new_node;

	new_node = ft_malloc(sizeof(t_element), 1);
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->type = type;
	new_node->next = NULL;
	return (new_node);
}

t_map_info	*creat_node_info(t_element *element)
{
	t_map_info	*new_node;

	new_node = ft_malloc(sizeof(t_map_info), 1);
	if (!new_node)
		return (NULL);
	new_node->element = element;
	new_node->map = NULL;
	return (new_node);
}

t_element	*last_node(t_element *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	add_back(t_element **lst, t_element *node)
{
	t_element	*last;

	last = NULL;
	if (!node)
		return ;
	if (lst && *lst)
	{
		last = last_node(*lst);
		last->next = node;
	}
	else
		*lst = node;
}

void	add_node(t_element **lst, char *content, t_type type)
{
	add_back(lst, creat_node(type, content));
}
