// prog15_1

#include "Rational.h"

void Rational::show() {
    std::cout << nom << "/" << denom << "\n";
}

int Rational::input() {
    std::cout << "Input nom:";
    std::cin >> nom;
    std::cout << "Input denom:";
    std::cin >> denom;

    reduce();

    return 0;
}

Rational Rational::add(const Rational& x) {
    int t = (int)(this->nom * x.denom + denom * x.nom);
    unsigned y = x.denom * denom;
    return Rational(t, y);
}

Rational Rational::mult(const Rational& x) {
    int t = nom * x.nom;
    unsigned y = x.denom * denom;
    return Rational(t, y);
}

unsigned Rational::gcd(unsigned x, unsigned y) {
    if (y == 0 || x == 0) return x + y;
    if (x >= y) return gcd(x % y, y);
    return gcd(y % x, x);
}

void Rational::reduce() {

    int nsd;
    if (nom >= 0)
        nsd = (int)gcd(nom, denom);
    else
        nsd = (int)gcd(-nom, denom);

    nom /= nsd;
    denom /= nsd;
}


Rational Hregory(double eps) {
    Rational s;
    int sign = -1;
    for (int i = 2; eps * i * i < 1; i++) {
        Rational tmp;
        tmp.setNom(sign);
        sign = -sign;
        tmp.setDenom(i * i);
        s = s.add(tmp);
    }
    return s;
}


int main() {
    Rational r1, r2(2, 3);
    r1.input();

    Rational r3 = r1.add(r2);
    Rational r4 = r1.mult(r2);
    r3.show();
    r4.show();
    unsigned p = Rational::gcd(60, 35);
    std::cout << p;
    //r4.reduce();
/*
    Rational mas[5];
    for(int i=0;i<5;++i){
        mas[i].input();
    }
    Rational minRat;
    minRat = mas[0];
    for(int i=1;i<5;i++){
        //if(mas[i]<minRat){
        if(mas[i].less(minRat)){
            minRat = mas[i];
        }
    }
    minRat.show();	*/
    Rational q = Hregory(0.01);
    q.show();
    std::cout << q.compare(M_PI * M_PI / 12.0);
}
// prog15_
#ifndef __RATIONAL__
#define __RATIONAL__

#include <iostream>
#include <cmath>

class Rational {
private:
    int nom;
    unsigned denom;

public:
    Rational() {
        nom = 1;
        denom = 1U;
    }
    Rational(int x, unsigned y) :nom(x), denom(y) {
        reduce();
    }

    void show();
    int input();

    int setNom(int x) {
        nom = x;
        return 0;
    }
    int setDenom(unsigned y) {
        if (y != 0) {
            denom = y;
            return 0;
        }
        return -1;
    }

    Rational add(const Rational& x); //x.add(y);
    Rational mult(const Rational& x);

    bool less(const Rational& x) {
        return (nom * x.denom < denom* x.nom);
    }

    double compare(double z) {
        return fabs(z - (nom + 0.) / denom);
    }

    static unsigned gcd(unsigned x, unsigned y);



private:
    void reduce();
};


#endif // __RATIONAL__ header 
// prog15_2

#include <iostream>
#include <cmath>

using namespace std;

class Point {
    double x, y;

public:
    Point() {}
    Point(int x_, int y_) :x(x_), y(y_) {
        counter++;
    }
    static int counter;
    void input() {
        cout << "x,y";
        cin >> x >> y;
        counter++;
    }

    static int getCount() {
        return counter;
    }

    friend double dist(Point& p1, Point& p2);
};

