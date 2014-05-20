#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

//doesn't work for primes larger than 23 ... using double would extend
//the range some
int is_prime(unsigned long n, int tests)
{
	unsigned long s = 0, s_pow = 1, d = n - 1;

	while (!(d % 2)) {
		d /= 2;
		++s;
		s_pow *= 2;
	}

	unsigned long a, tmp;

	//int is_prime = 1;
	int i, j;
	for (i=0; i < min(tests, n); ++i) {
		a = 1 + rand() % (n - 1);
		printf("%u\n", a);
		s_pow = 1;
		
		tmp = pow(a, d);
		if (tmp % n == 1) { //only for a^d
			continue;
		}

		for (j = 0; j < s; ++j) {
			tmp = pow(a, s_pow * d);
			printf("2 %lu, %lu, %lu\n", a, d, tmp);
			if (tmp % n == n - 1) {
				fprintf(stderr, "b1\n");
 				break;
			}
			s_pow *= 2;
		}
		if (j == s) {
			//printf("2 %u, %u, %u\n", n, a, d, tmp);
			printf("%u\n", s);
			return 0;
		}
	}

	return 1; //passed all tests for not-primeness
}

inline double rand_double(double min, double max)
{
	return ((double)rand()/(double)(RAND_MAX-1))*(max-min) + min;
}

inline long double rand_long_double(long double min, long double max)
{
	return ((long double)rand()/(long double)(RAND_MAX-1))*(max-min) + min;
}

inline int eql_long_double(long double a, long double b)
{
	return fabsl(a - b) < 0.01;
}

/*
inline bool eql_epsilon_double(double a, double b, double epsilon)
{
	return fabs(a - b) < epsilon;
}
*/

//long double on intel is 16 bytes in size but only uses 10
//for a 16 bit exponent and a 64 bit significand which only gives 
//20 decimal digits of precision
int is_prime_long_double(long double n, int tests)
{
	long double s = 0, s_pow = 1, d = n - 1;

	while (eql_long_double(fmodl(d, 2.0), 0.0)) {
		d /= 2;
		++s;
		s_pow *= 2;
	}
	printf("%Lf\n", s);

	long double a, tmp;

	//int is_prime = 1;
	int i, j;
	for (i=0; i < (int) min(tests, n); ++i) {
		a = floorl(rand_long_double(1, n));
		printf("a = %Lf\n", a);
		s_pow = 1;
		
		tmp = powl(a, d);
		if (eql_long_double(fmodl(tmp, n), 1.0)) { //only for a^d
			continue;
		}

		for (j = 0; j < (int)s; ++j) {
			tmp = powl(a, s_pow * d);
			printf("2 %Lf^(%Lf * %Lf) = %Lf\n", a, s_pow, d, tmp);
			if (eql_long_double(fmodl(tmp, n), n - 1)) {
				fprintf(stderr, "b1\n");
 				goto cont;
			}
			s_pow *= 2;
		}

		printf("s = %Lf\n", s);
		return 0;
cont:
		;
	}

	return 1; //passed all tests for not-primeness
}


int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("usage: %s n (to test n for primeness)\n", argv[0]);
		return 0;
	}
	
	printf("%u %u %u %u\n", sizeof(unsigned long), sizeof(unsigned long long), sizeof(unsigned int), sizeof(long double));
	printf("%d\n", LDBL_MAX_10_EXP);

	srand(time(NULL));

	unsigned long n = atoi(argv[1]);


	printf("%u is %s\n", n, (is_prime_long_double(n, 50) ? "prime" : "not prime"));




	return 0;
}
