/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 06:32:12 by hmouis            #+#    #+#             */
/*   Updated: 2025/11/16 15:08:00 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "./types.h"
#include "./macros.h"
#include "../lib/libft/libft.h"
#include "./include.h"

void	char_join(char **path, char c);
int	pars_0(char *line, char **arr, int flag, int i);
int	ft_atoi_color(char *str);
int	pars_empty_line(int *i, char *line);
int	count_comma(char *str);
char	*strcpy_nl(char *str);
int	all_element(t_map map_info);
int	is_empty(char *line, int track);
char	*strcpy_nl(char *str);
void	add_node(t_element **lst, char *content, t_type type);
t_map_info	*creat_node_info(t_element *element);


#endif