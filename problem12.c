#include <stdio.h>


//see http://code.jasonbhill.com/sage/project-euler-problem-12/ 

/*
 * Basically a triangle number n is sum 1 to n which is
 * (n * (n + 1))/2
 * so find prime factors and powers for n and n + 1 and only one is even
 * so discard one power of 2 for that one to offset the / 2 in the formula
 *
 * example n = 14 = 105 which has 1, 3, 5, 7, 15, 21, 35, 105 = 8 divisors
 * n divisors 2 * 7
 * n + 1 = 15 has divisors 3 * 5
 *
 * formula is (a_1 + 1)(a_i + 1) ... * p_1 * (p_2 + 1) .. (p_n + 1)
 * where a_1 are exponents of prime factors of odd one p_1 is exponent
 * of 2, p_i exponents of the rest of even one
 *
 * so triangle number 14 has  1*(1+1) * (1 + 1)*(1 + 1) = 8



int num_divisors(unsigned long n)
{
	if (n % 2 == 0)
		n /= 2;
	int divisors = 1, count = 0;
	while (n % 2 == 0) {
		n /= 2;
		++count;
	}
	divisors *= count + 1;
	int p = 3;
	while (n != 1) {
		count = 0;
		while (n % p == 0) {
			n /= p;
			++count;
		}
		divisors *= count + 1;
		p += 2;
	}	
	return divisors;
}


int main(int argc, char** argv)
{
	unsigned long n = 10;
	int n_divisors, n_plus_one_divisors;

	n_divisors = num_divisors(n);
	n_plus_one_divisors = num_divisors(n + 1);
	while (n_divisors * n_plus_one_divisors < 500) {
		++n;
		n_divisors = n_plus_one_divisors;
		n_plus_one_divisors = num_divisors(n + 1);
	}

	unsigned long triangle = (n * n + n) / 2;

	printf("The %luth triangle number %lu has %d divisors\n", n, triangle, n_divisors * n_plus_one_divisors);




	return 0;
}

