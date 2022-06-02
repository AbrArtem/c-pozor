#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void out(int mas[3][3], int N, int M) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mas[i][j] == M) {
                mas[i][j] = N;
            }
            printf("\ta[%d][%d]=%d", i, j, mas[i][j]);
        }
    }
}
void prog8_1() {
    int mas[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    int n, m;
    printf("N, M:");
    scanf_s("%d %d", &n, &m);
    out(mas, n, m);
}


#define N 3
#define M 3
bool change(double mas[N][M], int i, int j, double a) {

    if (i >= N || j >= M) return false;
    mas[i][j] = a;
    return true;
}
void output1(double mas[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("\ta[%d][%d]=%lf", i, j, mas[i][j]);
        }
    }
}
void prog8_2() {
    double mas[N][M] = { {1,2,3},{4,5,6},{7,8,9} };

    int i, j;
    double a;
    printf("i,j,a:");
    scanf_s("%d %d %lf", &i, &j, &a);

    if (change(mas, i, j, a))    output1(mas);
}


#define N1 20
#define M1 20
void prog8_3() {
    int n, m;
    printf("n= ");
    scanf_s("%d", &n);
    printf("m= ");
    scanf_s("%d", &m);
    double mas[N1][M1];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("a[%d][%d]= ", i, j);
            scanf_s("%lf", &mas[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("\n");
        for (int j = 1; j <= n; j++) {
            printf("%lf ", mas[i][j]);
        }
    }
}


#define N2 25
#define M2 25
void prog8_4() {
    int mas[N2][M2];
    int n, m;
    printf("n= ");
    scanf_s("%d", &n);
    printf("m= ");
    scanf_s("%d", &m);

    for (int i = 1; i <= n; i++) {
        printf("string %d:", i);
        for (int j = 1; j <= m; j++) {
            scanf_s(" %d", &mas[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("\n");
        for (int j = 1; j <= m; j++) {
            printf("%d ", mas[i][j]);
        }
    }
}


#define N3 2
int input_matr(int mas[N3][N3]) {
    for (size_t i = 0; i < N3; i++) {
        for (size_t j = 0; j < N3; j++) {
            printf("\na[%zu][%zu]= ", i, j);
            scanf_s("%d", &mas[i][j]);
        }
    }
    return 0;
}
void transp(int inp_matr[N3][N3], int out_matr[N3][N3]) {
    for (size_t i = 0; i < N3; i++) {
        for (size_t j = 0; j < N3; j++) {
            out_matr[i][j] = inp_matr[j][i];
        }
    }
}
void output(int mas[N3][N3]) {
    for (size_t i = 0; i < N3; i++) {
        printf("\n");
        for (size_t j = 0; j < N3; j++) {
            printf("\ta[%zu][%zu]=%d", i, j, mas[i][j]);
        }
    }
}
void prog8_5() {
    int mas[N3][N3];
    input_matr(mas);
    int mas2[N3][N3];
    transp(mas, mas2);
    output(mas2);
}


#define N4 3
#define M4 3
float sub_diag(double inp_matr[N4][M4], int k) {
    float res = 0.f;
    for (int i = 0; i < N4; i++) {
        if ((i - k >= 0) && (i - k <= M)) {
            res += inp_matr[i][i - k];
        }
    }
    return res;
}
void prog8_6() {
    double mas[N4][M4];
    for (int i = 0; i < N4; i++) {
        for (int j = 0; j < M4; j++) {
            printf("a[%d][%d]= ", i, j);
            scanf_s("%lf", &mas[i][j]);
        }
    }
    int k;
    printf("k = ");
    scanf_s("%d", &k);
    for (int i = 0; i < N4; i++) {
        printf("\n");
        for (int j = 0; j < M4; j++) {
            printf("%lf ", mas[i][j]);
        }
    }
    printf("\n sub=%f", sub_diag(mas, k));
}

void prog8_7() {
    double mas[N5][N5], det;
    for (int i = 1; i <= N5; i++) {
        for (int j = 1; j <= N5; j++) {
            printf("a[%d][%d]= ", i, j);
            scanf_s("%lf", &mas[i][j]);
        }
    }
    det = mas[1][1] * (mas[2][2] * mas[3][3] - mas[2][3] * mas[3][2]) - mas[1][2] * (mas[2][1] * mas[3][3] - mas[3][1] * mas[2][3]) + mas[1][3] * (mas[2][1] * mas[3][2] - mas[2][2] * mas[3][1]);
    printf("det = %lf", det);
}

#define N6 3
// prog8_19
#include <stdio.h>

#define N 10
#define M 10

int main() {
    int n, m, k = 1, min, max, count, numb;;
    int mat[N][M], elem[N][M];

    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);

    min = max = numb;
    while (--count > 0) {
        printf("%d:", count);
        scanf("%d", &numb);
        if (min > numb) min = numb;
        if (max < numb) max = numb;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("\n");
        for (int j = 1; j <= m; j++) {
        }
        if (m > k || n < k) {
            printf("elem[%d][%d] = %d \n", n, m, max);
            printf("elem[%d][%d] = %d ", n, m, min);
            break;
        }
    }
    return 0;
}

#include <iostream>

void enter_matrix(double** &matrix, const int &N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << "Enter coef in pos (row = " << i << ", col = " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }
}

void print_matrix(double** &matrix, const int &N) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double** cofactor(double **matrix, const int &N, const int &p, const int &q) {
    double **tmp = new double*[N];
    for(int i = 0; i < N; i++) tmp[i] = new double[N];

    int row = 0, col = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != p && j != q) {
                tmp[row][col] = matrix[i][j];
                col++;
                if (col == N-1) {
                    col = 0;
                    row++;
                }
            }
        }
    }

    return tmp;
}

