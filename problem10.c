#include <stdio.h>

#define CVECTOR_IMPLEMENTATION
#include "cvector.h"

unsigned long find_primes_upto_n(vector_i* primes_out, unsigned long n)
{
	vector_i sieve, primes;
	vec_i(&sieve, n+1, n+1); //+ 1 for 0 position
	vec_i(&primes, 0, 50000);

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int num_primes = 0;
	int p = 2, mult = 2, tmp;

	push_i(&primes, p); //gotta put 2 in there
	while (primes.size < n) {
		//mult = p; already true
		while (mult < sieve.size) {
			sieve.a[mult] = 0; //mark as composite
			mult += p;
		}
		mult = p + 1;
		while (!sieve.a[mult]) {
			++mult;

			if (mult >= sieve.size) {
				/*
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
				*/
				
				goto exit;
			}
		}

		p = mult;
		push_i(&primes, p);
	}

exit:

	*primes_out = primes;
	free_vec_i(&sieve);
	return primes.size;
}



int main(int argc, char** argv)
{

	if (argc != 2) {
		printf("usage: %s n (to find all primes <= n)\n", argv[0]);
		return 0;
	}

	char* end;

	unsigned long n = strtoul(argv[1], &end, 10);

	vector_i primes;
	find_primes_upto_n(&primes, n);

	printf("found %u primes\n", primes.size);
	unsigned long sum = 0;
	for (int i=0; i < primes.size; ++i) {
		sum += primes.a[i];
		//printf("%lu  %lu\n", sum, primes.a[i]);
	}

	printf("the sum of all primes up to %lu is %lu\n", n, sum);

	free_vec_i(&primes);


	return 0;
}

