#include <stdio.h>
#include <math.h>


#define CVECTOR_IMPLEMENTATION
#include "cvector.h"


unsigned long sum_proper_divisors(unsigned long a)
{
	unsigned long sum = 1;

	for (int i=2; i < sqrt(a); ++i) {
		if (a % i == 0)
			sum += i + a / i;
	}
	return sum;
}



int main(int argc, char** argv)
{
	
	vector_i div_sum;
	vec_i(&div_sum, 10000, 10000);

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




	return 0;
}

