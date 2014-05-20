#include <stdio.h>

#define MAX_LEN sizeof(int)*8

char* int_to_str(int num, int base)
{
	static char buf[MAX_LEN+1];
	static char digits[] = "0123456789ABCDEF";

	char* ret;
	char *pos = buf + MAX_LEN-1;
	int tmp = (num < 0) ? -num : num;

	while (tmp != 0) {
		*pos-- = digits[tmp % base];
		tmp /= base;
	}

	if (num < 0) {
		*pos = '-';
	} else {
		pos++;
	}

	ret = calloc(buf+MAX_LEN+1-pos, sizeof(char));
	if (!ret) {
		fprintf(stderr, "Failed to allocate memory!\n");
		return NULL;
	}
	
	return memcpy(ret, pos, buf+MAX_LEN-pos);  /* memcpy returns to, and calloc already nulled last char */

}

int main()
{
	int tmp, len, k, l;
	char buf[7];
	int max = 0;
	for (int i=999; i > 99; --i) {
		for (int j=i; j > 99; --j) {
			tmp = i * j;
			if (tmp < max) //all i * j's from here down will be too small anyway
				break;

			snprintf(buf, 7, "%d", tmp);
			len = strlen(buf);
			for (k=0, l=len-1; k <= l; ++k, --l) {
				if (buf[k] != buf[l])
					break;
			}
			if (k > l)
				max = (tmp > max) ? tmp : max;
		}
	}

	printf("%d is the largest palindrome that is a product of 2 3-digit numbers\n", max);


	return 0;
}
