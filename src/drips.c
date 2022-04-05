#include "matrix.h"

void drip_init(t_drip drips[])
{
	int i;

	i = -1;
	while (++i < DRIPS)
		drips[i].live = 0;
}

void drips_add(t_drip drips[], float prob_spawn)
{
	int		i;
	int		margin;

	margin = rand() % (MAXY - MAX_TOP_MARGIN);
	if (rand_zero_to_one() > prob_spawn)
		return ;
	i = 0;
	while (i < DRIPS && drips[i].live)
		i++;
	drips[i].live = 1;
	drips[i].x = rand() % MAXX;
	if (rand_zero_to_one() < PROB_SPAWN_MIDDLE && margin > 0)
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


