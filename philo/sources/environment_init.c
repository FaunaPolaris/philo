#include "philo.h"

void st_pull_chair(t_environment *env, t_round_table **chair,
		t_round_table **prev_chair, int i);

void	environment_init(t_environment *env, char **argv)
{
	int				i;
	t_round_table	*chair;
	t_round_table	*prev_chair;

	env->s_par.number_of_philo = atoi(argv[1]);
	env->s_par.time_to_die = atoi(argv[2]);
	env->s_par.time_to_eat = atoi(argv[3]);
	env->s_par.time_to_sleep = atoi(argv[4]);
	env->table = (t_round_table **)mem_calloc(env->s_par.number_of_philo,
			sizeof(t_round_table *));
	chair = NULL;
	prev_chair = NULL;
	i = -1;
	while (++i < env->s_par.number_of_philo)
		st_pull_chair(env, &chair, &prev_chair, i);
	chair->right = *env->table;
	(*env->table)->left = chair;
}

void st_pull_chair(t_environment *env, t_round_table **chair,
		t_round_table **prev_chair, int i)
{
	(*chair) = (t_round_table *)mem_calloc(1, sizeof(t_round_table));
	if (i == 0)
		*env->table = *chair;
	(*chair)->philo.id = i;
	(*chair)->philo.left_hand = 0;
	(*chair)->philo.right_hand = 0;
	(*chair)->philo.alive = 1;
	(*chair)->fork = 1;
	(*chair)->left = *prev_chair;
	if (*prev_chair)
		(*prev_chair)->right = (*chair);
	(*prev_chair) = *chair;
	if (i + 1 < env->s_par.number_of_philo)
		(*chair) = (*chair)->right;
}
