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





	return 0;
}



