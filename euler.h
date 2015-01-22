#ifndef EULER_H
#define EULER_H


#define CVECTOR_IMPLEMENTATION
#include "cvector.h"

#include <assert.h>
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
/*
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
*/



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
	if (r > n)
		return 0;

	return factorial(n) / (factorial(r) * factorial(n - r));
}

//n choose r, order matters
unsigned long permutation(unsigned long n, unsigned long r)
{
	if (r > n)
		return 0;

	return factorial(n) / factorial(n - r);
}

void prime_factorization(unsigned long a, vector_i* primes, vector_i* factors, vector_i* powers)
{
	if (a < 2)
		return;

	for (int i=0; i<primes->size && primes->a[i] < sqrt(a); ++i) {
		if (a % primes->a[i] == 0) {
			a /= primes->a[i];
			push_i(factors, primes->a[i]);
			push_i(powers, 1);
		}
		while (a % primes->a[i] == 0) {
			a /= primes->a[i];
			powers->a[powers->size-1]++;
		}
	}
}

//# of divisors d(n) = (a+1)*(b+1)*(c+1)
//if prime factorization of n is p^a*q^b*r^c
//TODO
unsigned long sum_divisors_prime(unsigned long a, vector_i* primes)
{
	vector_i factors, powers;
	vec_i(&factors, 0, 10);
	vec_i(&powers, 0, 10);

	if (a == 0)
		return 0;
	if (a == 1)
		return 1;

	prime_factorization(a, primes, &factors, &powers);

	unsigned long sum = 1;
	for (int i=0; i<powers.size; ++i)
		sum *= (powers.a[i]+1);

	free_vec_i(&factors);
	free_vec_i(&powers);

	return sum;
}

unsigned long sum_proper_divisors(unsigned long a)
{
	unsigned long sum = 1;

	for (int i=2; i < sqrt(a); ++i) {
		if (a % i == 0)
			sum += i + a / i;
	}
	return sum;
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

//TODO
//maybe one to generate pascals triangle to nth level or just generate the nth level



//Sieve of Eratosthenes
//start primes size based on prime number theorem

unsigned long find_primes_upto_n(vector_i* primes_out, unsigned long n)
{
	vector_i sieve, primes;
	vec_i(&sieve, n+1, n+1); //+ 1 for 0 position
	vec_i(&primes, 0, (double)(n*1.2)/log(n));  //prime number theorem says x/ln(x) ~ num_primes <= x 

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int num_primes = 0;
	int p = 2, mult = 2, tmp;

	push_i(&primes, p); //gotta put 2 in there
	while (1) {

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

unsigned long find_nth_prime(unsigned long n)
{
	vector_i sieve, primes;
	unsigned long sz = 100;

	while (sz/log(sz) < n) //prime number theorem, can't think of an analytical solution for this
		sz += 100;

	vec_i(&sieve, sz, sz);
	vec_i(&primes, 0, 50000);

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int p = 2, mult = 2, mult2, tmp;

	push_i(&primes, p); //gotta put 2 in there
	while (primes.size < n) {
		while (mult < sieve.size) {
			sieve.a[mult] = 0; //mark as composite
			mult += p;
		}
		mult = p + 1;
		while (!sieve.a[mult]) {
			++mult;

			//this should never happen since I set sieve size based on
			//prime number theorem
			/*
			if (mult >= sieve.size) {
				tmp = sieve.size;
				extend_i(&sieve, 100000);
				for (int i=tmp; i < sieve.size; ++i)
					sieve.a[i] = i;

				//TODO finish just in case
				for (int j=0; j < primes.size; ++j) {
					i = tmp;
					while (i % primes.a[j])
						++i;
					mult2 = i;

					while (mult2 < sieve.size) {
						sieve.a[mult2] = 0; //mark as composite
						mult2 += primes.a[j];
					}
				}
			}
			*/
		}

		p = mult;
		assert(p);
		push_i(&primes, p);
	}

exit:
	;
	unsigned long ret = primes.a[primes.size-1];
	free_vec_i(&sieve);
	free_vec_i(&primes);

	return ret;
}


#endif
