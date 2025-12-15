/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:58:31 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/14 15:05:00 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*buff;
	size_t	len;

	len = ft_strlen(str);
	buff = (char *)ft_malloc(sizeof(char) * (len + 1), 1);
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, str, len + 1);
	return (buff);
}
