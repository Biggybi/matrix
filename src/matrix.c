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

static void intensity_reduce(t_cell *cell)
{
    if ((cell->intensity == MAX_INTENSITY) && (rand_zero_to_one() < PROB_DIM_MAXED))
        cell->intensity--;
    else if ((cell->intensity > 0) && (rand_zero_to_one() < PROB_DIM))
        cell->intensity--;
}

static void init_char(t_cell *cell)
{
    if (!cell->character || rand_zero_to_one() < PROB_CHANGE)
        cell->character = randchar();
}

static void matrix_set(t_cell matrix[MAXX][MAXY])
{
    int        i;
    int        j;

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

static void matrix_update(t_cell matrix[MAXX][MAXY], t_drip drips[], float prob_spawn)
{
    int i;

    i = -1;
    while (++i < SPEED_SPAWN)
        drips_add(drips, prob_spawn);
    prob_spawn--;
    drips_update(matrix, drips);
    matrix_set(matrix);
}

static void matrix_init(t_cell matrix[MAXX][MAXY])
{
    int        i;
    int        j;

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

static int matrix_show(t_cell matrix[MAXX][MAXY])
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

void matrix_run(int color_shift)
{
    t_cell    matrix[MAXX][MAXY];
    t_drip    drips[DRIPS];
    float    prob_spawn;
    int        nb_shown;

    prob_spawn = PROB_SPAWN;
    matrix_init(matrix);
    drip_init(drips);
    nb_shown = 1;
    while (nb_shown)
    {
        if (color_shift) colors_shift();
        matrix_update(matrix, drips, prob_spawn);
        prob_spawn -= DECAY_STEP;
        nb_shown = matrix_show(matrix);
        usleep(REFRESH);
    }
}
