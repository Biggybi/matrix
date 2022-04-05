#ifndef MATRIX_H
# define MATRIX_H

# include <string.h>
# include <assert.h>
# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <time.h>

# define REFRESH 50000L

# define MAX_INTENSITY 13
# define MIN_INTENSITY 1

# define MAXX 260
# define MAXY 70

# define MAX_TOP_MARGIN 0
# define PROB_SPAWN_MIDDLE 0.2
/* # define PROB_SPAWN_MIDDLE 1 */

/* # define MAXX 130 */
/* # define MAXY 35 */

# define DRIPS 50000
# define SPEED_SPAWN 6
# define PROB_SPAWN .95
# define PROB_DIM 0.50
# define PROB_DIM_MAXED 1
# define PROB_CHANGE 0.95

# define DECAY_STEP 0.000
# define DECAY_DELAY 10000L

# define COLOR_MAP {1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 3, 6}
/* # define COLOR_MAP {1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6} */
/* # define COLOR_MAP {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 4, 7} */
/* # define COLOR_MAP {1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 6, 9} */

typedef struct	s_cell
{
	char		character;
	char		intensity;
}				t_cell;

typedef struct	s_drip
{
	int			x;
	int			y;
	int			live;
	int			bright;
}				t_drip;

int		ui_init(WINDOW *uiwindow, char user_color);
void	ui_clean();

void	colors_set(char user_color);

void	matrix_run();

void    drips_add(t_drip drips[], float prob_spawn);
void    drips_update(t_cell matrix[MAXX][MAXY], t_drip drips[]);
void    drip_init(t_drip drips[]);

double	rand_zero_to_one();
char	randchar();

#endif
