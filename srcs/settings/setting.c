#include "headers.h"

void    setting(t_data *data)
{
    data->key.arrow_left = 0;
	data->key.arrow_right = 0;
	data->key.up = 0;
	data->key.down = 0;
	data->key.left = 0;
	data->key.right = 0;
	data->menu = 0;
    load_textures(data);
	load_drago(data, &data->drago);
	load_drago_b(data, &data->drago);
}