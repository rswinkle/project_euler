#include <stdio.h>
#include <math.h>

unsigned long find_lattice_paths(unsigned long n)
{
	unsigned long n_paths = 0;
	if (n == 0)
		return 0;

	if (n == 1)
		return 2;

	for (unsigned long i = 1; i < n; ++i)
		n_paths += 2 * find_lattice_paths(i);

	unsigned long tmp = (n - 2) ? pow(n-2, n-2) : 0;
	//printf("%lu %lu %lu\n", n, n_paths, tmp);

	return n_paths + 2 * tmp + 2;
}


int main(int argc, char** argv)
{
	for (int i=0; i < 21; ++i)
		printf("%dx%d = %lu\n", i, i, find_lattice_paths(i));


	combination(40,20);




	return 0;
}

