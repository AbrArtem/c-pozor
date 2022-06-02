#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>


void prog7_1() {
    int mas[] = { 5,12,3,4,7 };
    int N = 5;
    double a;
    printf("a=");
    scanf_s("%lf", &a);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (mas[i] < a) count++;
    }

    printf("K=%d", count);
}


void prog7_2() {
    int mas[] = { 5,112,4,3 };
    for (int i = 3; i > -1; i--) {
        printf("%d\n", mas[i]);
    }
}


#define N 10
double func(double m[N]) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if (m[i] > M_E) {
            sum += m[i];
        }
    }
    return sum;
}
void prog7_3() {
    double mas[N];

    for (int i = 0; i < N; i++) {
        printf("mas[%d] = ", i);
        scanf_s("%lf", &mas[i]);
    }
    printf("result: %lf", func(mas));
}


#define N 5
int max(int m[N]) {
    int f = 0;
    for (int i = 0; i < N; i++) {
        printf("%d,", m[i]);
        if (m[i] > f) {
            f = m[i];
        }
    }
    printf("]");
    return f;
}
void prog7_4() {
    int mas[N];

    for (int i = 0; i < N; i++) {
        printf("mas[%d] = ", i);
        scanf_s("%d", &mas[i]);
    }
    printf("[");
    printf("\nmax: %d", max(mas));
}


#define N 50
int count(int m[N]) {
    int even = 0;
    int odd = 0;
    for (int i = 0; i < N; i++) {
        if (m[i] % 2 != 0) {
            odd++;
        }
        else even++;
        if (m[i] == 0) {
            even--;
            break;
        }
    }
    printf("odd: %d,even: %d\n", odd, even);
    return 1;
}
void prog7_5() {
    int mas[N];

    for (int i = 0; i < N; i++) {
        printf("mas[%d] = ", i);
        scanf_s("%d", &mas[i]);
        if (mas[i] == 0) {
            break;
        }
    }
    count(mas);
}


#define N 20
int input(double mas[], int size);
void output(const double mas[], int size);
int scal_sum(const double mas1[], const double mas2[], double mas3[], int size);
double scal_mult(const double mas1[], const double mas2[], int size);
double* diff_vect(const double mas1[], const double mas2[], int size);

void prog7_6() {

    double mas1[N];
    double mas2[N];
    double mas3[N];

    unsigned n;
    double dob;

    do {
        printf("N=");
        scanf_s("%u", &n);
    } while (n == 0 || n > 20);


    input(mas1, n);
    input(mas2, n);

    dob = scal_mult(mas1, mas2, n);

    scal_sum(mas1, mas2, mas3, n);

    printf("Dobutok =%lf", dob);

    output(mas3, n);
}
int input(double mas[], int size) {

    for (int i = 0; i < size; i++) {
        printf("mas[%d]=", i);
        scanf_s("%lf", &mas[i]);
    }

    return size;
}
void output(const double mas[], int size) {

    for (int i = 0; i < size; i++) {
        printf("\n mas[%d]= %lf", i, mas[i]);
    }
}
int scal_sum(const double mas1[], const double mas2[], double mas3[], int size) {

    for (int i = 0; i < size; i++) {
        mas3[i] = mas1[i] + mas2[i];
    }

    return 0;
}
double scal_mult(const double mas1[], const double mas2[], int size) {

    double res = 0;
    for (int i = 0; i < size; i++) {
        res += mas1[i] * mas2[i];
    }

    return res;
}
double* diff_vect(const double mas1[], const double mas2[], int size) {
    static double mas3[N];
    for (int i = 0; i < size; i++) {
        mas3[i] = mas1[i] - mas2[i];
    }

    return mas3;
}


void enter_arr(int n, double* arr) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf_s("%lf", &arr[i]);
    }
}
void print_arr(int n, const double* arr) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %lf", i, arr[i]);
    }
    printf("\n");
}
void sum_arr(int n, const double* arr1, const double* arr2, double* a) {

    for (int i = 0; i < n; i++) {
        a[i] = arr1[i] + arr2[i];
    }

}
double dob_arr(int n, const double arr1[], const double arr2[]) {
    double dob = 0;
    for (int i = 0; i < n; i++) {
        dob += arr1[i] * arr2[i];
    }
    return dob;
}
int prog7_6a() {

    double arr1[4];
    enter_arr(4, arr1);
    print_arr(4, arr1);
    double arr2[4];
    enter_arr(4, arr2);
    print_arr(4, arr2);
    double arr3[4];
    sum_arr(4, arr1, arr2, arr3);
    print_arr(4, arr3);
    printf("Dob:%lf \n", dob_arr(4, arr1, arr2));
}
/* prog7_7
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int input(int** a) {
    *a = (int*)malloc(0 * sizeof * *a);
    int n = 0;
    if (*a) {
        while (n < 20) {
            int m;
            cin >> m;
            if (m == 0)
                break;
            n++;
            *a = (int*)realloc(*a, n * sizeof * *a);
            if (*a == NULL)
                exit(1);
            (*a)[n - 1] = m;
        }
    }
    return n;
}

float harmonicMean(int arr[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + (float)1 / arr[i];
    return (float)n / sum;
}

float geometricMean(int arr[], int n)
{
    float product = 1;
    for (int i = 0; i < n; i++)
        product = product * arr[i];
    float gm = pow(product, (float)1 / n);
    return gm;
}

int main() {
    int* a;
    int n = input(&a);
    //print(a, n);
    cout << harmonicMean(a, n) << endl;
    cout << geometricMean(a, n) << endl;
    free(a);
    return 0;
}
*/

/* prog7_8a
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int Input(double masive[], double n){
    int i;
    for (i=0; i<n; i++){
        cout << "masive[" << i+1 << "] = ";
        cin >> masive[i];
    }
    return 0;
}

int Output(const double masive[], int size){
    int i;
    for (i=0; i<size; ++i){
        cout <<  masive[i];
    }
    return 0;
}


int main() {
    int n;
    double *masive;
    int i, count ;
    cout << "n = " ;
    cin >> n;
    Input(masive, n);
    int N=1000;

    vector <int>v(N);
    for (size_t i = 1; i < N; ++i){
        if(i == 1){
            v[i] = 0;
        }
        else{
            v[i] = i;
        }
    }
    for (size_t i = 2; i < N; ++i){
        if(v[i] != 0){
            for(size_t j = 2 * i; j < N; j+=i){
                v[j] = 0;
            }
        }
    }
    for (auto x : v){
        if (x != 0){
            cout << "x=" << x << endl;
            for (int i = 0; i <n; i++){
                if (pow(x, 2) == masive[i]){
                    count+=1;
                }
            }
        }
    }


    return 0;

}
*/

int main() {
    //prog7_1();
    //prog7_2();
    //prog7_3();
    //prog7_4();
    //prog7_5();
    //prog7_6();
    //prog7_6a();
}
