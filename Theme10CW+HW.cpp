// prog10_1a

#include <stdio.h>
#include <stdbool.h>

typedef struct Date {
    int day;
    int month;
    int year;
}Date;

void outputDate(Date d) {
    printf("%d.%d.%d\n", d.day, d.month, d.year);
}

bool inputDate(Date* d) {
    printf("input day,month,year");
    return scanf("%d.%d.%d", &d->day, &((*d).month), &d->year) == 3;
}

int main() {
    Date d = { 13,4,2022 };
    outputDate(d);
    Date d1;
    if (inputDate(&d1))
        outputDate(d1);
}
// prog10_1á

#include <stdio.h>
#include <stdbool.h>

typedef struct ChessField {
    char vert;
    unsigned char hor;
}ChessField;

void outputCF(ChessField d) {
    printf("%c%hhu:\n", d.vert, d.hor);
}

bool inputCF(ChessField* d) {
    printf("input Chess Field");
    scanf("%c", &d->vert);
    scanf("%hhu", &d->hor);
    if (d->vert >= 'a' && d->vert <= 'h' && d->hor >= '1' && d->hor <= '8') {
        return true;
    }
    d->vert = 0;
    d->hor = 0;
    return false;
}

int main() {

    ChessField cf;

    if (inputCF(&cf))
        outputCF(cf);
}
// prog10_1c

#include <stdio.h>

typedef struct Point {
    double x, y;
} Point;

typedef struct Rectangle {
    Point A;
    Point B;
} Rectangle;

int inputRect(Rectangle* r) {
    printf("A(x,y):");
    int d = scanf("%lf %lf", &r->A.x, &r->A.y);
    if (d < 2) return 4 - d;
    printf("B(x,y):");
    d += scanf("%lf %lf", &r->B.x, &r->B.y);
    return 4 - d;
}

void printRect(const Rectangle* r) {
    printf("(%lf %lf)", r->A.x, r->A.y);
    printf("-(%lf %lf)", r->B.x, r->B.y);
}

int main() {
    Rectangle x;
    inputRect(&x);
    printRect(&x);
}
// prog10_1ä
// task 10.1d

#include <stdio.h>
#include <stdlib.h>

typedef struct Polynome10 {
    unsigned n;
    double a[10];
} Polynome10;

typedef struct Polynome {
    unsigned n;
    double* a;
} Polynome;

int inputPolynome(Polynome* p) {
    printf("n=");
    scanf("%u", &p->n);
    p->a = (double*)malloc((p->n + 1) * sizeof(*(p->a)));
    if (!(p->a)) {
        printf("cannot allocate memory for polynome");
        return -1;
    }
    for (unsigned i = 0; i <= p->n; ++i) {
        printf("a[%u]=", i);
        scanf("%lf", &(p->a[i]));
    }
    return 0;
}

void printPolynome(const Polynome* p) {
    printf("P=");
    for (unsigned i = p->n; i > 0; i--) {
        printf("%g * x^%u + ", p->a[i], i);
    }
    printf("%g\n", p->a[0]);
}

void deletePolynome(Polynome* p) {
    free(p->a);
}

int main() {
    Polynome10 p1;
    p1.n = 3;
    p1.a[0] = 1;

    Polynome p2;
    inputPolynome(&p2);
    printPolynome(&p2);

    deletePolynome(&p2);
}
// prog10_2

#include <stdio.h>
#include <stdbool.h>

struct ChessField {
    char h;
    unsigned char v;
};

bool inputChessField(struct ChessField* cf) {
    printf("\nH:");
    scanf(" %c", &(cf->h));
    printf("V:");
    scanf(" %hhu", &(cf->v));

    if (cf->v > 8 || cf->v == 0) return false;
    if (cf->h < 'a' || cf->h>'h') return false;
    return true;
}

void outputChessField(struct ChessField cf) {
    printf("%c%hhu:", cf.h, cf.v);
}

int main() {
    struct ChessField w1, w2;
    if (inputChessField(&w1)) {
        outputChessField(w1);
    }
    if (inputChessField(&w2)) {
        outputChessField(w2);
    }
}
// prog 10_3

#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int checkDate(const Date* x) {
    int mas[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (x->year < 1900 || x->year>2200) return -1;
    if (x->month < 1 || x->month>12) return -2;
    if (x->day <= 0 || x->day > mas[x->month - 1]) return -3;
    return 0;
}

int input(Date* x) {
    scanf("%d", &x->day);
    scanf("%d", &x->month);
    scanf("%d", &x->year);
    return 0;
}

void vyvod(const Date x) {
    printf("\nDate = %2d.%2d.%4d", x.day, x.month, x.year);
}

int leapYear(int year) {
    return(year % 4 == 0) && (year % 200 != 0);
}

Date yesterday(const Date x) {
    int dayMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    Date res = x;
    if (x.day > 1) {
        res.day--;
        return res;
    }

    if (x.month > 1) {
        res.month--;
        res.day = dayMonth[res.month - 1];
        if (leapYear(x.year) && res.month == 2) res.day = 29;
        return res;
    }

    if (x.month == 1) {
        res.year--;
        res.month = 12;
        res.day = 31;
        return res;
    }
    fprintf(stderr, "Chet ne to");
    return res;
}

Date tomorrow(const Date* x) {
    int dayMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    Date res = *x;
    if (res.day < dayMonth[x->month] + leapYear(x->year)) {
        res.day++;
        return res;
    }

    if (x->month < 12) {
        res.month++;
        res.day = 1;
    }

    if (x->month == 12) {
        res.year++;
        res.month = 1;
        res.day = 1;
        return res;
    }

    fprintf(stderr, "Chet ne to");
    return res;
}

