/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tris <tris@tristankapous.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:07:16 by tris              #+#    #+#             */
/*   Updated: 2021/09/11 16:07:16 by tris             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	WINDOW *uiwindow;
	char user_color;
	int color_shift;

	color_shift = (av[2] && av[2][0] == 's');
    user_color = (ac > 1) ? av[1][0] : 'g';
	dprintf(1, "user color = %c\n", user_color);
	srand(time(NULL));
	if (!ui_init(uiwindow = 0, user_color))
		return (EXIT_FAILURE);
	matrix_run(color_shift);
	ui_clean(uiwindow);
	return (EXIT_SUCCESS);
}
