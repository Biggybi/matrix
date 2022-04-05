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

static void fade_colors(int r, int g, int b)
{
	int i;

	i = -1;
	while (++i < 7)
		init_color(i, i * r, i * g, i * b);
}

void colors_set(char user_color)
{
	int i;
	i = -1;
	while (++i < 8)
		init_pair(i + 1, i, COLOR_BLACK);
	if (user_color == 'w')
		fade_colors(200, 200, 200);
	if (user_color == 'g')
		fade_colors(0, 200, 0);
	if (user_color == 'G')
		fade_colors(0, 100, 0);
	if (user_color == 'r')
		fade_colors(200, 0, 0);
	if (user_color == 'R')
		fade_colors(100, 0, 0);
	if (user_color == 'B')
		fade_colors(0, 0, 200);
	if (user_color == 'b')
		fade_colors(0, 200, 200);
	if (user_color == 'm')
		fade_colors(200, 0, 200);
	if (user_color == 'M' || user_color == 'p')
		fade_colors(100, 0, 100);
	if (user_color == 'y')
		fade_colors(200, 200, 0);
	if (user_color == 'Y')
		fade_colors(200, 200, 100);
	if (user_color == 'o')
		fade_colors(200, 100, 0);
	if (user_color == 'O')
		fade_colors(100, 50, 0);
	if (user_color == '?')
		fade_colors(rand() % 200, rand() % 200, rand() % 200);
}
