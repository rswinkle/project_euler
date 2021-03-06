#include <stdio.h>
#include <stdlib.h>

#include "c_utils.h"

#define CVECTOR_IMPLEMENTATION
#include "cvector.h"



int main(int argc, char** argv)
{

	c_array file_string, names;
	file_open_read("problem22.txt", "r", &file_string);

	split(&file_string, ",", 1, &names);


	c_array *results = (c_array*)names.data;

	cvector_str names2;
	cvec_str(&names2, 0, 3000);
	for (int i=0; i < names.len; ++i) {
		results[i].data[results[i].len-1] = '\0'; //cut off ending '"'
		results[i].data++; //cut off starting '"'
		//printf("%d: %s\n", i, results[i].data);
		cvec_push_str(&names2, results[i].data);
	}

	qsort((void*)names2.a, names2.size, sizeof(char*), cmp_string_lt);

	unsigned long sum, total = 0;
	for (int i=0; i < names2.size; ++i) {
		sum = 0;
		for (int j=0; j < strlen(names2.a[i]); ++j)
			sum += names2.a[i][j] - 'A' + 1;

		total += sum * (i + 1);
		printf("%d: %s\n", i, names2.a[i]);
	}
	
	printf("The total of all name scores is %lu\n", total);


	cvec_free_str(&names2);


	return 0;
}