double determinant(double **&matrix, const int &N) {
    int det = 0;

    if (N == 1)
        return matrix[0][0];

    double **tmp;
    int sign = 1;

    for (int i = 0; i < N; i++) {
        tmp = cofactor(matrix, N, 0, i);
        det += sign * matrix[0][i] * determinant(tmp, N - 1);
        sign = -sign;
    }

    return det;
}

double** adjacent_matrix(double** &matrix, const int &N) {
    double **adj_matrix = new double*[N];
    for(int i = 0; i < N; i++) {
        adj_matrix[i] = new double[N];
    }

    if (N == 1) {
        adj_matrix[0][0] = 1;
        return adj_matrix;
    }

    double **tmp = new double*[N];
    for(int i = 0; i < N; i++) {
        tmp[i] = new double[N];
    }

    int sign = 1;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            tmp = cofactor(matrix, N, i, j);

            sign = ( (i+j)%2==0 ) ? 1 : -1;
            adj_matrix[j][i] = sign * determinant(tmp, N-1);
        }
    }

    return adj_matrix;
}

double** inverse_matrix(double** &matrix, const int &N) {
    double **inv_matrix = new double*[N];
    for(int i = 0; i < N; i++) {
        inv_matrix[i] = new double[N];
        for(int j = 0; j < N; j++) {
            inv_matrix[i][j] = matrix[i][j];
        }
    }

    double det = determinant(inv_matrix, N);
    if(det == 0) {
        std::cout << "Can`t find inverse matrix" << std::endl;
        return nullptr;
    }

    double **adj_matrix = adjacent_matrix(matrix, N);

    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inv_matrix[i][j] = adj_matrix[i][j] / det;

    return inv_matrix;
}

void free_matrix(double** &matrix, const int &N) {
    for(int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int N;
    std::cout << "Matrix size: ";
    std::cin >> N;
    if(N >= 200) {
        std::cout << "Wrong input" << std::endl;
        return 0;
    }

    double **matr = new double*[N];
    for(int i = 0; i < N; i++) {
        matr[i] = new double[N];
    }
    enter_matrix(matr, N);

    matr = inverse_matrix(matr, N);

    std::cout << "Inverse matrix: " << std::endl;
    print_matrix(matr, N);

    free_matrix(matr, N);
    return 0;
}

// prog8_9
#include <iostream>

void enter_matrix(double**& matrix, const int& N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "Enter coef in pos (row = " << i << ", col = " << j << "): ";
            std::cin >> matrix[i][j];
        }
    }
}

void print_matrix(double**& matrix, const int& N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double** cofactor(double** matrix, const int& N, const int& p, const int& q) {
    double** tmp = new double* [N];
    for (int i = 0; i < N; i++) tmp[i] = new double[N];

    int row = 0, col = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != p && j != q) {
                tmp[row][col] = matrix[i][j];
                col++;
                if (col == N - 1) {
                    col = 0;
                    row++;
                }
            }
        }
    }

    return tmp;
}

double determinant(double**& matrix, const int& N) {
    int det = 0;

    if (N == 1)
        return matrix[0][0];

    double** tmp;
    int sign = 1;

    for (int i = 0; i < N; i++) {
        tmp = cofactor(matrix, N, 0, i);
        det += sign * matrix[0][i] * determinant(tmp, N - 1);
        sign = -sign;
    }

    return det;
}

double** adjacent_matrix(double**& matrix, const int& N) {
    double** adj_matrix = new double* [N];
    for (int i = 0; i < N; i++) {
        adj_matrix[i] = new double[N];
    }

    if (N == 1) {
        adj_matrix[0][0] = 1;
        return adj_matrix;
    }

    double** tmp = new double* [N];
    for (int i = 0; i < N; i++) {
        tmp[i] = new double[N];
    }

    int sign = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp = cofactor(matrix, N, i, j);

            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj_matrix[j][i] = sign * determinant(tmp, N - 1);
        }
    }

    return adj_matrix;
}

double** inverse_matrix(double**& matrix, const int& N) {
    double** inv_matrix = new double* [N];
    for (int i = 0; i < N; i++) {
        inv_matrix[i] = new double[N];
        for (int j = 0; j < N; j++) {
            inv_matrix[i][j] = matrix[i][j];
        }
    }

    double det = determinant(inv_matrix, N);
    if (det == 0) {
        std::cout << "Can`t find inverse matrix" << std::endl;
        return nullptr;
    }

    double** adj_matrix = adjacent_matrix(matrix, N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            inv_matrix[i][j] = adj_matrix[i][j] / det;

    return inv_matrix;
}

void free_matrix(double**& matrix, const int& N) {
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int N;
    std::cout << "Matrix size: ";
    std::cin >> N;
    if (N >= 200) {
        std::cout << "Wrong input" << std::endl;
        return 0;
    }

    double** matr = new double* [N];
    for (int i = 0; i < N; i++) {
        matr[i] = new double[N];
    }
    enter_matrix(matr, N);

    matr = inverse_matrix(matr, N);

    std::cout << "Inverse matrix: " << std::endl;
    print_matrix(matr, N);

    free_matrix(matr, N);
    return 0;
}
int main() {
    //prog8_1();
    //prog8_2();
    //prog8_3();
    //prog8_4();
    //prog8_5();
    //prog8_6();
    //prog8_7();
    //prog8_9();
    //prog8_19();
}
