/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 04:09:48 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/02 18:00:14 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

# include "./macros.h"
# include "./include.h"

typedef enum e_type
{
	T_SO,
	T_WE,
	T_EA,
	T_NO,
	C_floor,
	C_CEILING,
	P_NO,
	P_SO,
	P_EA,
	P_WE,
}				t_type;

#endif
