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
#include <stdio.h>

static int cycles = 0;
t_color color;

void colors_apply()
{
    int i;

    i = -1;
    while (++i < 7)
        init_color(i, i * color.r, i * color.g, i * color.b);
}

void color_shift(int *rgb, int *rgb_up)
{
    *rgb_up = (*rgb >= 200 && *rgb_up == 1) ? -1 : *rgb_up;
    *rgb_up = (*rgb <= 0 && *rgb_up == -1) ? 1 : *rgb_up;
    *rgb += *rgb_up * COLOR_SHIFT_STEP;
    if (*rgb > 200) *rgb = 200;
    if (*rgb < 0) *rgb = 0;
}

void colors_shift()
{
    int selected_color;

    if (COLOR_SHIFT_STEP == 0)
        return ;
    if (COLOR_SHIFT_RATE > 0 && cycles % COLOR_SHIFT_RATE != 0)
    {
        cycles++;
        return ;
    }
    selected_color = rand() % 3;
    if (selected_color == 0)
        color_shift(&color.r, &color.r_up);
    if (selected_color == 1)
        color_shift(&color.g, &color.g_up);
    if (selected_color == 2)
        color_shift(&color.b, &color.b_up);
    cycles++;
    colors_apply();
}

void color_init(int r, int g, int b)
{
    color = (t_color){.r = r, .g = g, .b = b, .r_up = -1, .g_up = -1, .b_up = -1};
}

void void_color_init()
{
    int i;

    i = -1;
    while (++i < 8)
        init_pair(i + 1, i, COLOR_BLACK);
}

void colors_init(char user_color)
{
    void_color_init();
    if (user_color == 'w') color_init(200, 200, 200);
    if (user_color == 'g') color_init(0,   200, 0);
    if (user_color == 'G') color_init(0,   100, 0);
    if (user_color == 'r') color_init(200, 0,   0);
    if (user_color == 'R') color_init(100, 0,   0);
    if (user_color == 'B') color_init(0,   0,   200);
    if (user_color == 'b') color_init(0,   200, 200);
    if (user_color == 'm') color_init(200, 0,   200);
    if (user_color == 'M') color_init(100, 0,   100);
    if (user_color == 'p') color_init(100, 0,   100);
    if (user_color == 'y') color_init(200, 200, 0);
    if (user_color == 'Y') color_init(200, 200, 100);
    if (user_color == 'o') color_init(200, 100, 0);
    if (user_color == 'O') color_init(100, 50,  0);
    if (user_color == '?') color_init(rand() % 200, rand() % 200, rand() % 200);
    colors_apply();
}
