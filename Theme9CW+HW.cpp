// prog9_1
#include <stdio.h>
#include <stdlib.h>

float sum_sqr(float* arr, int n) {
    float s = 0.f;
    for (int i = 0; i < n; i++) {
        s += arr[i] * arr[i];
    }
    return s;
}

int main() {
    int n;
    scanf_s("%d", &n);
    float* mas = (float*)malloc(n * sizeof(float)); // dynamic array   
    if (!mas) {
        printf("error in alloc memory");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf_s("%f", &mas[i]);
    }

    printf(" s= %f", sum_sqr(mas, n));

    free(mas);
}

//prog9_2
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int input(int* n) {
	int i = 0;
	do {
		printf("a[%d]", i);
		scanf_s("%d", &n[i]);
	} while (n[i++] != 0);

	return i - 2;
}

int main() {
	int* memory = (int*)malloc(100 * sizeof(*memory));
	int n = input(memory);
	int cnt = 0, cnnt = 0;

	for (int i = 0; i < n; i++) {
		double tmp = sqrt(memory[i]);
		if (tmp * tmp == memory[i]) cnt++;
	}

	for (int i = 0; i < n; i++) {
		double tmp = cbrt(memory[i]);
		if (tmp * tmp * tmp == memory[i]) cnnt++;
	}

	printf("number of squeres = %d", cnt);
	printf("number of cubes = %d", cnnt);
	free(memory);
}

// prog9_3
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

double* input_vector(int n) {
	double* a = (double*)calloc(n, sizeof(*a));
	for (int i = 0; i < n; i++) {
		printf("a[%d]", i);
		scanf_s("%lf", &a[i]);
	}
	return a;
}

double* sub_vect(const double* v1, const double* v2, const unsigned n) {
	double* res = (double*)calloc(n, sizeof(double));
	for (int i = 0; i < n; i++) {
		res[i] = v1[i] - v2[i];
	}
	return res;
}

int sub_v2(const double* v1, const double* v2, double* v4, int n) {
	for (int i = 0; i < n; i++) {
		v4[i] = v1[i] - v2[i];
	}
	return 0;
}

void free_vect(double* v1) {
	free(v1);
}

void vect_out(double* v, int n) {
	printf("(%g", v[0]);
	for (int i = 0; i < n; i++) {
		printf(", %g", v[i]);
	}
	printf(")\n");
}

int main() {
	int n;
	printf("n=");
	scanf_s("%d", &n);

	double* v1 = input_vector(n);
	double* v2 = input_vector(n);

	double* v3 = sub_vect(v1, v2, n);
	vect_out(v3, n);

	double v4[5];
	sub_v2(v1, v2, v4, n);
	vect_out(v4, n);

	free_vect(v1);
	free_vect(v2);
}

// prog9_4
#include <stdio.h>
#include <stdlib.h>
#include <cmath>


//a
double** input_mat(int n) {
	double** a = (double**)calloc(n, sizeof(*a));
	for (int i = 0; i < n; i++) {
		a[i] = (double*)calloc(n, sizeof(*a[i]));
		for (int j = 0; j < n; j++) {
			printf("a[%d][%d]", i, j);
			scanf_s("%lf", &a[i][j]);
		}
	}
	return a;
}


void free_matr(double** v1, int n) {
	for (int i = 0; i < n; i++) {
		free(v1[i]);
	}
	free(v1);
}

double** mult_matr(double** v1, double** v2, unsigned dim) {
	double** res = (double**)calloc(dim, sizeof(double*));
	for (unsigned i = 0; i < dim; i++) {
		res[i] = (double*)calloc(dim, sizeof(res[i]));
		for (unsigned j = 0; j < dim; j++) {
			for (unsigned k = 0; k < dim; k++) {
				res[i][j] += v1[i][k] * v2[i][k];
			}
		}
	}
	return res;
}


void mat_out(double** v, unsigned n) {
	unsigned i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%g  ", v[i][j]);
		}
		printf("\n");
	}
}

