#include "philo.h"

void	*mem_calloc(int	 n, int size)
{
	void	*output;

	output = malloc(n * size);
	memset(output, '\0', n * size);
	return (output);
}
