#include <stdio.h>

int main(int argc, char** argv)
{
	char* ones_strings[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char* tens_strings[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	char* teens_strings[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	int ones[10] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
	int tens[10] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };  /*put 0 for ten cause ten is 0th in teens */
	int teens[10] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };

	int hundred = 7, and_len = 3, thousand = 8; 

	int total = 0;
	int tmp_total = 0;
	for (int i=0; i < 10; ++i) {
		tmp_total = ones[i] + ((i) ? hundred : 0);

		//total += 99 * ((i) ? and_len : 0); //no and for 100, 200 etc

		for (int j=0; j < 10; ++j) {

			for (int k=0; k < 10; ++k) {
				if (i) {
					printf("%s ", ones_strings[i]);
					printf("hundred ");
					total += tmp_total;
				}

				if (i && (j || k)) {
					printf("and ");
					total += 3;
				}
				if (j > 1)
					printf("%s ", tens_strings[j]);

				total += tens[j];

				if (j == 1) {
					total += teens[k];
					printf("%s ", teens_strings[k]);
				} else {
					total += ones[k];
					printf("%s ", ones_strings[k]);
				}
				printf("\n");
			}
			//printf("%d\n", total);
		}
	}

	printf("%s thousand\n", ones_strings[1]);
	total += ones[1] + thousand;

	printf("The total number of letters = %d\n", total);
			


	return 0;
}