//b
double* input_mat1(int n) {
	double* a = (double*)calloc(n * n, sizeof(a));
	for (int i = 0; i < n * n; i++) {
		printf("a[%d]", i);
		scanf_s("%lf", &a[i]);
	}
	return a;
}

void mat_out1(double* v, unsigned n) {
	unsigned i;
	for (i = 0; i < n * n; i++) {
		printf("%g  ", v[i]);
		if ((i + 1) % n == 0 && i != 0) printf("\n");
	}
}

void free_matr1(double* v1) {
	free(v1);
}

double* mult_matr1(double* v1, double* v2, unsigned n, unsigned j) {
	double* res = (double*)calloc(n * n, sizeof(double));
	unsigned j = 0, k = 0, i = 0;
	for (unsigned i = 0; i < n * n; i++) {

		if ((i + 1) % n != 0) {

			for (unsigned t = 0; t < n; t++) {
				res[i] += v1[j] * v2[k];
				j += 1;
				k += n;
			}
			k = j;
			j -= i;
		}
		else {
		}

	}

	return res;
}
// prog9_5
#include <iostream>
#include <cmath>

double** input_matrix(int n, int m) {
	double** res = new double* [m];
	for (int i = 0; i < m; i++) {
		res[i] = new double[n];
		for (int j = 0; j < n; j++) {
			std::cout << "Enter coef (" << i << "," << j << "): ";
			std::cin >> res[i][j];
		}
	}

	return res;
}

void output_matrix(double** matrix, int n, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

double** copy(double** matrix, int n, int m) {
	double** res = new double* [m];
	for (int i = 0; i < m; i++) {
		res[i] = new double[n];
		for (int j = 0; j < n; j++) {
			res[i][j] = matrix[i][j];
		}
	}

	return res;
}

double rank(double** matrix, int n, int m) {
	double** tmp = copy(matrix, n, m);

	bool vectors[m];

	double* swap;
	for (int i = 0; i < m; i++) {
		if (tmp[i][i] != 0) continue;

		for (int j = 0; j < m; j++) {
			if (tmp[j][i] != 0 && !vectors[j]) {
				vectors[j] = true;
				swap = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = swap;
			}
		}
	}

	double coef = 0;
	for (int i = 0; i < std::min(n, m); i++) {
		if (tmp[i][i] == 0) continue;
		for (int j = i + 1; j < m; j++) {
			coef = tmp[j][i] / tmp[i][i];
			for (int k = 0; k < n; k++) {
				tmp[j][k] -= coef * tmp[i][k];
				if (fabs(tmp[j][k]) < 1e-5) {
					tmp[j][k] = 0;
				}
			}
		}
	}
	//    std::cout << std::endl;
	//    output_matrix(tmp, n, m);

	for (int i = std::min(n, m) - 1; i >= 0; i--) {
		if (tmp[i][i] == 0) continue;
		for (int j = i - 1; j >= 0; j--) {
			coef = tmp[j][j + 1] / tmp[i][i];
			for (int k = 0; k < n; k++) {
				tmp[j][k] -= coef * tmp[i][k];
				if (fabs(tmp[j][k]) < 1e-5) {
					tmp[j][k] = 0;
				}
			}
		}
	}

	//    std::cout << std::endl;
	//    output_matrix(tmp, n, m);

	int rank = 0;
	bool is_non_zero_vector;
	for (int i = 0; i < m; i++) {
		is_non_zero_vector = false;
		for (int j = 0; j < n; j++) {
			if (tmp[i][j] != 0) {
				is_non_zero_vector = true;
				break;
			}
		}
		if (is_non_zero_vector) rank++;
	}

	free(tmp);

	return std::min(n, rank);
}

void free(double** matrix, double n, double m) {
	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
}

int main() {
	int n = 3, m = 4;

	double** res = input_matrix(n, m);

	output_matrix(res, n, m);

	std::cout << rank(res, n, m) << std::endl;

	free(res, n, m);
	return 0;
}
// prog9_9á
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double randDouble() {
	return fmod((double)rand() / (double)rand(), 13.0); // srand(time(NULL))  isn't working
}


void printArray2(double* array, unsigned n) {
	printf("\n");
	for (unsigned i = 0; i < n; i++) {
		printf("%lf ", array[i]);
	}
}


void printArray3(double** array, unsigned n, unsigned m) {
	printf("\n");
	for (unsigned i = 0; i < n; i++) {
		printArray2(array[i], m);
	}
}


void fillArray(double* array, unsigned n) {
	for (unsigned i = 0; i < n; i++) {
		array[i] = randDouble();
	}
}


void fillArray3(double** array, unsigned n, unsigned m) {
	for (int i = 0; i < n; i++) {
		array[i] = malloc(sizeof(double) * m);
		fillArray(array[i], m);
	}
}


void freeArray(double** array, unsigned n) {
	if (!array) return;
	for (unsigned i = 0; i < n; i++) free(array[i]);
	free(array);
}


int findMaxElLineArray3(double** array, unsigned n, unsigned m) {
	double max_el = array[0][0];
	int line = 0;
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < m; j++) {
			if (array[i][j] > max_el) {
				max_el = array[i][j];
				line = i;
			}
		}
	}
	return line;
}


