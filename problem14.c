#include <stdio.h>

unsigned long collatz_length(unsigned long n)
{
	unsigned long len = 1;
	while (n != 1) {
		if (n % 2)
			n = 3 * n + 1;
		else
			n /= 2;
		++len;
	}
	return len;
}


int main(int argc, char** argv)
{
	unsigned long max = 0, tmp, max_n;
	for (int i = 8; i < 1000000; ++i) {
		tmp = collatz_length(i);

		if (tmp > max) {
			max = tmp;
			max_n = i;
		}
	}

	printf("the length of the longest chain with n < 1000000 is %lu starting at %lu\n", max, max_n);


	return 0;
}

