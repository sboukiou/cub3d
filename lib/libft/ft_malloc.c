/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:12:31 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/14 17:14:44 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size, int flag)
{
	t_list			*node;
	void			*ptr;
	static t_list	*list_m;

	node = NULL;
	ptr = NULL;
	if (flag == 0)
	{
		ft_lstclear(&list_m, free);
		return (NULL);
	}
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = ft_lstnew(ptr);
	if (!node)
		return (NULL);
	ft_lstadd_front(&list_m, node);
	return (ptr);
}
