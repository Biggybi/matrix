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

int		main()
{
	WINDOW *uiwindow;

	uiwindow = 0;
	if (!init_ui(uiwindow))
		return (EXIT_FAILURE);
	matrix_run();
	clean_ui(uiwindow);
	return (EXIT_SUCCESS);
}
