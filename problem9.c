#include <stdio.h>
#include <math.h>


unsigned long gcd(unsigned long a, unsigned long b)
{
	if (!a)
		return b;
	if (!b)
		return a;

	unsigned long tmp;
	if (b > a) {
		tmp = a;
		a = b;
		b = tmp;
	}

	while (tmp = a % b) {
		a = b;
		b = tmp;
	}
	return b;
}



int main(int argc, char** argv)
{

	//brute force did work
	/*
	int A, B, C, b_plus_c;
	for (int a=1; a < 1000; ++a) {
		b_plus_c = 1000 - a;
		for (int b = 2; b < 1000; ++b) {
			C = b_plus_c - b;
			if (C * C == a * a + b * b) {
				A = a, B = b;
				goto exit;
			}
		}
	}
	*/

	if (argc != 2) {
		printf("usage: %s s (find all triplets (a,b,c) where a + b + c = s\n", argv[0]);
		return 0;
	}

	/*
 	 * Euclid's Formula:
 	 * a = m^2 - n^2, b = 2 * m * n, c = m^2 + n^2
 	 * m > n > 0 and a < b which implies a < b < c
 	 *
 	 * it's a primitive triplet iff one of m, n is even and gcd(m,n) = 1
 	 * You can get a primitive by dividing out common divisor, d
 	 * so unique representation is:
 	 * a = (m^2 - n^2) * d, b = 2 * m * n * d, c = (m^2 + n^2) * d
 	 *
 	 * so a + b + c = 2*d*m^2 + 2*m*n*d = 2 * m * d * (m + n)
 	 *
 	 * so find m > 1 such that m | s/2 and odd k (= m + n) | s/(2m)
 	 * m < k < 2m and gcd(m, k) = 1.  n = k - m, d = s/(2mk) and plug
 	 * in
 	 *
 	 *
 	 * so this finds all triples where a + b + c = s
 	 */


	int s = atoi(argv[1]);
	int s2 = s / 2;
	int mlimit = ceil(sqrt(s2)) - 1; // just sqrt and truncate?
	int sm, k, d, n, a, b, c;
	
	for (int m=2; m < mlimit; ++m) {
		if (!(s2 % m)) {
			sm = s2 / m;
			while (!(sm % 2)) //remove 2 factors
				sm /= 2;

			k = (m % 2) ? m + 2 : m + 1; //?

			while (k < 2 * m && k <= sm) {
				if (sm % k == 0 && gcd(k, m) == 1) {
					d = s2 / (k * m);
					n = k - m;
					a = d * (m * m - n * n);
					b = d * 2 * m * n;
					c = d * (m * m + n * n);
					printf("(%d, %d, %d)\n", a, b, c);
				}
				k += 2;
			}
		}
	}



exit:
//	printf("a = %d\nb = %d\nc = %d\na * b * c = %d\n", A, B, C, A * B * C);


	return 0;
}

