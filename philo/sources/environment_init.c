#include "philo.h"

void st_pull_chair(t_environment *env, t_round_table **chair,
		t_round_table **prev_chair, int i);

void	environment_init(t_environment *env, char **argv, int argc)
{
	int				i;
	t_round_table	*chair;
	t_round_table	*prev_chair;

	env->s_par.number_of_philo = atoi(argv[1]);
	env->s_par.time_to_die = atoi(argv[2]);
	env->s_par.time_to_eat = atoi(argv[3]);
	env->s_par.time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		env->s_par.times_to_eat = atoi(argv[5]);
	else
		env->s_par.times_to_eat = -1;
	env->table = (t_round_table **)mem_calloc(env->s_par.number_of_philo,
			sizeof(t_round_table *));
	chair = NULL;
	prev_chair = NULL;
	i = -1;
	while (++i < env->s_par.number_of_philo)
		st_pull_chair(env, &chair, &prev_chair, i);
	chair->right = *env->table;
	(*env->table)->left = chair;
	i = -1;
	while (++i < env->s_par.number_of_philo)
		pthread_create(&chair->philo.brain, NULL, philo_brain, (void *)env);
}

void st_pull_chair(t_environment *env, t_round_table **chair,
		t_round_table **prev_chair, int id)
{
	(*chair) = (t_round_table *)mem_calloc(1, sizeof(t_round_table));
	if (id == 0)
		*env->table = *chair;
	if (pthread_mutex_init(&(*chair)->fork, NULL) != 0)
		printf("failed to init mutex\n");
	(*chair)->philo.id = id;
	(*chair)->philo.alive = 1;
	(*chair)->philo.ate = 0;
	(*chair)->left = *prev_chair;
	if (*prev_chair)
		(*prev_chair)->right = (*chair);
	(*prev_chair) = *chair;
	if (id + 1 < env->s_par.number_of_philo)
		(*chair) = (*chair)->right;
}
