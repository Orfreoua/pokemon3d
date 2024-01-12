#include "headers.h"

char *ft_super_strjoin(char *path, char *number, char *extension)
{
    char *file_name;

    file_name = ft_strjoin(path, number, 0);
    if (!file_name)
        return (0);
    file_name = ft_strjoin(file_name, extension, 1);
    return (file_name);
}

void    free_drago(t_data *data, t_drago *drago, int index)
{
    while (index)
    {
        free(drago->paths[index]);
        if (drago->textures[index].img)
            mlx_destroy_image(data->mlx, drago->textures[index].img);
        index--;
    }
    free(drago->paths[index]);
    if (drago->textures[index].img)
        mlx_destroy_image(data->mlx, drago->textures[index].img);
    free(drago->paths);
}

int load_drago_b(t_data *data, t_drago *drago)
{
    int i;

    i = 0;
    drago->paths_b = malloc(sizeof(char *) * 52);
    if (!drago->paths_b)
        return (0);
    while (i < 51)
    {
        drago->paths_b[i] = ft_super_strjoin("assets/textures/sprite_pokemon/dragofeu_b/", ft_itoa(i), ".xpm");
        if (!drago->paths_b[i] || load_texture(data, &drago->textures_b[i], drago->paths_b[i]))
        {
            free_drago(data, drago, i);
            return (0);
        }
        i++;
    }
    return (1);
}

int load_drago(t_data *data, t_drago *drago)
{
    int i;

    i = 0;
    drago->paths = malloc(sizeof(char *) * 48);
    if (!drago->paths)
        return (0);
    while (i < 47)
    {
        drago->paths[i] = ft_super_strjoin("assets/textures/sprite_pokemon/dragofeu/", ft_itoa(i), ".xpm");
        if (!drago->paths[i] || load_texture(data, &drago->textures[i], drago->paths[i]))
        {
            free_drago(data, drago, i);
            return (0);
        }
        i++;
    }
    return (1);
}