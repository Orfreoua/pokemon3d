/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:44:27 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 23:44:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "headers.h"

# define KO 1 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define ERROR -1
# define ERROR_BIS -4
# define MAP_ERROR -1
# define EXIT_FAILLURE -1
# define OK 0
# define RED "\x1B[31m"
# define BLU "\x1B[34m"
# define NRM "\x1B[0m"

#endif
