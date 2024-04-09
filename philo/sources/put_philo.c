#include "philo.h"

void	st_top_philo(t_round_table *philo);
void	st_double_philo(t_round_table *left_philo, t_round_table *right_philo);
void	st_table_top();
void	st_table_bottom();

void	put_philo(t_environment env)
{
	int				amount = env.s_par.number_of_philo * .5;
	t_round_table	*left_philo;
	t_round_table	*right_philo;

	left_philo = (*env.table);
	right_philo = left_philo->right;
	if (env.s_par.number_of_philo % 2 != 0)
	{
		st_top_philo(left_philo);
		right_philo = left_philo->right;
		left_philo = left_philo->left;
		st_table_top();
	}
	else
		st_table_top();
	for (int i = 0; i < amount; i++)
	{
		st_double_philo(left_philo, right_philo);
		right_philo = right_philo->right;
		left_philo = left_philo->left;
	}
	st_table_bottom();
}

void	st_top_philo(t_round_table *philo)
{
	printf("\t\t\t                        ^\n");
	printf("\t\t\t                     ( o O )\n");
	printf("\t\t\t                    /       \\\n");
	printf("\t\t\t                   (   ---   )\n");
	printf("\t\t\t                    \\       /\n");
	printf("\t\t\t                       |%i|\n", philo->philo);
	printf("\t\t\t                   ----    ----\n");
}

void	st_double_philo(t_round_table *left_philo, t_round_table *right_philo)
{
	printf("\t\t\t            |                        |\n");
	printf("\t\t\t     ^      |                        |       ^\n");
	printf("\t\t\t  (    O    |                        |     O    )\n");
	printf("\t\t\t (      >   |                        |    <      )\n");
	printf("\t\t\t  (   --    |                        |     --   )\n");
	printf("\t\t\t    ||%i     |                        |      %i||\n", left_philo->philo,
			right_philo->philo);
	printf("\t\t\t   /  \\     |                        |      /  \\\n");
}

void	st_table_top()
{
	printf("\t\t\t\t     *----------------------*\n");
	printf("\t\t\t\t    /                        \\\n");
}

void	st_table_bottom()
{
	printf("\t\t\t\t    \\                        /\n");
	printf("\t\t\t\t     *----------------------*\n");
}