int main() {
    Date dat1;
    int r = -1;
    do {
        printf("Input date: ");
        input(&dat1);
        if (checkDate(&dat1) == 0) break;
    } while (1);

    vyvod(dat1);
    vyvod(yesterday(dat1));

    printf("\n");
    Date d1 = { 23,2,2020 };
    Date d2 = { 1,1,2021 };
    Date d3 = { 31,12,2020 };
    Date d4 = { 28,2,2020 };
    Date d5 = { 28,2,2019 };

    vyvod(yesterday(d1));
    vyvod(yesterday(d2));
    vyvod(yesterday(d3));
    vyvod(yesterday(d4));
    vyvod(yesterday(d5));
    printf("\n------------");
    vyvod(tomorrow(&d1));
    vyvod(tomorrow(&d2));
    vyvod(tomorrow(&d3));
    vyvod(tomorrow(&d4));
    vyvod(tomorrow(&d5));
}
// prog10_5

#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define LEN_NAME 255
#define MAX_MAS 100

typedef struct {
    char name[LEN_NAME];
    int height;
} Mount;

bool inputMount(Mount* x) {
    printf("Mount name:");
    scanf(" %s", x->name);
    printf("Mount height:");
    scanf(" %d", &x->height);
    return true;
}

void outputMount(const Mount* x) {
    printf("Mount %s of height %d", x->name, x->height);
}

const char* maxHeightName(const Mount* arr, size_t n) {

    if (n == 0) return "No mountains";

    int maxh = arr[0].height;
    int indexMax = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].height > maxh) {
            maxh = arr[i].height;
            indexMax = i;
        }
    }
    return arr[indexMax].name;
}

void heightbyName(const Mount* arr, size_t n, const char* mount_name) {
    printf("%s", mount_name);
    bool isFound = false;
    for (int i = 0; i < n; i++) {

        if (strcmp(arr[i].name, mount_name) == 0) {
            printf("Mount %s has height %d", mount_name, arr[i].height);
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        printf("There is no mountains %s!\n", mount_name);
    }
}

int main() {
    /*Mount m;
    inputMount(&m);
    outputMount(&m);*/

    Mount test[MAX_MAS] = { {"K2",8676},{"Everest", 8878},{"Hill",1234} };

    printf("%s", maxHeightName(test, 3));

    heightbyName(test, 3, "Coverla");
    heightbyName(test, 3, "K2");
    heightbyName(test, 3, "Hill");

    Mount mnt[MAX_MAS];
    size_t n;
    printf("Input n=");
    scanf(" %zu", &n);
    for (size_t i = 0; i < n; i++) {
        inputMount(&mnt[i]);
    }
    printf("%s\n", maxHeightName(mnt, n));

    printf("name:");
    char mname[LEN_NAME];
    fgets(mname, LEN_NAME, stdin);
    heightbyName(mnt, n, mname);
}
// prog10_6
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 100
#define MAX_NAME 30


typedef struct Mount
{
    char name[MAX_NAME];
    int height;
}Mount;


void output_M(const Mount* x)
{
    printf("%s: %d", (char*)(x->name), x->height);
}


int input_M(Mount* x)
{
    printf("Name: ");
    scanf(" ");
    fgets(x->name, MAX_NAME, stdin);
    printf("Height: ");
    scanf("%d", &x->height);
    return 0;
}


void print_H(const Mount* arr, int n, const char* mname)
{
    bool isFound = false;

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, mname) == 0) {
            printf("Height of %s is %d", mname, arr[i].height);
            isFound = true;
            break;
        }
    }

    if (!isFound) {
        printf("No mountain with name %s", mname);
    }
}


int max_M(const Mount* arr, int n, char* maxMnt)
{

    if (n <= 0) return -1;
    int maxHeight = arr[0].height;
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].height > maxHeight) {
            maxHeight = arr[i].height;
            index = i;
        }
    }
    strcpy(maxMnt, arr[index].name);
    return index;
}



int main() {
    Mount mnts[MAX_ARRAY] = { {"Everest", 8848}, {"Elbrus", 5642}, {"Hoverla", 2700} };
    char mnt[MAX_NAME];
    max_M(mnts, 3, mnt);
    puts(mnt);
}
// prog10_11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 80


typedef struct {
    char surname[N], city[N], street[N];
    int house, apartment;
} Inhabitant;


void print(Inhabitant a) {
    printf("Surname: %s, City: %s, Address: %s, %i, %i\n", a.surname, a.city, a.street, a.house, a.apartment);
}

void print_array(Inhabitant arr[], int n) {
    for (int i = 0; i < n; i++)
        print(arr[i]);
}


int same_address(Inhabitant arr[], int n, char* one, char* two) {
    int m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(arr[i].city, arr[j].city)) {
                if ((!strcmp(arr[i].street, arr[j].street)) && (arr[i].house == arr[j].house) &&
                    (arr[i].apartment == arr[j].apartment)) {
                    m1 = i;
                    m2 = j;
                    strcpy(one, arr[m1].surname);
                    strcpy(two, arr[m2].surname);
                    return 1;
                }
            }
        }
    }
    return 0;
}


int main() {
    int n = 3;
    Inhabitant p[N] = {
            {"Ivanov",  "Kyiv",  "Chystyakivska", 4,  87},
            {"Petrov",  "Odesa", "Syretska",      10, 101},
            {"Sidorov", "Lviv",  "Chystyakivska", 4,  87},
    };
    print_array(p, n);

    char one[N];
    char two[N];
    if (same_address(p, n, one, two))
        printf("\nSame address: %s and %s\n", one, two);
    else
        printf("No inhabitants with the same address ");
    return 0;
}