﻿#include <stdio.h>
#include <math.h>
#include <float.h>

void prog4_1() {
	double y, x;
	unsigned n;
	printf("n=");
	scanf_s("%u", &n);
	printf("x=");
	scanf_s("%lf", &x);

	y = x;
	for (unsigned i = 0; i < n; i++) {
		y = sin(y);
	}
	printf("Y=%lf", y);
}


void prog4_2() {
	unsigned n;
	printf("n=");
	scanf_s("%u", &n);

	printf("%u = 1", n);

	for (unsigned i = 2; i <= n; ++i) {
		printf("*%u", i);
	}
	printf("\n");

	printf("%u = %u", n, n);

	for (unsigned i = n - 1; i >= 1; i--) {
		printf("*%u", i);
	}
	printf("\n");
}


void prog4_3a() {
	int n;
	float x, y, t;
	printf("x, n:");
	scanf_s("%f %d", &x, &n);

	t = 1;
	y = 1;

	for (int i = 0; i < n; i++) {
		t *= x;
		y += t;
	}

	printf("y=%f", y);
}


void prog4_3b() {
	int n;
	float x, y, t, f;
	printf("x, y, n:");
	scanf_s("%f %f %d", &x, &y, &n);

	t = 1;
	f = 1;

	for (int i = 0; i < n; i++) {
		t *= x * x * y;
		f += t;
	}

	printf("f_x=%f\n", f);
}


void prog4_4() {
	int n;
	float x, y = 0;
	printf("x, n:");
	scanf_s("%f %d", &x, &n);
	for (int i = 1; i <= n; i++) {
		y += i * pow(x, i);
	}
	printf("y= %lf", y);
}


void prog4_5() {
	unsigned n;
	printf("n= ");
	scanf_s("%u", &n);
	unsigned long long m = 1UL;
	for (unsigned i = n; i >= 2; i -= 2) {
		m *= i;
	}
	printf("%u!! = %llu \n", n, m);
}


void prog4_6b() {
	unsigned n;
	printf("n= ");
	scanf_s("%u", &n);
	double res = sqrt(3U * n);
	for (unsigned i = n - 1; i >= 1; i--) {
		res = sqrt(3U * i + res);
	}
	printf("total = %g\n", res);
}


double my_exp(double x, int n) {
	double t = 1;
	double y = 1;
	int i = 1;
	while (i <= n) {
		t *= (x / i);
		y += t;
		i++;
	}
	return y;
}
void prog4_7() {
	int n;
	double x, y;
	printf("n= ");
	scanf_s("%d", &n);
	printf("x= ");
	scanf_s(" %lf", &x);

	y = my_exp(x, n);
	printf("y=%lf, %lf", y, exp(x));
}


void prog4_8() {
	int m;
	printf("m= ");
	scanf_s("%d", &m);
	if (m < 1) {
		printf("incorrect input");
	}

	int p = 1, r = 0;
	while (p < m) {
		p *= 4;
		r++;
	}
	printf("4^%d < %d\n", r - 1, m);
	printf("k = %d", r - 1);
}


void prog4_9() {
	int n;
	printf("n= ");
	scanf_s("%d", &n);
	if (n < 1) {
		printf("incorrect input");
	}

	int p = 1, r = 0;
	while (p < n) {
		p *= 2;
		r++;
	}
	printf("2^%d = %d > %d\n", r, p, n);
	printf("r = %d", r);
}


void prog4_10() {
	double eps = 1.0;
	int k = 0;
	do {
		eps = eps / 2;
		k++;
	} while (1.0 + eps != 1.0);
	printf("k=%d zeros=%g, %g", k, eps * 2, DBL_EPSILON);
}


void prog4_11() {
	int i;
	double x, sum = 0., sum_harm = 0.;
	i = 0;
	while (1) {
		printf("a[%d]=", i);
		scanf_s("%lf", &x);

		if (fabs(x) <= 2 * DBL_EPSILON) break;

		sum += x;
		sum_harm += 1 / x;
		i++;
	}
	printf("avg = %lf, harm = %lf", sum / i, i / sum_harm);
}


int myfact(int i) {
	int p = 1;
	int f = -1;
	if (i == 0) {
		return 1;
	}
	else {
		while (p < i) {
			f *= -(p + 1);
			p += 1;
		}
		return f;

	}
}
/* prog4_12в
#include <stdio.h>
#include <math.h>

int main() {
	int i, n;
	double x, y;
	printf("x=");
	scanf_s("%lf", &x);
	printf("n=");
	scanf_s("%d", &n);
	y = 0;
	for (i = 1; i <= n; i++) {
		y = y + pow(x, pow(i, 2));
	}
	printf("y=%lf", y);
}
*/
/* prog4_22
#include <stdio.h>


int main() {
    int n, swapper, a1, a2, a3, counter = 0;
    printf("n = ");
    scanf("%d", &n);
    printf("Enter number: ");
    scanf("%d", &a3);
    printf("Enter number: ");
    scanf("%d", &a2);
    if (a3 > a2) counter++; // needed if only one neighbor counts
    for (int i = 2; i<n; i++) {
        printf("Enter number: ");
        scanf("%d", &a1);
        if (a2 > a1 && a2 > a3) {
            counter++;
            printf("\n %d %d %d. C= %d", a3, a2, a1, counter);
        }
        a3 = a2;
        swapper = a1; // needed if only one neighbor counts
        a2 = a1;
    }
    if (swapper > a3) counter ++; // needed if only one neighbor counts
    printf("There are %d numbers, that are greater then their neighbors", counter);
}
*/


int main() {
	//prog4_1();
	//prog4_2();
	//prog4_3a();
	//prog4_3b();
	//prog4_4();
	//prog4_5();
	//prog4_6b();
	//prog4_7();
	//prog4_8();
	//prog4_9();
	//prog4_10();
	//prog4_11();
	//prog4_12в();
	//prog4_22();
}