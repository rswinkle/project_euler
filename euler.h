#ifndef EULER_H
#define EULER_H


#define CVECTOR_IMPLEMENTATION
#include "cvector.h"

#include <assert.h>
#include <math.h>
#include <stdint.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

u64 gcd(u64 a, u64 b)
{
	u64 tmp;
	while (b) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

//TODO finish
/*
u64 gcd_binary(u64 a, u64 b)
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



u64 lcm(u64 a, u64 b)
{
	return (a * b) / gcd(a, b);
}

u64 factorial(u64 n)
{
	u64 fact = 1, i = 2;
	while (i <= n) {
		fact *= i;
		++i;
	}
	return fact;
}
		

//n choose r, order doesn't matter
u64 combination(u64 n, u64 r)
{
	if (r > n)
		return 0;

	return factorial(n) / (factorial(r) * factorial(n - r));
}

//n choose r, order matters
u64 permutation(u64 n, u64 r)
{
	if (r > n)
		return 0;

	return factorial(n) / factorial(n - r);
}

void prime_factorization(u64 a, cvector_i* primes, cvector_i* factors, cvector_i* powers)
{
	if (a < 2)
		return;

	for (int i=0; i<primes->size && primes->a[i] < sqrt(a); ++i) {
		if (a % primes->a[i] == 0) {
			a /= primes->a[i];
			cvec_push_i(factors, primes->a[i]);
			cvec_push_i(powers, 1);
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
u64 sum_divisors_prime(u64 a, cvector_i* primes)
{
	cvector_i factors, powers;
	cvec_i(&factors, 0, 10);
	cvec_i(&powers, 0, 10);

	if (a == 0)
		return 0;
	if (a == 1)
		return 1;

	prime_factorization(a, primes, &factors, &powers);

	u64 sum = 1;
	for (int i=0; i<powers.size; ++i)
		sum *= (powers.a[i]+1);

	cvec_free_i(&factors);
	cvec_free_i(&powers);

	return sum;
}

u64 sum_proper_divisors(u64 a)
{
	u64 sum = 1;

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
u64* pascals_triangle_nth_row(u64 n)
{
	u64* row = malloc((n+1) * sizeof(u64));
	assert(row);

	row[0] = 1;
	row[n] = 1;
	for (u64 i = 1; i < n; ++i)
		row[i] = combination(n, i);

	return row;
}

//TODO
//maybe one to generate pascals triangle to nth level or just generate the nth level



//Sieve of Eratosthenes
//start primes size based on prime number theorem

u64 find_primes_upto_n(cvector_i* primes_out, u64 n)
{
	cvector_i sieve, primes;
	cvec_i(&sieve, n+1, n+1); //+ 1 for 0 position
	cvec_i(&primes, 0, (double)(n*1.2)/log(n));  //prime number theorem says x/ln(x) ~ num_primes <= x 

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int num_primes = 0;
	int p = 2, mult = 2, tmp;

	cvec_push_i(&primes, p); //gotta put 2 in there
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
		cvec_push_i(&primes, p);
	}

exit:

	*primes_out = primes;
	cvec_free_i(&sieve);
	return primes.size;
}

u64 find_nth_prime(u64 n)
{
	cvector_i sieve, primes;
	u64 sz = 100;

	while (sz/log(sz) < n) //prime number theorem, can't think of an analytical solution for this
		sz += 100;

	cvec_i(&sieve, sz, sz);
	cvec_i(&primes, 0, 50000);

	for (int i=0; i < sieve.size; ++i) {
		sieve.a[i] = i;
	}

	int p = 2, mult = 2, mult2, tmp;

	cvec_push_i(&primes, p); //gotta put 2 in there
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
		cvec_push_i(&primes, p);
	}

exit:
	;
	u64 ret = primes.a[primes.size-1];
	cvec_free_i(&sieve);
	cvec_free_i(&primes);

	return ret;
}


// stuff from problem 24
typedef struct perm_state
{
	char* str;
	int len;
} perm_state;


char* init_perm_iterator(perm_state* state, char* str)
{
	// handle empty string?
	if (!str || !*str)
		return NULL;

	state->str = str;
	state->len = strlen(str);
	return str;
}

/*
0123
0132
0213
0231
0312
0321
1023
...
3201
3210
*/

void euler_char_insertionsort(char a[], size_t n)
{
	int temp,j;

	for (int i=1; i<n; ++i) {
		j = i-1;
		temp = a[i];
		
		while (j >= 0 && a[j] > temp) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = temp;
	}

	return;
}

int next_perm_impl(char* s, int len)
{
	char tmp;

	if (len == 2) {
		if (s[0] < s[1]) {
			tmp = s[0];
			s[0] = s[1];
			s[1] = tmp;
			return 1;
		}
		return 0;
	}

	if (next_perm_impl(s+1, len-1))
		return 1;


	int next = 256; // invalid
	int n_loc = -1;
	for (int i=1; i<len; ++i) {
		// change to handle duplicates?
		if (s[i] > s[0] && s[i] < next) {
			next = s[i];
			n_loc = i;
		}
	}

	if (next != 256) {
		tmp = s[0];
		s[0] = s[n_loc];
		s[n_loc] = tmp;
		euler_char_insertionsort(&s[1], len-1);
		return 1;
	}
	return 0;
}


char* next_perm(perm_state* state)
{
	if (state->len == 1)
		return NULL;

	if (next_perm_impl(state->str, state->len))
		return state->str;

	return NULL;
}


//TODO
char* nth_permutation(char* s, int n)
{
	if (!s || factorial(strlen(s)) < n)
		return NULL;

	//insertionsort(s

}


#endif
