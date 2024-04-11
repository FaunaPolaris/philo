#include "philo.h"

int	main(int argc, char **argv)
{
	t_environment	env;
	t_round_table	*chair;

	if (argc != 5)
		return (FALSE);
	environment_init(&env, argv);
	put_philo(env);
	printf("Starting philosophers...\n");
	printf("The number of philosophers is:			%i\n",
			env.s_par.number_of_philo);
	printf("Time each philosopher has before dying: 	%i\n",
			env.s_par.time_to_die);
	printf("Time each philosopher takes to eat: 		%i\n",
			env.s_par.time_to_eat);
	printf("Time each philosopher needs to sleep for: 	%i\n\n",
			env.s_par.time_to_sleep);
	chair = *env.table;
	environment_end(&env);
	return (TRUE);
}
