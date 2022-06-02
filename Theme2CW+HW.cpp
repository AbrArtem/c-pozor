#include <stdio.h>
#include <math.h>
#include <iostream>

void prog2_1() {
	double x;
	printf("x=");
	scanf_s("%lf", &x);
	printf("cosx=%g", cos(x));
}


void prog2_2() {
	double a, b;
	printf("a=");
	scanf_s("%lf", &a);
	printf("b=");
	scanf_s("%lf", &b);
	printf("c=%g", hypot(a, b));
}


void prog2_3() {
	double a, b, c;
	printf("a=");
	scanf_s("%lf", &a);
	printf("b=");
	scanf_s("%lf", &b);
	printf("c=");
	scanf_s("%lf", &c);
	double p = (a + b + c) / 2;
	printf("S=%g", sqrt(p * (p - a) * (p - b) * (p - c)));
}


void prog2_4a() {
	double x;
	printf("x=");
	scanf_s("%lf", &x);
	double y = pow((x * x + 1), 2);
	printf("f(x)=%g", y);
}


double Rosenbrock2d(double x, double y) {
	return 100 * (x * x - y) * (x * x - y) + (x - 1) * (x - 1);
}
void prog2_5() {
	double x1 = 5.1, y1 = -0.45245, x2 = 7294.65583, y2 = 5.328482, x3 = -48392.94487, y3 = -473.39473;
	printf("x1 = %g, y1 = %g, Rosenbrock2d(x1,y1)= %g\n", x1, y1, Rosenbrock2d(x1, y1));
	printf("x2 = %g, y2 = %g, Rosenbrock2d(x2,y2)= %g\n", x2, y2, Rosenbrock2d(x2, y2));
	printf("x3 = %g, y3 = %g, Rosenbrock2d(x3,y3)= %g", x3, y3, Rosenbrock2d(x3, y3));
}

double lenght(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
double square(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
void prog2_6()
{
	double x1, y1, x2, y2, x3, y3;
	printf("A1 A2: ");
	std::cin >> x1 >> y1;
	printf("\n");
	printf("B1 B2: ");
	std::cin >> x2 >> y2;
	printf("\n");
	printf("C1 C2: ");
	std::cin >> x3 >> y3;
	printf("S=%g", square(lenght(x1, y1, x2, y2), lenght(x2, y2, x3, y3), lenght(x1, y1, x3, y3)));
}


double func_a(double x, double y) {
	return pow(x + y, 3);
}
double func_b(double x, double y) {
	return pow(x * y, 2) + pow(x * y, 3) + pow(x * y, 4);
}

#define pi 3.141592
void prog2_9()
{
	double a, b, c, R, val, a1, b1, s;
	printf("a, b, c, R = ");
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	scanf("%lf", &R);
	if (a + b + c < 180)
		printf("sum of angles must be equal to 180");
	else
	{
		val = pi / 180;
		a1 = sin(a * val) * 2 * R;
		b1 = sin(b * val) * 2 * R;
		printf("a = %lf, b = %lf", a1, b1);
		s = 0.5 * a1 * b1 * sin(c * val);
		printf("\nArea of a triangle is %lf", s);
	}
}
/* task 2.17в

#include <stdio.h>
#include <cmath>

double softSign(double x) {
	double y;
	y = x / (1 + fabs(x));
	return y;
}

double softSign_der(double x) {
	double y;
	y = 1 / (1 + fabs(x) * (1 + fabs(x)));
	return y;
}

int main() {

	printf("this function in x0 is %g, derivative in this x0 is %g\n", softSign(-1), softSign_der(-1));
	printf("this function in x0 is %g, derivative in this x0 is %g\n", softSign(1), softSign_der(1));
	printf("this function in x0 is %g, derivative in this x0 is %g\n", softSign(0), softSign_der(0));
}
*/
int main() {
	//prog2_1();
	//prog2_2();
	//prog2_3();
	//prog2_4a();
	//prog2_5();
	//prog2_6();
	//prog2_9();
	//prog2_17в();
}