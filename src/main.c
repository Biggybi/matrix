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
#include <stdio.h>

int main(int ac, char **av)
{
    WINDOW *uiwindow = 0;
    char user_color = (ac > 1) ? av[1][0] : 'g';;
    int color_shift = (ac > 2 && av[2][0] == 's');;

    srand(time(NULL));
    if (!ui_init(uiwindow, user_color))
        return (EXIT_FAILURE);
    matrix_run(color_shift);
    ui_clean(uiwindow);
    return (EXIT_SUCCESS);
}

