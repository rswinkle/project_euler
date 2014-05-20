#include <stdio.h>

#include "c_utils.h"

/*
 * "Since the required answer to this problem only requires the first 10 digits of the sum,
 * there is absolutely no need to add more than the first 11 digits of each of the 100 numbers,
 * yielding a 13-digit number. Adding the 12th++ digits could never affect more than
 * the 11th digit of the sum."
 *
*/

int main(int argc, char** argv)
{
	if (argc != 3) {
		printf("usage: %s file_name num_digits\nreads all numbers (separated by newlines) and displays the first num_digits of their sum\n", argv[0]);
		return 0;
	}

	FILE* file = fopen(argv[1], "r");

	unsigned long sum = 0;
	int len, num_digits = atoi(argv[2]);
	char* num_str, *end;

	num_digits++;
	num_str = freadline(file);
	while (num_str) {
		len = strlen(num_str);
		if (len - num_digits >= 0) {
 		   num_str[num_digits] = 0; //only care about first n + 1 digits
		   sum += strtoul(num_str, &end, 10); //assume no errors
		}
		free(num_str);
		num_str = freadline(file);
	}

	char buf[100];
	snprintf(buf, 100, "%lu", sum);
	--num_digits;
	buf[num_digits] = 0;
	printf("The first %u digits are %s\n", num_digits, buf);


	return 0;
}

