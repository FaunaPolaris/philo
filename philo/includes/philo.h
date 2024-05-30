#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct s_simulation_params
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	times_to_eat;
}	t_simulation_params;

typedef struct s_philosopher
{
	pthread_t	brain;
	int			id;
	int			ate;
	int			alive;
}	t_philosopher;

typedef struct s_round_table
{
	t_philosopher			philo;
	pthread_mutex_t			fork;
	struct s_round_table	*left;
	struct s_round_table	*right;
}	t_round_table;

typedef struct s_environment
{
	t_round_table		**table;
	t_simulation_params	s_par;
}	t_environment;

void	*mem_calloc(int n, int size);
void	environment_init(t_environment *env, char **argv, int argc);
void	environment_end(t_environment *env);
void	*philo_brain(void *arg);
void	put_philo(t_environment env);
int		panopticon_tower(t_environment *env);

void	lefthand_philo_pick_fork(t_round_table *chair,
		pthread_mutex_t mouth);
void	lefthand_philo_return_fork(t_round_table *chair,
		pthread_mutex_t mouth);
void	righthand_philo_pick_fork(t_round_table *chair,
		pthread_mutex_t mouth);
void	righthand_philo_return_fork(t_round_table *chair,
		pthread_mutex_t mouth);

#endif
