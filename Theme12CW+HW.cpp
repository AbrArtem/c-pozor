// prog12_1
#include <iostream>
#include <cmath>

/*using std::cout;
using std::cin;
using std::endl;
*/

int main1() {
	double x, y;
	std::cin >> x;
	std::cin >> y;
	std::cout << std::fixed << "x^y=" << pow(x, y) << std::endl;
	std::cout << std::scientific << "x^y=" << pow(x, y);
	return 0;

}
// prog12_2
#include <iostream>
#include <cstring>

using namespace std;

const int N = 10;

int main2() {
	char str[N];
	unsigned long long sums = 0L;
	unsigned long long x;
	size_t err;
	char* err2;
	while (cin.get(str, 10)) {
		//int x= atoi(str)
		//c++11:strtoull
		x = strtoull(str, &err2, N);
		sums += x;
	}
	cout << "sum" << sums << "\n";
	return 0;
}
// prog12_3
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
//to_do
using namespace std;

int main3() {
	int n;
	float i;
	cin >> n;
	cout << fixed;
	cout << setprecision(2);
	i = 1.0;

	while (i <= n) {
		cout << i << "`s square root is " << pow(i, 0.5) << endl;
		i++;
	}
	return 0;
}
// prog12_4
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	unsigned n;
	cout << "n=";
	cin >> n;
	int* m = new int[n];//dynamic array of size n

	for (unsigned i = 0; i < n; i++) {
		cin >> m[i];
	}
	double* x = new double[n];
	const char fname[] = "ddata.txt";
	fstream f;
	f.open(fname, fstream::out);
	if (f.bad()) {
		cerr << "error opening file" << fname << "\n";
		delete[] x;
		delete[] m;
		return 0;
	}

	unsigned k = 0;
	double a;
	while (f >> a && k < n) {
		x[k++] = a;
	}

	if (k != n) {
		cerr << "read only" << k << "numbers but needed" << n << "!\n";
		return 0;
	}
	else {
		const char gname[] = "ddate2.txt";
		fstream g;
		g.open(fname, fstream::in);
		if (!f) {
			cerr << "error opening file" << gname << "\n";
			delete[] x;
			delete[] m;
			return 0;
		}
		for (unsigned i = 0; i < n; i++) {
			g << pow(x[i], m[i]) << " ";
		}
		g.close();
	}

	f.close();

}
// prog12_5
#include <iostream>
#include <fstream>
#include <cmath>

using ULL = unsigned long long;

int main() {

	ULL mas[2000];
	int k = 0;

	const char fname[] = "data3.txt";
	std::fstream f(fname);

	while (f >> mas[k++]) {
		;
	}
	f.close();

	std::cout.precision(4);
	for (int i = k - 2; i >= 0; i--) {
		std::cout << sqrt(mas[i]) << std::endl;
	}
}
// prog12_12
#include <iostream>
using namespace std;


int main() {
	long double a, b, c;
	cout << "A=xxx.xxx\nA=";
	cin >> a;
	cout << "B=xxExxx\nB=";
	cin >> b;
	cout << "C=xxx.xxxx\nC=";
	cin >> c;
	long double aver_harm = 3 / (1 / a + 1 / b + 1 / c);
	cout << "Average harmonic: " << aver_harm;
}