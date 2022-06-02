// prog11_1

#include <stdio.h>
#include <stdlib.h>

int write_array_to_file(float* arr, int n, const char* fname) {
    FILE* fp = fopen(fname, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error in open file %s for writing", fname);
        return -1;
    }
    int res = fwrite(arr, sizeof(*arr), n, fp);
    fclose(fp);
    return res;
}

int read_array_from_file(const char* fname) {
    FILE* fp = fopen(fname, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error in open file %s for reading", fname);
        return -1;
    }
    printf("Reading file:");
    float x;
    int count = 0;
    while (!feof(fp)) {
        int r = fread(&x, sizeof(float), 1, fp);
        if (r != 1) break;
        count++;
        printf("%g", x);
    }
    fclose(fp);
    return count;
}
int main() {
    float* mas;
    printf("n=");
    int n;
    scanf("%d", &n);
    mas = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        printf("a[%d]=", i);
        scanf("%f", &mas[i]);
    }
    char fname[20];
    printf("file:");
    scanf("%s", fname);
    write_array_to_file(mas, n, fname);
    read_array_from_file(fname);

    free(mas);
}
// prog11_2
#include <stdio.h>
#include <math.h>

#define EPS 0.0000001

int write_reals_to_file(const char* fnameF) {

    FILE* fp = fopen(fnameF, "wb");
    if (fp == NULL) {
        printf("Error opening &s", fnameF);
        return -1;
    }

    double tmp;
    do {
        printf("x=");
        scanf("%lf", &tmp);
        if (fabs(tmp) < EPS) break;
        fwrite(&tmp, sizeof(tmp), 1, fp);
    } while (1);

    fclose(fp);
    return 0;
}

int write_limit_reals_to_file(const char* fnameF, const char* fnameG, double a) {

    FILE* Fp = fopen(fnameF, "rb");
    if (Fp == NULL) {
        printf("Error opening &s", fnameF);
        return -1;
    }

    FILE* Gp = fopen(fnameG, "wb");
    if (Gp == NULL) {
        printf("Error opening &s", fnameG);
        return -2;
    }

    FILE* Hp = fopen("tempfile.dat", "wb");

    double tmp;
    do {
        int res = fread(&tmp, sizeof(tmp), 1, Fp);
        if (res != 1) {
            break;
        }
        if (fabs(tmp) < a) {
            fwrite(&tmp, sizeof(tmp), 1, Gp);
        }
        else {
            fwrite(&tmp, sizeof(tmp), 1, Hp);
        }
    } while (!feof(Fp));

    fclose(Fp);
    fclose(Gp);
    fclose(Hp);

    rename("tempfile.dat", fnameF);

}
// prog11_3

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>

#pragma warning(disable : 4996)


int write_to_file(const char* fnameF) {
    FILE* fp = fopen(fnameF, "wb");
    if (fp == NULL) {
        printf("Error opening %s", fnameF);
        return -1;
    }
    int tmp = 0;
    int ch;
    while (true) {
        fwrite(&tmp, sizeof(tmp), 1, fp);
        tmp += 1;
        //printf("%d", tmp);
        if (kbhit()) {
            ch = getch();
            if (ch == '0')
                break;
        }
    }

    fclose(fp);
    return 0;
}

bool isprime(int num) {
    if (ceil((int)sqrt(num)) == floor((int)sqrt(num))) {
        int n = sqrt(num);
        for (int i = 2; i < int(sqrt(n) + 1); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}

int write_primes_to_file(const char* fnameF, const char* fnameG) {
    FILE* Fp = fopen(fnameF, "rb");
    if (Fp == NULL) {
        printf("Error opening %s", fnameF);
        return -1;
    }
    FILE* Gp = fopen(fnameG, "wb");
    if (Gp == NULL) {
        printf("Error opening %s", fnameG);
        return -2;
    }
    int tmp;
    do {
        int res = fread(&tmp, sizeof(tmp), 1, Fp);
        if (res != 1) {
            break;
        }
        if (isprime(tmp) == true) {
            fwrite(&tmp, sizeof(tmp), 1, Gp);
        }
    } while (!feof(Fp));
    fclose(Fp);
    fclose(Gp);
}

void read_file(const char* fname) {
    FILE* fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("file %s cannot be opened for reading", fname);
        return;
    }

    int x;
    do {
        int r = fread(&x, sizeof(x), 1, fp);
        if (r != 1) break;
        printf("%d", x);
    } while (1);

    fclose(fp);
}

int main(int argc, char** argv) {

    char fnameF[] = "task3f.dat";
    char fnameG[] = "task3g.dat";

    write_to_file(fnameF);
    write_primes_to_file(fnameF, fnameG);
    read_file(fnameG);
}
// prog11_4

#include <stdio.h>
#include <ctype.h>

typedef struct Rect {
    unsigned num;
    double Ax;
    double Ay;
    double Bx;
    double By;
};

int inputRect(Rect* x) {
    printf("n=");
    scanf(" %u", &x->num);
    printf("Ax,y");
    scanf(" %lf %lf", &x->Ax, &x->Ay);
    printf("Bx,y");
    scanf(" %lf %lf", &x->Bx, &x->By);
    return 0;
}

void outRect(const Rect* x) {
    printf("%u: (%lf,%lf)- (%lf,%lf)", &x->num, &x->Ax, &x->Ay, &x->Bx, &x->By);
}

int writeRects(const char* fname) {
    FILE* fp = fopen(fname, "wb");
    //check file pointer
    Rect r;
    int count = 0;
    do {
        char c;
        do {
            printf("Next rectangle?y/n");
            c = (char)getchar();
        } while (tolower(c) != 'y' || tolower(c) != 'n');
        if (c == 'n') {
            break;
        }
        if (inputRect(&r) == 0) {
            fwrite(&r, sizeof(r), 1, fp);
        }
    } while (1);

    fclose(fp);
    return count;
}

double area(const Rect* r) {
    return(r->Ax - r->Bx) * (r->Ay - r->By);
}

int findMaxRect(const char* fname) {

    FILE* fp = open(fname, "rb");
    Rect rect;
    double squareMax = 0;
    Rect rmax;
    while (!feof(fp)) {
        int r = fread(&rect, sizeof(rect), 1, fp);
        if (r != 1) break;
        if (area(&rect) > squareMax) {
            squareMax = area(&rect);
            rmax = rect;
        }
    }
    outRect(rmax);
    printf(": %g \n", area(&rmax));
    return rmax.num;

}
// prog class main
#include <stdio.h>

#include "task11_2.c"

int read_from_file(const char* fname) {
    FILE* fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("file %s cannot be open for reading", fname);
        return 0;
    }
    double x;

    do {
        int r = fread(&x, sizeof(x), 1, fp);
        if (r != 1) break;
        printf("%f", x);
    } while (1);

    fclose(fp);
}

