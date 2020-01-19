#include <stdio.h>
#include <stdint.h>

#define CVECTOR_IMPLEMENTATION
#include "cvector.h"


typedef uint64_t u64;

u64 find_primes_upto_n(cvector_i* primes_out, u64 n)
{
	cvector_i sieve, primes;
	cvec_i(&sieve, n+1, n+1); //+ 1 for 0 position
	cvec_i(&primes, 0, 50000);

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int num_primes = 0;
	int p = 2, mult = 2, tmp;

	cvec_push_i(&primes, p); //gotta put 2 in there
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
		cvec_push_i(&primes, p);
	}

exit:

	*primes_out = primes;
	cvec_free_i(&sieve);
	return primes.size;
}



int main(int argc, char** argv)
{

	if (argc != 2) {
		printf("usage: %s n (to find all primes <= n)\n", argv[0]);
		return 0;
	}

	char* end;

	u64 n = strtoul(argv[1], &end, 10);

	cvector_i primes;
	find_primes_upto_n(&primes, n);

	printf("found %zd primes\n", primes.size);
	u64 sum = 0;
	for (int i=0; i < primes.size; ++i) {
		sum += primes.a[i];
		//printf("%lu  %lu\n", sum, primes.a[i]);
	}

	printf("the sum of all primes up to %lu is %lu\n", n, sum);

	cvec_free_i(&primes);


	return 0;
}

