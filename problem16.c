#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//could be regular char since we only hold 0-9
char* binary_power(unsigned long n)
{
	int carry, prod;
	char* ret = calloc(n+1, sizeof(char)); assert(ret);
	ret[0] = 1;

	for (unsigned long pow = 0; pow < n; ++pow) {
		carry = 0;
		for (unsigned long i=0; i < n; ++i) {
			prod = 2 * ret[i] + carry;
			if (prod > 9) {
				carry = 1;
				prod %= 10;
			} else {
				carry = 0;
			}
			ret[i] = prod;
		}
	}
	return ret;
}




int main(int argc, char** argv)
{
	char* num;
	for (int n=0; n < 51; ++n) {
		num = binary_power(n);
		int i;
		for (i=n; !num[i]; --i);

		printf("2^%d = ", n);
		for (; i >= 0 ; --i)
			printf("%d", num[i]);

		printf("\n");
		free(num);
	}

	int n = 1000;
	num = binary_power(n);
	int i;
	unsigned long sum = 0;

	for (i=n; !num[i]; --i);

	printf("\n\nlen = %d\n", i+1);
	printf("2^%d = ", n);
	for (; i >= 0 ; --i) {
		printf("%d", num[i]);
		sum += num[i];
	}
	printf("\nsum of digits = %lu\n", sum);

	printf("\n");

	return 0;
}

