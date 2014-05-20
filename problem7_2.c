#include <stdio.h>
#include <stdlib.h>

#define CVECTOR_IMPLEMENTATION
#include "cvector.h"



int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("usage: %s n (to find the nth prime)\n", argv[0]);
		return 0;
	}

	int n = atoi(argv[1]);

	vector_i sieve, primes;
	vec_i(&sieve, 200000, 200000);
	vec_i(&primes, 0, 50000);
	//int* sieve = malloc(n * sizeof(int));
	//int* primes = malloc(n/2 * sizeof(int));

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int num_primes = 0;
	int p = 2, mult = 2, tmp;

	push_i(&primes, p); //gotta put 2 in there
	while (primes.size < n) {
		//primes.a[primes.size] = p;

		//mult = p; already true
		while (mult < sieve.size) {
			sieve.a[mult] = 0; //mark as composite
			mult += p;
		}
		mult = p + 1;
		while (!sieve.a[mult]) {
			++mult;

			if (mult >= sieve.size) {
				tmp = sieve.size;
				extend_i(&sieve, 100000);
				for (int i=tmp; i < sieve.size; ++i) {
					sieve.a[i] = i;
					for (int j=0; j < primes.size; ++j) {
						if (!(i % primes.a[j])) {
							sieve.a[i] = 0;
							break;
						}
					}
				}
				
				//goto exit;
			}
		}

		p = mult;
		push_i(&primes, p);
	}

exit:
	printf("Found %d primes <= to %d and the nth is %d\n", primes.size, sieve.size-1, primes.a[n - 1]);


	return 0;
}
