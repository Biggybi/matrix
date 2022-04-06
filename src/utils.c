/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biggybi <biggybi@protonmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:19:23 by biggybi           #+#    #+#             */
/*   Updated: 2022/04/06 00:19:23 by biggybi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double rand_zero_to_one()
{
    return ((double)rand() / (double)RAND_MAX);
}

char randchar()
{
    return (33 + (rand() % (127 - 32)));
}

