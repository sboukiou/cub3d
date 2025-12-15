/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:18:49 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/14 14:42:20 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	index;

	if (!s || !f)
		return (NULL);
	new_string = ft_calloc(ft_strlen(s) + 1, sizeof(char), 1);
	if (!new_string)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new_string[index] = f(index, s[index]);
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}