int main(int argc, char** argv) {

    char fnameF[] = "task2f.dat";
    char fnameG[] = "task2g.dat";
    double a;
    printf("a=");
    scanf("%lf", &a);

    write_reals_to_file(fnameF); // create file of reals
    write_limit_reals_to_file(fnameF, fnameG, a); //fromF to G with limit a
    read_from_file(fnameG);
    read_from_file(fnameF);
    return 0;
}
// prog class main4
#include <stdio.h>

#include "11_4.c"

int read_from_file(const char* fname) {
    FILE* fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("file %s cannot be open for reading", fname);
        return 0;
    }
    double x;

    do {
        int r = fread(&x, sizeof(x), 1, fp);
        if (r != 1) break;
        printf("%f", x);
    } while (1);

    fclose(fp);
}

int main(int argc, char** argv) {

    /*char fnameF[]="task2f.dat";
    char fnameG[]="task2g.dat";
    double a;
    printf("a=");
    scanf("%lf",&a);
    write_reals_to_file(fnameF); // create file of reals
    write_limit_reals_to_file(fnameF, fnameG, a); //fromF to G with limit a
    read_from_file(fnameG);
    read_from_file(fnameF);*/

    writeRects("rect.dat");
    findMaxRect("rect.dat");
    return 0;
}
// prog11_6б
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable : 4996)

#define END 0
int square_root(int x) {
    for (int i = 1; i <= x / 2; i++) {
        if (i * i == x) {
            return i;
        }
    }
    return -1;
}

int create_file(const char* fnameF) {
    FILE* fp = fopen(fnameF, "wb");
    if (fp == NULL) {
        printf("Error opening %s", fnameF);
        return -1;
    }
    int tmp;
    do {
        printf("x=");
        scanf("%d", &tmp);
        if (tmp == END) break;
        fwrite(&tmp, sizeof(tmp), 1, fp);
    } while (1);
    fclose(fp);
    return 0;
}


int main() {
    const char* fname = "numbers.dat";
    int k = 0;
    create_file(fname);
    FILE* Fp = fopen(fname, "rb");
    if (Fp == NULL) {
        printf("Error opening %s", fname);
        return -1;
    }
    int tmp;
    int res = 1;
    do {
        int res = fread(&tmp, sizeof(tmp), 1, Fp);
        printf("Square root of %d=%d\n", tmp, square_root(tmp));
        if (square_root(tmp) % 2 == 1) {
            k++;
        }
        if (res != 1) {
            break;
        }
    } while (!feof(Fp));
    printf("Result is %d", k - 1);
    fclose(Fp);
}
// prog11_12б

#include <iostream>
#include <fstream>

using namespace std;

struct Toy {
    char toyName[25];
    double toyPrice;
    int minAge;
    int maxAge;
};

int main() {

    size_t toys_size = 4;
    Toy toys[] = {
            {"Tennis racket", 1250.75, 7, 99},
            {"Baseball bat", 550.55, 12, 99},
            {"Puppet", 1500.0, 5, 9},
            {"Constructor", 2020.220, 5, 15}
    };

    //Save toys

    FILE* f1 = fopen("toys.dat", "wb+");

    cout << "Writing data to file..." << endl;
    fwrite(&toys, sizeof(Toy) * toys_size, 1, f1);

    fclose(f1);

    FILE* f2 = fopen("toys.dat", "r");

    cout << "Reading data from file..." << endl;
    Toy toys_read[toys_size];

    fread(&toys_read, sizeof(Toy) * toys_size, 1, f2);

    fclose(f2);

    int n, m;
    cout << "Input n (for age n or m): ";
    scanf("%d", &n);
    cout << "Input m: ";
    scanf("%d", &m);

    if (n < 0 | m < 0) return 0;

    printf("\nToys, that match for both age %d and %d:\n", n, m);
    for (int i = 0; i < toys_size; i++) {
        Toy toy = toys_read[i];
        if (n<toy.minAge || m<toy.minAge ||
            n>toy.maxAge || m>toy.maxAge) {
            continue;
        }
        cout << "    " << toy.toyName << endl;
    }
    return 0;
}