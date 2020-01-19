#include <stdio.h>
#include <math.h>
#include <stdint.h>


#define CVECTOR_IMPLEMENTATION
#include "cvector.h"

typedef uint64_t u64;

u64 sum_proper_divisors(u64 a)
{
	u64 sum = 1;

	for (int i=2; i < sqrt(a); ++i) {
		if (a % i == 0)
			sum += i + a / i;
	}
	return sum;
}



int main(int argc, char** argv)
{
	
	cvector_i div_sum;
	cvec_i(&div_sum, 10000, 10000);

	int amicable_sum = 0;

	for (int i=0; i < 10000; ++i)
		div_sum.a[i] = sum_proper_divisors(i);

	for (int i=0; i < 10000; ++i) {
		if (div_sum.a[i] >= 0 && div_sum.a[i] < 10000 && div_sum.a[div_sum.a[i]] == i && i != div_sum.a[i]) {
			printf("%d\t%d\n", i, div_sum.a[i]);
			amicable_sum += i + div_sum.a[i];
			div_sum.a[div_sum.a[i]] = -1;
			div_sum.a[i] = -1;
		}
	}


	printf("The sum of amicable numbers < 10000 is %d\n", amicable_sum);

	cvec_free_i(&div_sum);



	return 0;
}

