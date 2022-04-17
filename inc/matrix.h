#ifndef MATRIX_H
# define MATRIX_H

# include <curses.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# define COMMAND_SHIFT 's'

# define REFRESH 50000L

# define MAX_INTENSITY 13
# define MIN_INTENSITY 1

# define MAXX 200
# define MAXY 60

# define MAX_TOP_MARGIN 0
# define PROB_SPAWN_MIDDLE 0.2

# define DRIPS 100000
# define SPEED_SPAWN 6
# define PROB_SPAWN .95
# define PROB_DIM 0.50
# define PROB_DIM_MAXED 1
# define PROB_CHANGE 0.95

# define DECAY_STEP 0.000
# define DECAY_DELAY 10000L

# define COLOR_SHIFT_RATE 0
# define COLOR_SHIFT_STEP 2
# define COLOR_MIN 0
# define COLOR_MAX 200

# define COLOR_MAP {1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 3, 6}

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

typedef struct  s_color
{
	int r;
	int g;
	int b;
	int r_up;
	int g_up;
	int b_up;
	int cycles;
}				t_color;

extern t_color color;

int		ui_init(WINDOW *uiwindow, char user_color);
void	ui_clean();

void	colors_init(char user_color);
void	colors_shift();

void	matrix_run();

void    drips_add(t_drip drips[], float prob_spawn);
void    drips_update(t_cell matrix[MAXX][MAXY], t_drip drips[]);
void    drip_init(t_drip drips[]);

double	rand_zero_to_one();
char	randchar();

#endif
