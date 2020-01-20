
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "euler.h"

#include "c_utils.h"

//#define CVECTOR_IMPLEMENTATION
//#include "cvector.h"

/*
NameError: name 'math' is not defined
>>> factorial(10)
3628800
>>> factorial(9)
362880
>>> 1000000 % 362880
274240
>>> 1000000 / 362880
2.755731922398589
>>> factorial(8)
40320
>>> 274240 % 40320
32320
>>> 274240 / 40320
6.801587301587301
>>> factorial(70
... 
KeyboardInterrupt
>>> factorial(7)
5040
>>> 40320 / 5040
8.0
>>> 32320 / 5040
6.412698412698413


*/



int main(int argc, char** argv)
{
	if (argc != 3) {
		printf("usage: %s symbol_str nth_permutation\n", argv[0]);
		return 0;
	}

	char str[256];
	char final[256] = { 0 };
	strncpy(str, argv[1], 256);
	if (str[255]) {
		puts("Your string is impossibly long!\n");
		return 0;
	}

	unsigned long perms_left = atol(argv[2]);

	unsigned long symbols_left = strlen(str);
	unsigned long total_perms = factorial(symbols_left);

	int used = 0;
	unsigned long next;
	unsigned long tmp;

	qsort(str, symbols_left, 1, cmp_char_lt);

	if (perms_left > total_perms) {
		printf("There are only %lu permutations in the string you provided!\n", total_perms);
		return 0;
	} else if (perms_left == total_perms) {  //just reverse it cause it's the very last one
		for (int i=symbols_left-1; i>=0; --i)
			putchar(str[i]);
		putchar('\n');
	}


	/*
	while () {
		--symbols_left;
		 next = factorial(symbols_left-1);

		remainder = perms_left % next;
		tmp = perms_left / next;
		if (remainder == 0) {
			final[used] = str[tmp-1+used] //this +used stuff won't work
		perms_left

		final[used] = str[tmp+used];
		++used;
	}
	*/


	return 0;
}



