/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:18:56 by orfreoua          #+#    #+#             */
/*   Updated: 2023/09/28 23:41:06 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# include "headers.h"

# define BAD_NB_ARG "expecting ./cub_3d file_name.cub"
# define EMPTY_ARG_FILE "you have to give an argument"
# define SECRET_FILE "this is a secret file"
# define BAD_NAME_FILE "file prototype is file_name.cub"
# define BAD_PATH_FILE "the path is not valid"
# define PATH_IS_DIR "this is a directory"
# define MLX_CONNECTION "connection between with the display not established"
# define WIN_CONNECTION "window could not be created"
# define IMG_CREATE "unable to create a new image with MiniLibX"
# define IMG_ADDR "unable to get the address of image data with MiniLibX"
# define MISSING_TEXTURES "one or more textures are missing from the file.cub"
# define DOUBLE_SAME_PATH "double same path"
# define MALLOC_FAILED "failed to allocate memory"
# define NO_PB "something went wrong with NO path"
# define SO_PB "something went wrong with SO path"
# define WE_PB "something went wrong with WE path"
# define EA_PB "something went wrong with EA path"
# define ELSE_MAP "something went wrong with the map"
# define RET_CEI "something went wrong with ceiling description"
# define RET_FLO "something went wrong with floor description"
# define CEI_COL "ceiling must start with C and follow full RGB scale 0 - 255"
# define FLO_COL "floor must start with F and follow full RGB scale 0 - 255"
# define FILE_ERR "stopped checking the file at line "
# define NORTH_BIS "north is already define, stop checking at line "
# define SOUTH_BIS "south is already define, stop checking at line "
# define EAST_BIS "east is already define, stop checking at line "
# define WEST_BIS "west is already define, stop checking at line "
# define FLOOR_BIS "floor is already define, stop checking at line "
# define CEIL_BIS "ceiling is already define, stop checking at line "
# define NO_NORTH "north is not define before map, stop checking at line "
# define NO_SOUTH "south is not define before map, stop checking at line "
# define NO_EAST "east is not define before map, stop checking at line "
# define NO_WEST "west is not define before map, stop checking at line "
# define NO_CEIL "ceiling is not define before map, stop checking at line "
# define NO_FLOOR "floor is not define before map, stop checking at line "
# define WEIRD_CHAR "unknown char at line "
# define RGB_NORM "RGB scale is 0 - 255, expected expression is R,G,B"
# define NO_PLAYER "no player position found"
# define SEP_MAP "map is separated at some point"
# define FLO_MAP "map is not closed with walls"

# define TEX_PATH "texture path seems sketchy"
# define UNPROTECTED "unprotected map, some walls are not closed"
# define NO_MAP "where is the map??"
# define NL_IN_MAP "some new line seeems to be on the way of my map"
# define TOO_MUCH_POS "you must put only one starting position"
# define WRONG_CHAR_IN_MAP " is not a receivable character, use -01 NSEW-"
# define READ "something went wrong while reading the file"
# define TOO_SHORT "map is too short"
# define LOAD_TEXTURES_FAIL "something went wrong while extracting the textures"

#endif