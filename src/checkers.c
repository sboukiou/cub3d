/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:45:02 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/08 17:45:29 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.h"

bool	is_prog_valid(t_prog *prog)
{
	if (prog == NULL)
		return (false);
	if (prog->info == NULL)
		return (false);
	if (prog->mlx == NULL)
		return (false);
	return (true);
}
