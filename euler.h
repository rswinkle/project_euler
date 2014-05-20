#ifndef EULER_H
#define EULER_H


#define CVECTOR_IMPLEMENTATION
#include "cvector.h"

#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

unsigned long gcd(unsigned long a, unsigned long b)
{
	unsigned long tmp;
	while (b) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

//TODO finish
unsigned long gcd_binary(unsigned long a, unsigned long b)
{
	unsigned d = 1;

	while () {
		if (a ^ 0x1) { //a is even
			a >>= 2;
			if (b ^ 0x1) {
				b >>= 2;
				d <<= 2;
			}
		} else {
			if (b ^ 0x1) {
				b >>= 2;
				continue;
			} else {


			}
		}
	}
}




unsigned long lcm(unsigned long a, unsigned long b)
{
	return (a * b) / gcd(a, b);
}

unsigned long factorial(unsigned long n)
{
	unsigned long fact = 1, i = 2;
	while (i <= n) {
		fact *= i;
		++i;
	}
	return fact;
}
		

//n choose r, order doesn't matter
unsigned long combination(unsigned long n, unsigned long r)
{
	if (r > k)
		return 0;

	return factorial(n) / (factorial(r) * factorial(n - r));
}

//n choose r, order matters
unsigned long permutation(unsigned long n, unsigned long r)
{
	if (r > k)
		return 0;

	return factorial(n) / factorial(n - r);
}


void quadratic_formula(double a, double b, double c, double* x1, double *x2)
{
	*x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	*x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}

//nth row starts at row 0
//ie
//0         1
//1       1   1
//2     1   2   1
//etc
unsigned long* pascals_triangle_nth_row(unsigned long n)
{
	unsigned long* row = malloc((n+1) * sizeof(unsigned long));
	assert(row);

	row[0] = 1;
	row[n] = 1;
	for (unsigned long i = 1; i < n; ++i)
		row[i] = combination(n, i);

	return row;
}

//TODO combination, permutation functions
//maybe one to generate pascals triangle to nth level or just generate the nth level



//Sieve of Eratosthenes
//start primes size based on prime number theorem

unsigned long find_primes_upto_n(vector_i* primes_out, unsigned long n)
{
	vector_i sieve, primes;
	vec_i(&sieve, n+1, n+1); //+ 1 for 0 position
	vec_i(&primes, 0, n/log(n) + 50);  //prime number theorem says x/ln(x) ~ num_primes <= x 

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int num_primes = 0;
	int p = 2, mult = 2, tmp;

	push_i(&primes, p); //gotta put 2 in there
	while (primes.size < n) {

		while (mult < sieve.size) {
			sieve.a[mult] = 0; //mark as composite
			mult += p;
		}
		mult = p + 1;
		while (!sieve.a[mult]) {
			++mult;

			if (mult >= sieve.size) {
				goto exit;
			}
		}

		p = mult;
		push_i(&primes, p);
	}

exit:

	*primes_out = primes;
	free_vec_i(&sieve);
	return primes.size;
}

unsigned long find_nth_prime(unsigned long n, unsigned long sieve_size)
{
	vector_i sieve, primes;
	unsigned long sz = sieve_size ? sieve_size : //TODO
	vec_i(&sieve, n+1, n+1); //+ 1 for 0 position
	vec_i(&primes, 0, 50000);

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int num_primes = 0;
	int p = 2, mult = 2, tmp;

	push_i(&primes, p); //gotta put 2 in there
	while (primes.size < n) {
		while (mult < sieve.size) {
			sieve.a[mult] = 0; //mark as composite
			mult += p;
		}
		mult = p + 1;
		while (!sieve.a[mult]) {
			++mult;

			if (mult >= sieve.size) {
				tmp = sieve.size;
				extend_i(&sieve, 100000);
				for (int i=tmp; i < sieve.size; ++i) {
					sieve.a[i] = i;
					for (int j=0; j < primes.size; ++j) {
						if (!(i % primes.a[j])) {
							sieve.a[i] = 0;
							break;
						}
					}
				}
				
				goto exit;
			}
		}

		p = mult;
		push_i(&primes, p);
	}

exit:

}


#endif
