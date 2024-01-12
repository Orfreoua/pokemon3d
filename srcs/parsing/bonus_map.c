#include "headers.h"

//	data->file.map = bonus_map(data->fole.mapy);/////////ligne 71 de all_in_struct.c
/*

mur des bords = 3;
espace = 0;
maisons:
'2'
34(maison en deux parties)
5(lac)



*/

void	transformers_b(char **map, int zone, int new)
{
	int	y;
	int	x;

	y = 0;
	////printf("transfor_b\n");
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == zone)
				map[y][x] = new;
			x++;
		}
		y++;
	}
	////printf("fin trans_b\n");
}

void	is_one_nxt_bonus(char **map, int y, int x, t_fole *fole)
{
	if (x == 0)
		map[y][x] = fole->zone;
	else if (x < fole->len_y && map[y][x - 1] <= '2')
	{
		fole->zone++;
		map[y][x] = fole->zone;
	}
	else if (x < fole->len_y && map[y][x - 1] > '2')
		map[y][x] = map[y][x - 1];
}

void	is_one_nxt_nxt_bonus(char **map, int y, int x, t_fole *fole)
{
	if (map[y - 1][x] > '2')
		map[y][x] = map[y - 1][x];
	else if (x < fole->len_y && map[y - 1][x] <= '2')
	{
		fole->zone++;
		map[y][x] = fole->zone;
	}
}

void	is_one_nxt_nxt_end_bonus(char **map, int y, int x, t_fole *fole)
{
	if (map[y - 1][x] <= '2' && map[y][x - 1] <= '2')
	{
       // //printf("if 1\n");
		fole->zone++;
		map[y][x] = fole->zone;
	}
	else if (map[y - 1][x] > '2' && map[y][x - 1] > '2'
		&& map[y - 1][x] > map[y][x - 1])
	{
        //printf("if 2\n");
		map[y][x] = map[y][x - 1];
		transformers_b(map, map[y - 1][x], map[y][x - 1]);
	}
	else if (map[y - 1][x] > '2' && map[y][x - 1] > '2'
	&& map[y - 1][x] < map[y][x - 1])
	{
        //printf("if 3\n");
		map[y][x] = map[y - 1][x];
		transformers_b(map, map[y][x - 1], map[y - 1][x]);
	}
	else if (map[y - 1][x] > '2')
    {
        //printf("if 4\n");
		map[y][x] = map[y - 1][x];
    }
	else if (map[y][x - 1] > '2')
    {
        //printf("if 5\n");
		map[y][x] = map[y][x - 1];
    }
    //printf("none\n");
}

char    **check_bonus(char **map, int y, int x, t_fole *fole)
{
    if (y == 0)
    {
        //printf("SEG1\n");
		is_one_nxt_bonus(map, y, x, fole);
    }
	else if (x == 0)
    {
        //printf("seG?2\n");
		is_one_nxt_nxt_bonus(map, y, x, fole);
    }
	else
	{
        //printf("seg?3\n");
		is_one_nxt_nxt_end_bonus(map, y, x, fole);
	}
    //printf("retrun\n");
    return (map);
}

char    **lac(int x, int y, int z, char **map)
{
    if (y > 0 && x > 0 && z != '0' && map[y - 1][x] == '0' && map[y + 1] != NULL 
    && map[y][x - 1] == '1' && map[y][x + 1] == z && map[y + 1][x] == z && map[y + 1][x - 1] == z && map[y + 1][x + 1] == z)
        map[y][x] = '5';
    else if (x > 0 && z != '0' && map[y][x - 1] == '5' && map[y][x] == z && map[y][x + 1] != '\0' && map[y][x + 1] == z)
        map[y][x] = '5';
    else if (y > 0 && x > 0 && z != '0' && (map[y - 1][x + 1] == '5' || map[y - 1][x + 1] == '1')
    && map[y - 1][x] == '1' && map[y + 1] != NULL 
    && map[y][x - 1] == '0' && map[y][x + 1] == z && map[y + 1][x] == z && map[y + 1][x + 1] == z)
        map[y][x] = '5';
    else if (x > 0 && y > 0 && z != '0' && map[y - 1][x] == '5' && map[y + 1] != NULL && map[y][x + 1] != '\0' && map[y][x + 1] == z && map[y + 1][x + 1] == z)
        map[y][x] = '5';
    else if (y > 0 && x > 0 && z != '0' && (map[y - 1][x - 1] == '5' || map[y - 1][x - 1] == '1')
    && (map[y - 1][x] == '1' || map[y - 1][x] == '5') && map[y + 1] != NULL 
    && (map[y][x - 1] == '1' || map[y][x - 1] == '5') && map[y][x + 1] == '0' && map[y + 1][x] == z && map[y + 1][x - 1] == z)
        map[y][x] = '5';
    else if (y > 0 && x > 0 && z != '0' && (map[y - 1][x - 1] == '5' || map[y - 1][x - 1] == '1')
    && (map[y - 1][x] == '5' || map[y - 1][x] == '1')
    && (map[y - 1][x + 1] == '5' || map[y - 1][x + 1] == '1')
    && map[y + 1] != NULL 
    && (map[y][x - 1] == '1' || map[y][x - 1] == '5') && map[y][x + 1] == z
    && map[y + 1][x] == '0')
        map[y][x] = '5';
    return (map);
}

char    **maisons(int x, int y, char **map)
{
    if (map[y][x] > '6'  && map[y][x - 1] == '0' && map[y][x + 1] == '0' && map[y + 1][x] == '0' && map[y + 1][x + 1] == '0')
        map[y][x] = '2';
    else if (map[y][x] > '6' && (map[y][x] == map[y][x + 1]) && map[y][x + 2] == '0' && map[y + 1][x] == '0' && map[y + 1][x + 1] == '0')
    {
        map[y][x] = '3';
        map[y][x + 1] = '4';
        x++;
    }
    else if (map[y][x] > '6')
        map[y][x] = '1';
    return (map);
}

char    **create_house_bonus(char **map, t_fole *fole)
{
    int x;
    int y;
    int z;

    y = 0;
    (void)fole;

    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
          //  printf("Y X = %c\n",map[y][x]);
            if (map[y][x] == '6')
                map[y][x] = '1';
            x++;
        }
        y++;
    }
    y = 0;
    while (map[y] != NULL)
    {
        x = 0;
        while (map[y][x] != '\0')
        {
            z = map[y][x];
            map = lac(x, y, z, map);
            map = maisons(x, y, map);
            x++;
        }
        y++;
    }
    return (map);
}

char **bonus_map(char **first, t_fole *fole)
{
    int x;
    int y;

    y = 0;
    fole->zone = '6';
    while (first[y] != NULL)
    {
        x = 0;
        while (first[y][x] != '\0')
        {
            if (first[y][x] == '1')
                first = check_bonus(first, y, x, fole);
            x++;
        }
        y++;
    }
    //print_map(first);
   // printf("Fin de print\n");
    first = create_house_bonus(first, fole);
  //  print_map(first);
    return (first);
}
