#ifndef INCLUDES_H
# define INCLUDES_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

# define UNUSED(X) (void)(X);
# define PANIC(X) dprintf(STDERR_FILENO, "Err: [%s]\n", X);\
	exit(EXIT_FAILURE);

#endif /* INCLUDES_H */
