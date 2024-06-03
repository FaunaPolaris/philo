#include "philo.h"

void	say_state_change(char *new_state, int id, pthread_mutex_t *mouth)
{
	struct timeval	tv;

	pthread_mutex_lock(mouth);
	gettimeofday(&tv, NULL);
	printf("%-9li %-2i %s\n", tv.tv_sec * 1000 + (int)(tv.tv_usec * .001),
			id, new_state);
	pthread_mutex_unlock(mouth);
}
