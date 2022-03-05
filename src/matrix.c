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

void drip_init(t_drip drips[])
{
	int i;

	i = -1;
	while (++i < DRIPS)
		drips[i].live = 0;
}

double rand01()
{
	return ((double)rand() / (double)RAND_MAX);
}

char randchar()
{
	return (33 + (rand() % (127 - 32)));
}

void intensity_reduce(t_cell *cell)
{
	if ((cell->intensity == MAX_INTENSITY) && (rand01() < PROB_DIM_MAXED))
		cell->intensity--;
	else if ((cell->intensity > 0) && (rand01() < PROB_DIM))
		cell->intensity--;
}

void init_char(t_cell *cell)
{
	if (!cell->character || rand01() < PROB_CHANGE)
		cell->character = randchar();
}

void change_matrix(t_cell matrix[MAXX][MAXY])
{
	int		i;
	int		j;

	i = -1;
	while (++i < MAXX)
	{
		j = -1;
		while (++j < MAXY)
		{
			init_char(&matrix[i][j]);
			intensity_reduce(&matrix[i][j]);
		}
	}
}

void drips_add(t_drip drips[], float prob_spawn)
{
	int		i;
	int		margin;

	margin = rand() % (MAXY - MAX_TOP_MARGIN);
	if (rand01() > prob_spawn)
		return ;
	i = 0;
	while (i < DRIPS && drips[i].live)
		i++;
	drips[i].live = 1;
	drips[i].x = rand() % MAXX;
	if (rand01() < PROB_SPAWN_MIDDLE && margin > 0)
		drips[i].y = margin;
	else
		drips[i].y = 0;
	drips[i].bright = rand() % 2;
}

void drips_update(t_cell matrix[MAXX][MAXY], t_drip drips[])
{
	int		i;

	i = -1;
	while (++i < DRIPS)
		if (drips[i].live)
		{
			if (drips[i].bright)
				matrix[drips[i].x][drips[i].y].intensity = MAX_INTENSITY;
			else
				matrix[drips[i].x][drips[i].y].intensity = MIN_INTENSITY;
			if (++drips[i].y >= MAXY - 1)
				drips[i].live = 0;
		}
}

void matrix_update(t_cell matrix[MAXX][MAXY], t_drip drips[], float prob_spawn)
{
	int i;

	i = -1;
	while (++i < SPEED_SPAWN)
		drips_add(drips, prob_spawn);
	prob_spawn--;
	drips_update(matrix, drips);
	change_matrix(matrix);
}

void matrix_init(t_cell matrix[MAXX][MAXY])
{
	int		i;
	int		j;

	i = -1;
	while (++i < MAXX)
	{
		j = -1;
		while (++j < MAXY)
		{
			matrix[i][j].character = 0;
			matrix[i][j].intensity = 0;
		}
	}
}

void matrix_run()
{
	t_cell	matrix[MAXX][MAXY];
	t_drip	drips[DRIPS];
	float	prob_spawn;
	int		nb_shown;

	prob_spawn = PROB_SPAWN;
	matrix_init(matrix);
	drip_init(drips);
	nb_shown = 1;
	while (nb_shown)
	{
		matrix_update(matrix, drips, prob_spawn);
		prob_spawn -= DECAY_STEP;
		nb_shown = show_matrix(matrix);
		usleep(REFRESH);
		/* dprintf(1, "%d\n", nb_shown); */
	}
}
