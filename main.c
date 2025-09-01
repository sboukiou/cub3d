/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:21:46 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/01 09:52:29 by hmouis           ###   ########.fr       */
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
		return (printf("ERROR\nmissing file\n"), FAILURE);
	if (parse_map(av, &map_info, &info) == FAILURE)
		return (FAILURE);
	printf("max width = %d\n", info->map_height);
	return (SUCCESS);
}
