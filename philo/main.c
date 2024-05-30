#include "philo.h"

int	main(int argc, char **argv)
{
	t_environment	env;
	t_round_table	*chair;

	if (argc < 5 || argc > 6)
		return (FALSE);
	environment_init(&env, argv, argc);
	put_philo(env);
	chair = *env.table;
	while (1)
	{
		if (!panopticon_tower(&env))
			break ;
	}
	//environment_end(&env);
	return (TRUE);
}
