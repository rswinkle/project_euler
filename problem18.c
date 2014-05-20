#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

char triangle_str[] = "75                                          "
                      "95 64                                       "
                      "17 47 82                                    "
                      "18 35 87 10                                 "
                      "20 04 82 47 65                              "
                      "19 01 23 75 03 34                           "
                      "88 02 77 73 07 63 67                        "
                      "99 65 04 28 06 16 70 92                     "
                      "41 41 26 56 83 40 80 70 33                  "
                      "41 48 72 33 47 32 37 16 94 29               "
                      "53 71 44 65 25 43 91 52 97 51 14            "
                      "70 11 33 28 77 73 17 78 39 68 17 57         "
                      "91 71 52 38 17 14 91 43 58 50 27 29 48      "
                      "63 66 04 68 89 53 67 30 73 16 69 87 40 31   "
                      "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

int main(int argc, char** argv)
{
	unsigned long tmp_array[1000];
	int i = 0;
	unsigned long tmp;
	char* start, *end;


	start = triangle_str;
	while (1) {
		tmp = strtoul(start, &end, 10);
		if (end == start)
			break;
		tmp_array[i++] = tmp;
		start = end;
	}

	double a, b, c;
	a = 0.5;
	b = 0.5;
	c = -i;

	double tmp_sqrt = sqrt(b*b - 4 * a * c);
	int x1 = -b + tmp_sqrt; //2*a = 1 so ignore that part
	int x2 = -b - tmp_sqrt;

	printf("x1 = %d\nx2 = %d\n", x1, x2);

	unsigned long *triangle = calloc(x1 * x1, sizeof(unsigned long));
	unsigned long *triangle_max = calloc(x1 * x1, sizeof(unsigned long));
	assert(triangle);
	assert(triangle_max);

	int count = 0;
#define TRI(A, X, Y) A[(X)*x1 + (Y)]

	for (i=0; i < x1; ++i) {
		for (int j=0; j <= i; ++j) {
			TRI(triangle, i, j) = tmp_array[count++];
		}
	}

	memcpy(triangle_max, triangle, x1*x1*sizeof(unsigned long));

	//I suppose I don't really need to work in a copy if I don't need to
	//preserve the original triangle ...
	for (i = x1-2; i >= 0; --i) {
		for (int j=0; j <= i; ++j) {
			TRI(triangle_max, i, j) += max(TRI(triangle_max, i+1, j), TRI(triangle_max, i+1, j+1));
		}
	}

	for (i=0; i < x1; ++i) {
		for (int j=0; j <= i; ++j)
			printf("%lu ", TRI(triangle, i, j));
		printf("\n");
	}

	for (i=0; i < x1; ++i) {
		for (int j=0; j <= i; ++j)
			printf("%lu ", TRI(triangle_max, i, j));
		printf("\n");
	}

	printf("\n\nthe max sum is %lu\n", triangle_max[0]);







	



	return 0;
}


