/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:05:32 by agirardi          #+#    #+#             */
/*   Updated: 2021/12/17 18:42:08 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_key(int key, t_data *data)
{
	(void)data;
	if (key == 13)
		printf("W\n");
	if (key == 0)
		printf("A\n");
	if (key == 1)
		printf("S\n");
	if (key == 2)
		printf("D\n");
	// if (key == 53)
	// 	printf("ESC\n");

	return (0);

}
