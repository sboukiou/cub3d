/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouis <hmouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:02:40 by hmouis            #+#    #+#             */
/*   Updated: 2025/08/02 17:16:24 by hmouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
#define MACROS_H

# define SUCCESS 0
#define FAILURE 1
# define MAP_SIZE 1024
# define TRUE 1
# define FALSE 0
# define FAIL -1
# define ESCAPE 65307
/*Defining Window demensions*/
# define WIN_HEIGHT 480
# define WIN_WIDTH 640
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


# define UNUSED(X) (void)(X);
# define PANIC(X) dprintf(STDERR_FILENO, "Err: [%s]\n", X),\
	exit(EXIT_FAILURE);

#endif