void newLineAfterMaxElArray(double** array, unsigned n, unsigned m) {
	int max_line = findMaxElLineArray3(array, n, m);
	printf("\nMAX_EL_LINE = %d", max_line);
	max_line++;
	double** swap_array = (double**)malloc(sizeof(double*) * n);
	fillArray3(swap_array, n, m);
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < m; j++) {
			swap_array[i][j] = array[i][j];
		}
	}
	freeArray(array, n);
	array = (double**)malloc(sizeof(double*) * (n + 1));
	fillArray3(array, n + 1, m);
	unsigned i1 = 0, j1 = 0;
	for (unsigned i = 0; i <= n; i++) {
		if (i != max_line) {
			for (unsigned j = 0; j < m; j++) {
				array[i][j] = swap_array[i1][j1++];
			}
			i1++;
			j1 = 0;
		}
		else {
			for (unsigned j = 0; j < m; j++) {
				array[i][j] = randDouble();
			}
		}
	}
}


void newColArray(double** array, unsigned n, unsigned m, unsigned k) {
	for (unsigned i = 0; i < n; i++) {
		double* swap_array = (double*)malloc(sizeof(double) * m);
		for (unsigned j = 0; j < m; j++) {
			swap_array[j] = array[i][j];
		}
		free(array[i]);
		array[i] = malloc(sizeof(double) * (m + 1));
		unsigned f = 0;
		for (unsigned j = 0; j <= m; j++) {
			if (j != k) array[i][j] = swap_array[f++];
			else array[i][j] = randDouble();
		}
		free(swap_array);
	}
}


int main() {
	unsigned N, M;
	printf("N = ");
	scanf("%d", &N);
	printf("M = ");
	scanf("%d", &M);

	double** array = (double**)malloc(sizeof(double*) * N);
	fillArray3(array, N, M);
	printArray3(array, N, M);

	unsigned k;
	printf("\nk = ");
	scanf("%d", &k);
	newColArray(array, N, M, k);
	M++;
	printArray3(array, N, M);

	printf("\n\n\nNext part");
	//array[0][0] = 777777;
	printArray3(array, N, M);
	newLineAfterMaxElArray(array, N, M);
	N++;
	printArray3(array, N, M);

	freeArray(array, N);
}

int main() {
	/*a
	int n;
	printf("n=");
	scanf_s("%d", &n);
	double** v1 = input_mat(n);
	double** v2 = input_mat(n);
	double** v3 = mult_matr(v1, v2, n);
	mat_out(v3, n);
	free_matr(v1, n);
	free_matr(v2, n);
	free_matr(v3, n);*/

	/*b
	int m;
	printf("n=");
	scanf_s("%d", &m);
	double* v4 = input_mat1(m);
	double* v5 = input_mat1(m);
	double* v6 = mult_matr1(v4, v5, m);
	mat_out1(v6, m);
	free_matr1(v4);
	free_matr1(v5);
	free_matr1(v6);
	*/
}