double dist(Point& p1, Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int Point::counter = 0;

int main() {
    string answer;
    //int m=0;
    Point p_prev;
    Point p_first;
    double d1 = 0;
    do {
        cout << "Continue enter points?y/n";
        cin >> answer;
        if (answer.length() >= 1 && tolower(answer[0]) == 'y') {
            Point p;
            p.input();
            //m++;

            if (Point::getCount() > 1) {
                d1 += dist(p, p_prev);
            }
            else {
                p_first = p;
            }
            p_prev = p;
        }
        else {
            break;
        }
    } while (true);

    Point z;
    cout << Point::getCount() << z.counter;
    d1 += dist(p_first, p_prev);
    cout << "Perimeter " << d1;
}
// prog15_3
#include <cstring>       // memmove, memcpy
#include "Poly.h"

Poly::Poly() {
    n = 0; a = nullptr;
};

Poly::Poly(unsigned m) {
    n = m;
    a = new double[n];
}

Poly::Poly(unsigned n, double* ptr_a) {
    this->n = n;
    a = new double[n];
    memmove(a, ptr_a, sizeof(*a) * n);
}

Poly::~Poly() {
    delete[] a;
}

Poly::Poly(const Poly& p) {
    n = p.n;
    a = new double[n];
    memmove(a, p.a, n * sizeof(*a));
}


double Poly::value(double x) {
    if (n == 0) { std::cerr << "Empty Polynome"; return 0; };
    double res = a[0];
    for (unsigned i = 1; i < n; ++i) {
        res *= x;
        res += a[i];
    }
    return res;
}

void Poly::show() {
    std::clog << "P{";
    for (unsigned i = 0; i < n; ++i) {
        std::clog << a[i] << ", ";
    }
    std::clog << "}\n";
}
//
#ifndef POLY_H
#define POLY_H
#include <iostream>

/*
 * Class Polynome
 * */
class Poly {
    unsigned n; ///< size of Polynome
    double* a;  ///< array of Polynome coefficients
public:
    // default constructor: create empty polynome
    Poly();
    /* constructor: create polynome of given size
     * @params:
     * unsigned n - size of polynome
     **/
    Poly(unsigned n);
    /* constructor: create polynome with given array
     * P(x) = a_0 * x^n-1 + a_1*x^n-2 + ... + a_n-1
     * @params:
     * unsigned n - size of polynome
     * double* ptr_a - array of coefficients a_0, a_1,...,a_n
     **/
    Poly(unsigned n, double* ptr_a);
    // destructor: free memory
    ~Poly();
    /* copy-constructor: create another polynome from the given
     * @params:
     * Poly p - polynome
     */
    Poly(const Poly& p);
    /* Calculate the value of the polynome
     * @params:
     * double x - argument of polynome
     * */
    double value(double x);
    // display polynome
    void show();

};

#endif // POLY_H   
// prog15_14
#include "Header.h"

void Rational::output() {
    std::cout << nom << "/" << denom << "\n";
}

int Rational::input() {
    std::cout << "Input nom:";
    std::cin >> nom;
    std::cout << "Input denom:";
    std::cin >> denom;

    reduce();

    return 0;
}

Rational Rational::add(const Rational& x) {
    int t = (int)(this->nom * x.denom + denom * x.nom);
    unsigned y = x.denom * denom;
    return Rational(t, y);
}

Rational Rational::mult(const Rational& x) {
    int t = nom * x.nom;
    unsigned y = x.denom * denom;
    return Rational(t, y);
}

unsigned Rational::gcd(unsigned x, unsigned y) {
    if (y == 0 || x == 0) return x + y;
    if (x >= y) return gcd(x % y, y);
    return gcd(y % x, x);
}

void Rational::reduce() {

    int nsd;
    if (nom >= 0)
        nsd = (int)gcd(nom, denom);
    else
        nsd = (int)gcd(-nom, denom);

    nom /= nsd;
    denom /= nsd;
}


Rational Hregory(double eps) {
    Rational s;
    int sign = -1;
    for (int i = 2; eps * i * i < 1; i++) {
        Rational tmp;
        tmp.setNom(sign);
        sign = -sign;
        tmp.setDenom(i * i);
        s = s.add(tmp);
    }
    return s;
}


int main() {
    Rational r1, r2(2, 3);
    r1.input();

    Rational r3 = r1.add(r2);
    Rational r4 = r1.mult(r2);
    r3.output();
    r4.output();
    unsigned p = Rational::gcd(60, 35);
    std::cout << p;
    //r4.reduce();
/*
    Rational mas[5];
    for(int i=0;i<5;++i){
        mas[i].input();
    }
    Rational minRat;
    minRat = mas[0];
    for(int i=1;i<5;i++){
        //if(mas[i]<minRat){
        if(mas[i].less(minRat)){
            minRat = mas[i];
        }
    }
    minRat.show();	*/
    Rational q = Hregory(0.01);
    q.output();
    std::cout << q.compare(3.14 * 3.14 / 12.0);
}