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

int init_ui(WINDOW *uiwindow, char user_color)
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
	set_colors(user_color);
	return (1);
}

void clean_ui(WINDOW *uiwindow)
{
	delwin(uiwindow);
	endwin();
	refresh();
}

int show_matrix(t_cell matrix[MAXX][MAXY])
{
	int i;
	int j;
	int intensity;
	int color_map[MAX_INTENSITY + 1] = COLOR_MAP;
	int nb_shown;

	nb_shown = 0;
	i = -1;
	while (++i < MAXX)
	{
		j = -1;
		while (++j < MAXY)
		{
			intensity = matrix[i][j].intensity;
			color_set(color_map[intensity], 0);
			mvaddch(j, i, matrix[i][j].character);
			if (color_map[intensity] != MIN_INTENSITY)
				nb_shown += 1;
		}
	}
	refresh();
	return (nb_shown);
}
