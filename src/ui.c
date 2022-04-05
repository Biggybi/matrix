/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tris <tris@tristankapous.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:22:50 by tris              #+#    #+#             */
/*   Updated: 2021/09/11 16:22:50 by tris             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* #include "ui.h" */
#include "matrix.h"
/* #include <curses.h> */

int ui_init(WINDOW *uiwindow, char user_color)
{
	uiwindow = initscr();
	if (!uiwindow)
		return (EXIT_FAILURE);
	start_color();
	if (!has_colors() || !can_change_color() || COLOR_PAIRS < 6)
	{
		dprintf(1, "Color support not available.");
		return (0);
	}
	colors_set(user_color);
	return (1);
}

void ui_clean(WINDOW *uiwindow)
{
	delwin(uiwindow);
	endwin();
	refresh();
}
