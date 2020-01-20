
#include "euler.h"
#include "c_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>


int main(int argc, char** argv)
{
	unsigned long triangle[100][100];
	int i = 0;
	unsigned long tmp;

	c_array triangle_str;

	file_open_read("triangle_67.txt", "r", &triangle_str);


	char* start, *end;


	int row = 0, col = 0;
	start = triangle_str.data;
	while (1) {
		tmp = strtoul(start, &end, 10);
		if (end == start)
			break;
		triangle[row][col++] = tmp;
		if (col > row) {
			row++;
			col = 0;
		}
		start = end;
	}

	for (i = 98; i >= 0; --i) {
		for (int j=0; j <= i; ++j) {
			triangle[i][j] += MAX(triangle[i+1][j], triangle[i+1][j+1]);
		}
	}

	printf("\n\nthe max sum is %lu\n", triangle[0][0]);







	



	return 0;
}


