/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:26:04 by ojauregu          #+#    #+#             */
/*   Updated: 2023/03/14 18:26:06 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "headers.h"

char	*join_fr(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
	{
		if (s1)
			free(s1);
		return (s2);
	}
	else if (s2 == NULL)
	{
		free(s2);
		return (s1);
	}
	return (NULL);
}

char	*joi(char *s1, char *s2)
{
	char	*tmp;
	int		x;
	int		y;

	x = -1;
	if (s1 == NULL || s2 == NULL)
		return (join_fr(s1, s2));
	tmp = (char *)malloc(sizeof(char) * ((int)ft_strlenn(s1)
				+ (int)ft_strlenn(s2) + 1));
	if (!tmp)
		return (print_error_null(MALLOC_FAILED));
	while (s1[++x] != '\0')
		tmp[x] = s1[x];
	y = -1;
	while (s2[++y] != '\0')
		tmp[x + y] = s2[y];
	tmp[x + y] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (tmp);
}

char	*mali(char c)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (2));
	if (!tmp)
		return (print_error_null(MALLOC_FAILED));
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}

char	*malicious(char *str)
{
	char	*tmp;
	int		x;

	x = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlenn(str) + 1));
	if (!tmp)
		return (print_error_null(MALLOC_FAILED));
	while (str[x] != '\0')
	{
		tmp[x] = str[x];
		x++;
	}
	tmp[x] = '\0';
	return (tmp);
}
