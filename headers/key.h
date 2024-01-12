/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:19:02 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 23:55:22 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# ifdef __linux__
#  define OS 0
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT	100
#  define ECHAP	65307
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
# elif defined(__APPLE__)
#  define OS 1
#  define UP					13
#  define DOWN				1
#  define LEFT				0
#  define RIGHT				2
#  define ECHAP				53
#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
# endif

#endif