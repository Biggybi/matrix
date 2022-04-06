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

static int cycles = 0;
t_color color;

void colors_apply()
{
	int i;

	i = -1;
	while (++i < 7)
		init_color(i, i * color.r, i * color.g, i * color.b);
}

void	colors_shift()
{
	static int r_up = 1;
	static int g_up = 1;
	static int b_up = 1;
	int selected_color;

	if (COLOR_SHIFT_RATE > 0 && cycles % COLOR_SHIFT_RATE != 0)
	{
		cycles++;
		return ;
	}
	selected_color = rand() % 3;
	if (selected_color == 0)
	{
		r_up = (color.r >= 200 && r_up == 1) ? -1 : r_up;
		r_up = (color.r <= 0 && r_up == -1) ? 1 : r_up;
		color.r += r_up * COLOR_SHIFT_STEP;
	}
	if (selected_color == 1)
	{
		g_up = (color.g >= 200 && g_up == 1) ? -1 : g_up;
		g_up = (color.g <= 0 && g_up == -1) ? 1 : g_up;
		color.g += g_up * COLOR_SHIFT_STEP;
	}
	if (selected_color == 2)
	{
		b_up = (color.b >= 200 && b_up == 1) ? -1 : b_up;
		b_up = (color.b <= 0 && b_up == -1) ? 1 : b_up;
		color.b += b_up * COLOR_SHIFT_STEP;
	}
	if (color.r > 200) color.r = 200;
	if (color.g > 200) color.g = 200;
	if (color.b > 200) color.b = 200;
	if (color.r < 0) color.r = 0;
	if (color.g < 0) color.g = 0;
	if (color.b < 0) color.b = 0;
	cycles++;
	colors_apply();
}

void colors_init(char user_color)
{
	int i;

	i = -1;
	while (++i < 8)
		init_pair(i + 1, i, COLOR_BLACK);
	if (user_color == 'w')
		color = (t_color){.r = 200, .g = 200, .b = 200};
	else if (user_color == 'g')
		color = (t_color){.r = 0, .g = 200, .b = 0};
	else if (user_color == 'G')
		color = (t_color){.r = 0, .g = 100, .b = 0};
	else if (user_color == 'r')
		color = (t_color){.r = 200, .g = 0, .b = 0};
	else if (user_color == 'R')
		color = (t_color){.r = 100, .g = 0, .b = 0};
	else if (user_color == 'B')
		color = (t_color){.r = 0, .g = 0, .b = 200};
	else if (user_color == 'b')
		color = (t_color){.r = 0, .g = 200, .b = 200};
	else if (user_color == 'm')
		color = (t_color){.r = 200, .g = 0, .b = 200};
	else if (user_color == 'M' || user_color == 'p')
		color = (t_color){.r = 100, .g = 0, .b = 100};
	else if (user_color == 'y')
		color = (t_color){.r = 200, .g = 200, .b = 0};
	else if (user_color == 'Y')
		color = (t_color){.r = 200, .g = 200, .b = 100};
	else if (user_color == 'o')
		color = (t_color){.r = 200, .g = 100, .b = 0};
	else if (user_color == 'O')
		color = (t_color){.r = 100, .g = 50, .b = 0};
	else if (user_color == '?')
		color = (t_color){.r = rand() % 200, .g = rand() % 200, .b = rand() % 200};
	colors_apply();
}
