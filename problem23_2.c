#include <stdio.h>
#include <math.h>


#define CVECTOR_IMPLEMENTATION
#include "cvector.h"

int sum_of_divisors(int n)
{
	int prod=1, p;
	for (int k=2; k*k<=n; ++k) {
		p = 1;
		while(n % k == 0) {
			p = p*k + 1;
			n /= k;
		}
		prod *= p;
	}
	if (n > 1)
		prod *= 1 + n;
	return prod;
}

unsigned long sum_proper_divisors(unsigned long a)
{
	unsigned long sum = 1;

	for (int i=2; i*i <= a; ++i) {
		if (a % i == 0)
			if (i*i == a)
				sum += i;
			else
				sum += i + a / i;
	}
	return sum;
}


int main(int argc, char** argv)
{
	char* is_abundant = calloc(28124, 1);

	vector_i abundant;
	vec_i(&abundant, 0, 1000);

	int tmp;
	for (int i=12; i<28123; ++i) {
		tmp = sum_proper_divisors(i);
		if (tmp > i) {
			printf("%d is abundant, tmp = %d\n", i, tmp);
			is_abundant[i] = 1;
			push_i(&abundant, i);
		}
	}
	printf("abundant size = %lu\n", abundant.size);

	int sum = 0, found;
	for (int i=1; i<28123; ++i) {
		/*
		if (i < 24) {
			sum += i;
			continue;
		}
		*/

		found = 0;
		for (int j = 0; j < abundant.size; ++j) {
			for (int k = j; k < abundant.size; ++k) {
				if (abundant.a[j] + abundant.a[k] == i) {
					found = 1;
					goto found_out;
				}
			}
		}

		sum += i;
		printf("i = %d  sum = %d\n", i, sum);

found_out:
		;
	}
		


	printf("sum = %d\n", sum);



	return 0;
}



