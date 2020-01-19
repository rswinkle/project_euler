#include <stdio.h>
#include <math.h>

#include "euler.h"



int main(int argc, char** argv)
{
	cvector_i abundant_nums, primes;

	cvec_i(&abundant_nums, 0, 30000);
	cvec_i(&primes, 0, sqrt(28123));

	find_primes_upto_n(&primes, (int)sqrt(28123));

	printf("There are %zd primes less than %d sqrt(28123)\n", primes.size, (int)sqrt(28123));
	for (int i=0; i<primes.size; ++i)
		printf("%d\n", primes.a[i]);


	unsigned long tmp;

	for (int i=2; i<28123; ++i) {
		tmp = sum_divisors_prime(i, &primes) - i; //proper divisors doesn't count the number itself
		if (tmp > i)
			cvec_push_i(&abundant_nums, i);
	}
		

	printf("There are %lu abundant nums\n", abundant_nums.size);
	for (int i=0; i<10; ++i)
		printf("%d\n", abundant_nums.a[i]);
	putchar('\n');

	unsigned long sum_of_failures = 0;


	/*
	int found, max, j, k;
	for (int i=1; i<28123; ++i) {
		//if (i % 100 == 0)
			//printf("%d\n", i);

		found = 0;
		for (j=0; abundant_nums.a[j]<i; ++j);
		
		max = --j;
		
		for (k=0; k<=max; ++k) {
			while (j >= 0 && abundant_nums.a[k] + abundant_nums.a[j] > i)
				--j;

			if (j < 0)
				break;
			
			if (abundant_nums.a[k] + abundant_nums.a[j] == i) {
				found = 1;
				break;
			}
		}
		if (!found)
			sum_of_failures += i;
	}
	*/
	cvector_i abundant_sums;
	cvec_i(&abundant_sums, 0, 50000);

	printf("combination(28123,2) = %lu\n", combination(28123,2));

	for (int i=0; i<abundant_nums.size; ++i) {
		;

	}
		

	printf("Sum of positive ints that can't be written as sum of 2 abundant #'s: %lu\n", sum_of_failures);

	cvec_free_i(&abundant_nums);
	cvec_free_i(&primes);
	cvec_free_i(&abundant_sums);

	return 0;
}



