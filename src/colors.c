/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biggybi <biggybi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:21:11 by biggybi           #+#    #+#             */
/*   Updated: 2022/04/05 23:21:11 by biggybi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
t_color color;

static void colors_apply()
{
    int i;

    i = -1;
    while (++i < 7)
        init_color(i, i * color.r, i * color.g, i * color.b);
}

static void void_color_apply()
{
    int i;

    i = -1;
    while (++i < 8)
        init_pair(i + 1, i, COLOR_BLACK);
}

static void color_shift(int *rgb, int *rgb_up)
{
    *rgb_up = (*rgb >= COLOR_MAX && *rgb_up == 1) ? -1 : *rgb_up;
    *rgb_up = (*rgb <= COLOR_MIN && *rgb_up == -1) ? 1 : *rgb_up;
    *rgb += *rgb_up * COLOR_SHIFT_STEP;
    if (*rgb > COLOR_MAX) *rgb = COLOR_MAX;
    if (*rgb < COLOR_MIN) *rgb = COLOR_MIN;
}

void colors_shift()
{
    int selected_color;
	int *selection[3][2] = {
		{&color.r, &color.r_up},
		{&color.g, &color.g_up},
		{&color.b, &color.b_up}
	};
    if (COLOR_SHIFT_STEP == 0)
        return ;
    if (COLOR_SHIFT_RATE > 0 && color.cycles % COLOR_SHIFT_RATE != 0)
    {
        color.cycles++;
        return ;
    }
    selected_color = rand() % 3;
	color_shift(selection[selected_color][0], selection[selected_color][1]);
    color.cycles++;
    colors_apply();
}

static void color_init(int r, int g, int b)
{
    color.r = r;
    color.g = g;
    color.b = b;
    color.r_up = rand() % 2 ? -1 : 1;
    color.g_up = rand() % 2 ? -1 : 1;
    color.b_up = rand() % 2 ? -1 : 1;
    color.cycles = 0;
}

void colors_init(char user_color)
{
    void_color_apply();
    if (user_color == 'w') color_init(COLOR_MAX, COLOR_MAX, COLOR_MAX);
    else if (user_color == 'g') color_init(COLOR_MIN,   COLOR_MAX,   COLOR_MIN);
    else if (user_color == 'G') color_init(COLOR_MIN,   COLOR_MAX/2, COLOR_MIN);
    else if (user_color == 'r') color_init(COLOR_MAX,   COLOR_MIN,   COLOR_MIN);
    else if (user_color == 'R') color_init(COLOR_MAX/2, COLOR_MIN,   COLOR_MIN);
    else if (user_color == 'B') color_init(COLOR_MIN,   COLOR_MIN,   COLOR_MAX);
    else if (user_color == 'b') color_init(COLOR_MIN,   COLOR_MAX,   COLOR_MAX);
    else if (user_color == 'm') color_init(COLOR_MAX,   COLOR_MIN,   COLOR_MAX);
    else if (user_color == 'M') color_init(COLOR_MAX/2, COLOR_MIN,   COLOR_MAX/2);
    else if (user_color == 'p') color_init(COLOR_MAX/2, COLOR_MIN,   COLOR_MAX/2);
    else if (user_color == 'y') color_init(COLOR_MAX,   COLOR_MAX,   COLOR_MIN);
    else if (user_color == 'Y') color_init(COLOR_MAX,   COLOR_MAX,   COLOR_MAX/2);
    else if (user_color == 'o') color_init(COLOR_MAX,   COLOR_MAX/2, COLOR_MIN);
    else if (user_color == 'O') color_init(COLOR_MAX/2, COLOR_MAX/4, COLOR_MIN);
    else if (user_color == '?') color_init(rand() % COLOR_MAX, rand() % COLOR_MAX, rand() % COLOR_MAX);
    colors_apply();
}

