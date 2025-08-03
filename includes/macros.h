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

#define FAILURE 1
#define SUCCESS 0

# define UNUSED(X) (void)(X);
# define PANIC(X) dprintf(STDERR_FILENO, "Err: [%s]\n", X);\
	exit(EXIT_FAILURE);

#endif
