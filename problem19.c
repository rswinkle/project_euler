#include <stdio.h>
#include <stdlib.h>

#define CVECTOR_IMPLEMENTATION
#include "cvector.h"

typedef enum day
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
} day;

int main(int argc, char** argv)
{
	cvector_i century;
	cvec_i(&century, 0, 40000);

	day cur_day = TUESDAY;
	int date = 0;
	int count_sun = 0;

	for (int year = 1901; year <= 2000; ++year) {
		for (int month = 1; month <= 12; ++month) {
			if (month == 2) {
				if (year % 4 == 0) { // (!(year & 0x3))
					cvec_extend_i(&century, 29);
				} else {
					cvec_extend_i(&century, 28);
				}
			} else if (month == 4 || month == 6 || month == 9 || month == 11) {
				cvec_extend_i(&century, 30);
			} else {
				cvec_extend_i(&century, 31);
			}

			if (cur_day == SUNDAY)
				++count_sun;

			while (date < century.size) {
				century.a[date++] = cur_day;
				cur_day++;
				cur_day %= 7;
			}
		}
	}

	printf("sundays on 1st of month 1901 through 2000 = %d\n", count_sun);

	cvec_free_i(&century);



	return 0;
}

