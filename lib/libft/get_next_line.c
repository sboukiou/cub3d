/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:23 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/14 15:05:47 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static char	*ft_strcpy_gnl(char *str, char *after_newline)
{
	int	i;

	i = 0;
	while (after_newline[i])
	{
		str[i] = after_newline[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_line(char *str, char *after_newline)
{
	char	*line;

	line = ft_malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(after_newline)
				+ 1), 1);
	if (!line)
		return (NULL);
	line = ft_strcpy_nl(line, str);
	return (line);
}

static char	*fill_str(char *str, int fd)
{
	ssize_t	count;
	char	*buf;

	buf = ft_malloc(sizeof(char) * BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (!ft_strchr_gnl(buf, '\n'))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == 0)
			break ;
		if (count < 0)
		{
			str = NULL;
			break ;
		}
		buf[count] = '\0';
		str = ft_strjoin_gnl(str, buf);
		if (!str)
			return (NULL);
	}
	return (str);
}

static char	*check_after_nl(char **str)
{
	char	*line;

	if (str)
	{
		line = ft_malloc(sizeof(char) * (ft_strlen(*str) + 1), 1);
		if (!line)
		{
			*str = NULL;
			return (NULL);
		}
		line = ft_strcpy_gnl(line, *str);
		*str = NULL;
		return (line);
	}
	str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*after_newline;
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = fill_str(str, fd);
	if (!str)
		return (NULL);
	after_newline = ft_strchr_gnl(str, '\n');
	if (!after_newline)
		return (check_after_nl(&str));
	line = get_line(str, after_newline);
	if (!line)
		return (str = NULL);
	str = ft_strcpy_gnl(str, after_newline);
	if (str && str[0] == '\0')
		str = NULL;
	return (line);
}
