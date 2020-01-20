
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "euler.h"





int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("usage: %s [str to generate permutations of]\n", argv[0]);
		return 0;
	}

	perm_state s;

	char* string = strdup(argv[1]);


	int i=1;
	for (char* p = init_perm_iterator(&s, string); p; p = next_perm(&s)) {
		if (i % 1000000 == 0)
			puts(p);
		i++;
	}

	free(string);


	return 0;
}
