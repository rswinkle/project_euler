#include <stdio.h>

/* python 
 *
import math
sum([int(i) for i in list(str(math.factorial(100)))])
*/

unsigned long factorial(unsigned long n)
{
	unsigned long fact = 1, i = 2;
	while (i <= n) {
		fact *= i;
		++i;
	}
	return fact;
}

int main(int argc, char** argv)
{
	for (int i=0; i < 101; ++i)
		printf("%d! = %lu\n", i, factorial(i));



	return 0;
}

