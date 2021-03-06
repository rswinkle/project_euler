
#include <stdio.h>

//  n/6 * (2n + 1) * (n + 1)
double sum_of_squares_to_n(double n)
{
	return (n * n * n) / 3 + (n * n) / 2 + n / 6;
}

// classic n * (n + 1) / 2
unsigned long sum_one_to_n(unsigned long n)
{
	return (n * n + n) / 2;
}


int main()
{
	int sum_of_squares, square_of_sum;
	/*
	for (int i=1; i<=100; ++i) {
		sum_of_squares += i * i;
		square_of_sum += i;
	}

	square_of_sum *= square_of_sum;

	*/

	sum_of_squares = sum_of_squares_to_n(100);
	square_of_sum = sum_one_to_n(100);
	square_of_sum *= square_of_sum;

	printf("%d - %d = %d\n", square_of_sum, sum_of_squares, square_of_sum - sum_of_squares);



	return 0;
}
