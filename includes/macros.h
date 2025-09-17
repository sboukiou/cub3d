/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:02:40 by hmouis            #+#    #+#             */
/*   Updated: 2025/09/12 16:11:47 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
#define MACROS_H

# define COLORS_SIZE 3
# define SUCCESS 0
#define FAILURE 1
# define MAP_SIZE 1024
# define SIZE_SCALE 44
# define TRUE 1
# define KEY_E 101
# define FALSE 0
# define FAIL -1
# define ESCAPE 65307
/*Defining Window demensions*/
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
/*Defining Colors*/
# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLUE 0xFF00FF
# define PINK 0xFF8DA1
# define DEFAULT_Z 0x99CCFF
# define DEFAULT 0x00CC66
/*Defining Macros for events*/
# define KEY_PRESS_EVENT 2
# define BTN_PRESS_EVENT 4
# define DESTROY_NOTIFY_EVENT 17
# define PI 3.14159
# define ROT_SPEED 0.05
# define BLOCK_SIZE 22


# define UNUSED(X) (void)(X);
# define PANIC(X) dprintf(STDERR_FILENO, "Err: [%s]\n", X),\
	exit(EXIT_FAILURE);

#endif
