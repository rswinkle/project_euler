
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "euler.h"



typedef struct perm_state
{
	char* str;
	int len;
} perm_state;


char* init_perm_iterator(perm_state* state, char* str)
{
	// handle empty string?
	if (!str || !*str)
		return NULL;

	state->str = str;
	state->len = strlen(str);
	return str;
}

/*
0123
0132
0213
0231
0312
0321
1023
...
3201
3210
*/

void insertionsort(char a[], size_t n)
{
	int temp,j;

	for (int i=1; i<n; ++i) {
		j = i-1;
		temp = a[i];
		
		while (j >= 0 && a[j] > temp) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = temp;
	}

	return;
}

int next_perm_impl(char* s, int len)
{
	char tmp;

	if (len == 2) {
		if (s[0] < s[1]) {
			tmp = s[0];
			s[0] = s[1];
			s[1] = tmp;
			return 1;
		}
		return 0;
	}

	if (next_perm_impl(s+1, len-1))
		return 1;


	int next = 256; // invalid
	int n_loc = -1;
	for (int i=1; i<len; ++i) {
		// change to handle duplicates?
		if (s[i] > s[0] && s[i] < next) {
			next = s[i];
			n_loc = i;
		}
	}

	if (next != 256) {
		tmp = s[0];
		s[0] = s[n_loc];
		s[n_loc] = tmp;
		insertionsort(&s[1], len-1);
		return 1;
	}
	return 0;
}


char* next_perm(perm_state* state)
{
	if (state->len == 1)
		return NULL;

	if (next_perm_impl(state->str, state->len))
		return state->str;

	return NULL;
}


char* nth_permutation(char* s, int n)
{
	if (!s || factorial(strlen(s)) < n)
		return NULL;

	//insertionsort(s

}


int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("usage: %s [str to generate permutations of]\n", argv[0]);
		return 0;
	}

	perm_state s;

	char* string = strdup(argv[1]);


	int i=1;
	for (char* p = init_perm_iterator(&s, string); p; p = next_perm(&s)) {
		if (i % 10000000 == 0)
			puts(p);
		i++;
	}

	free(string);


	return 0;
}
