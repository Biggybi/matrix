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
/* #include "ui.h" */

int		main(int ac, char **av)
{
	WINDOW *uiwindow;
	char user_color;

	srand(time(NULL));
    user_color = (ac > 1) ? av[1][0] : 'g';
	if (!init_ui(uiwindow = 0, user_color))
		return (EXIT_FAILURE);
	matrix_run();
	clean_ui(uiwindow);
	return (EXIT_SUCCESS);
}
