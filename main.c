/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:46 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/02 18:15:11 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub.h"

int	main(int ac, char **av)
{
	t_map_info	*map_info;
	t_info	*info;

	
	map_info = NULL;
	info = NULL;
	if (ac != 2)
		return (FAILURE);
	if (pars_map(av, &map_info, &info) == -1)
		return (FAILURE);
	return (SUCCESS);
}
