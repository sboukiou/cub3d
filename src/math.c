/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:47:07 by sboukiou          #+#    #+#             */
/*   Updated: 2025/12/09 15:49:49 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	calculate_distance(int px, int py, int dx, int dy)
{
	int		diff_x;
	int		diff_y;
	double	distance;

	diff_x = dx - px;
	diff_y = dy - py;
	distance = sqrt(diff_x * diff_x + diff_y * diff_y);
	return ((int)distance);
}

unsigned int	rgb_merge(int r, int g, int b)
{
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	return (((unsigned int)r << 16) | ((unsigned int)g << 8) | (unsigned int)b);
}
