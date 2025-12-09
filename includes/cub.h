/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 06:17:09 by hmouis            #+#    #+#             */
/*   Updated: 2025/12/08 16:45:11 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./types.h"
# include "./macros.h"
# include "./include.h"

int	parse_map(char **av, t_map_info **info, t_info **final_info);

#endif
