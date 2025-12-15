/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:39:08 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/14 14:42:28 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		src_len;

	if (!s || len == 0)
		return (ft_strdup(""));
	src_len = ft_strlen(s);
	if (start >= src_len || src_len == 0)
		return (ft_strdup(""));
	if (len > src_len - start)
		len = src_len - start;
	substring = ft_calloc(len + 1, sizeof(char), 1);
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
