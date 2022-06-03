// prog16_5
#include<iostream>
#include<fstream>
#include<sstream>
#define N 20
using namespace std;

class Word {

private:
    string root;
    string suffix;
    string ending;

public:

    Word() :Word("", "", "") {}

    Word(string _root, string _suffix, string _ending) :
        root(_root), suffix(_suffix), ending(_ending) {}

    //string get_prefix(){return prefix;}
    string get_root() { return root; }
    string get_suffix() { return suffix; }
    string get_ending() { return ending; }

    virtual void print(ostream& out = cout) {
        out << root << suffix << ending << ends;
    }

    Word change_ending(string new_ending) {
        Word w(root, suffix, new_ending);
        return w;
    }

    Word change_suffix(string new_suffix) {
        Word w(root, new_suffix, ending);
        return w;
    }

    Word change_genus(string new_suffix, string new_ending) {
        Word w(get_root(), get_suffix(), get_ending());
        Word w1 = w.change_suffix(new_suffix);
        Word w2 = w1.change_ending(new_ending);
        return w2;
    }
    virtual Word change_genus_to_m(string new_suffix = "", string new_ending = "") {
        return change_genus(new_suffix, new_ending);
    }
    virtual Word change_genus_to_w(string new_suffix = "", string new_ending = "") {
        return change_genus(new_suffix, new_ending);
    }
    virtual Word change_genus_to_n(string new_suffix = "", string new_ending = "") {
        return change_genus(new_suffix, new_ending);
    }
    virtual Word change_genus_to_plular(string new_suffix = "", string new_ending = "") {
        return change_genus(new_suffix, new_ending);
    }


    virtual Word vidminok_r(string new_ending = "") {
        return change_ending(new_ending);
    }
    virtual Word vidminok_d(string new_ending = "") {
        return change_ending(new_ending);
    }
    virtual Word vidminok_th(string new_ending = "") {
        return change_ending(new_ending);
    }
    virtual Word vidminok_o(string new_ending = "") {
        return change_ending(new_ending);
    }
    virtual Word vidminok_m(string new_ending = "") {
        return change_ending(new_ending);
    }

};

class Verb :public Word {

public:

    Verb(string _root, string _suffix, string _ending) :
        Word(_root, _suffix, _ending) {}

    virtual Word change_genus_to_m(string new_suffix = "â", string new_ending = "") {
        return Word::change_genus_to_m("â", "");
    }
    virtual Word change_genus_to_w(string new_suffix = "ë", string new_ending = "à") {
        return Word::change_genus_to_w("ë", "à");
    }
    virtual Word change_genus_to_n(string new_suffix = "ë", string new_ending = "î") {
        return Word::change_genus_to_n("ë", "î");
    }
    virtual Word change_genus_to_plular(string new_suffix = "ë", string new_ending = "è") {
        return Word::change_genus_to_plular("ë", "è");
    }
};

class Adjective : public Word {

public:

    Adjective(string _root, string _suffix, string _ending) :
        Word(_root, _suffix, _ending) {}

    virtual Word change_genus_to_m(string new_suffix = "", string new_ending = "èé") {
        return Word::change_genus_to_m("", "èé");
    }
    virtual Word change_genus_to_w(string new_suffix = "", string new_ending = "à") {
        return Word::change_genus_to_w("", "à");
    }
    virtual Word change_genus_to_n(string new_suffix = "", string new_ending = "å") {
        return Word::change_genus_to_n("", "å");
    }
    virtual Word change_genus_to_plular(string new_suffix = "", string new_ending = "³") {
        return Word::change_genus_to_plular("", "i");
    }

    virtual Word vidminok_r(string new_ending = "îãî") {
        return Word::vidminok_r("îãî");
    }
    virtual Word vidminok_d(string new_ending = "îìó") {
        return Word::vidminok_r("îìó");
    }
    virtual Word vidminok_th(string new_ending = "îãî") {
        return Word::vidminok_th("îãî");
    }
    virtual Word vidminok_o(string new_ending = "èì") {
        return Word::vidminok_r("èì");
    }
    virtual Word vidminok_m(string new_ending = "îìó") {
        return Word::vidminok_m("îìó");
    }
};

class Noun : public Word { //â³äì³íþâàííÿ

public:

    Noun(string _root, string _suffix, string _ending) :
        Word(_root, _suffix, _ending) {}

    virtual Word change_genus_to_plular(string new_suffix = "", string new_ending = "è") {
        return Word::change_genus_to_plular("", "è");
    }

    virtual Word vidminok_r(string new_ending = "è") {
        return Word::vidminok_r("è");
    }
    virtual Word vidminok_d(string new_ending = "ó") {
        return Word::vidminok_r("ó");
    }
    virtual Word vidminok_th(string new_ending = "") {
        return Word::vidminok_th("");
    }
    virtual Word vidminok_o(string new_ending = "îì") {
        return Word::vidminok_r("îì");
    }
    virtual Word vidminok_m(string new_ending = "³") {
        return Word::vidminok_m("i");
    }
};
int main() {

    setlocale(LC_ALL, "Ukrainian");

    int n = 3;
    Word* arr[N] = {
        new Verb("ãóëÿ","ÿ","â"),
        new Adjective("÷óäîâ","","èé"),
        new Noun("ñîáàê","","à")
    };
    for (int i = 0; i < n; i++) {
        (arr[i]->change_genus_to_plular()).print();
        //arr[i];
    }
    cout << endl << endl << "Rod:" << endl;
    for (int i = 0; i < n - 1; i++) {
        (arr[i]->change_genus_to_w()).print();
        (arr[i]->change_genus_to_n()).print();
        cout << endl;
        //;
    }
    cout << endl << endl;
    for (int i = 1; i < n; i++) {
        (arr[i]->vidminok_r()).print();
        (arr[i]->vidminok_d()).print();
        (arr[i]->vidminok_th()).print();
        (arr[i]->vidminok_o()).print();
        (arr[i]->vidminok_m()).print();
        cout << endl;
    }
}
//figure.cpp
#include "Figure.h"
void Figure::input() {
    ;
};

void Figure::length() {
    if (name == "Polygon" || name == "Pentagon") {
        cout << "This progran doesn`t count length of sides of this figure: " << name << endl;
    }

    else {
        ;
    }
};

void Figure::perimeter() {
    if (name == "Polygon" || name == "Pentagon") {
        cout << "This progran doesn`t count perimeter of this figure: " << name << endl;
    }

    else {
        ;
    }
};

void Figure::square() {
    if (name == "Polygon" || name == "Pentagon") {
        cout << "This progran doesn`t count square of this figure: " << name << endl;
    }

    else {
        ;
    }
};

void Figure::isop() {
    if (name == "Triangle" || name == "Rectangle") {
        cout << "This progran doesn`t check if this figure is convex: " << name << endl;
    }

    else if (name == "Polygon" || name == "Pentagon") {
        ;
    }

    else cout << "Wrong figure name";
};
//figure.h
#pragma once
#ifndef FIGURE
#define  FIGURE

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

typedef struct {
    int x;
    int y;
}Point;

class Figure {

public:

    string name;

    Figure() {
        string name = "";
    }

    Figure(string n) : name(n) {
        string name = n;
        if (name != "Triangle" || name != "Polygon" || name != "Pentagon" || name != "Rectangle") exit(-1);
    }

    void input();

    void length();

    void perimeter();

    void square();

    void isop();

    void set_name(string a) {
        name = a;
    }

};


#endif FIGURE
//Pentagon.cpp
#include "Pentagon.h"

void Pentagon::inputPe() {
    for (int i = 0; i < 5; i++) {
        cout << "Input x coord for side " << i;
        cin >> mas[i].x;
        cout << "Input y coord for side " << i;
        cin >> mas[i].y;
    }
}

void Pentagon::lengthPe() {
    length();
}

void Pentagon::perimeterPe() {
    perimeter();
}

void Pentagon::squarePe() {
    square();
}

void Pentagon::isopPe() {

    int product, signPrev, sign = 0;
    int dx1, dx2, dy1, dy2, f = 0;

    for (int i = 0; i < 5; i++) {
        if (i < 5 - 1 && i + 1 == 5 - 1 && i + 2 > 5 - 1) {
            dx1 = mas[i + 1].x - mas[i].x;
            dy1 = mas[i + 1].y - mas[i].y;
            dx2 = mas[0].x - mas[i + 1].x;
            dy2 = mas[0].y - mas[i + 1].y;
        }
        else if (i == 5 - 1 && i + 1 > 5 - 1 && i + 2 > 5 - 1) {
            dx1 = mas[0].x - mas[i].x;
            dy1 = mas[0].y - mas[i].y;
            dx2 = mas[1].x - mas[0].x;
            dy2 = mas[1].y - mas[0].y;
        }
        else {
            dx1 = mas[i + 1].x - mas[i].x;
            dy1 = mas[i + 1].y - mas[i].y;
            dx2 = mas[i + 2].x - mas[i + 1].x;
            dy2 = mas[i + 2].y - mas[i + 1].y;
        }

        product = dx1 * dy2 - dy1 * dx2;

        signPrev = sign;
        if (product < 0) sign = -1;
        else if (product > 0) sign = 1;
        else if (product == 0) { ; }

        if (signPrev != 0 && sign != 0 && sign != signPrev) {
            f += 1;
        }
    }
    if (f == 0) cout << "This Polygon is  convex " << endl;
    else cout << "This Polygon is not convex " << f << endl;
}
//Pentagon.h
#pragma once
#ifndef PENTAGON
#define  PENTAGON
#include "Figure.h"

class Pentagon :public Figure {

private:
    Point mas[5];
public:

    Pentagon() {
        mas[0] = { 0, 1 };
        mas[1] = { -3, 3 };
        mas[2] = { -3, 6 };
        mas[3] = { -1, 8 };
        mas[4] = { 2, 8 };
    }

    void inputPe();
    void lengthPe();
    void perimeterPe();
    void squarePe();
    void isopPe();
};


#endif PENTAGON
//Polygon.cpp
#include "Polygon.h"

void Polygon::inputPo() {
    cout << "Input number of sides of Polygon ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Input x coord for side " << i;
        cin >> mas[i].x;
        cout << "Input y coord for side " << i;
        cin >> mas[i].y;
    }
}

void Polygon::lengthPo() {
    length();
}

void Polygon::perimeterPo() {
    perimeter();
}
void Polygon::squarePo() {
    square();
}
void Polygon::isopPo() {

    int product, signPrev, sign = 0;
    int dx1, dx2, dy1, dy2, f = 0;

    for (int i = 0; i < n; i++) {
        if (i < n - 1 && i + 1 == n - 1 && i + 2 > n - 1) {
            dx1 = mas[i + 1].x - mas[i].x;
            dy1 = mas[i + 1].y - mas[i].y;
            dx2 = mas[0].x - mas[i + 1].x;
            dy2 = mas[0].y - mas[i + 1].y;
        }
        else if (i == n - 1 && i + 1 > n - 1 && i + 2 > n - 1) {
            dx1 = mas[0].x - mas[i].x;
            dy1 = mas[0].y - mas[i].y;
            dx2 = mas[1].x - mas[0].x;
            dy2 = mas[1].y - mas[0].y;
        }
        else {
            dx1 = mas[i + 1].x - mas[i].x;
            dy1 = mas[i + 1].y - mas[i].y;
            dx2 = mas[i + 2].x - mas[i + 1].x;
            dy2 = mas[i + 2].y - mas[i + 1].y;
        }

        product = dx1 * dy2 - dy1 * dx2;
        cout << product << endl;

        signPrev = sign;
        if (product < 0) sign = -1;
        else if (product > 0) sign = 1;
        else if (product == 0) { ; }
        cout << "pr " << signPrev << "n " << sign;

        if (signPrev != 0 && sign != 0 && sign != signPrev) {
            f += 1;
        }
    }
    if (f == 0) cout << "This Polygon is  convex " << endl;
    else cout << "This Polygon is not convex " << f << endl;
}
//Polygon.h
#pragma once
#ifndef POLYGON
#define  POLYGON
#include "Figure.h"
#define N 50

class Polygon :public Figure {
private:
    int n;
    Point mas[N];
public:

    Polygon() {
        n = 7;
        mas[0] = { 0, 1 };
        mas[1] = { -3, 3 };
        mas[2] = { -3, 6 };
        mas[3] = { -1, 8 };
        mas[4] = { 2, 8 };
        mas[5] = { 4, 6 };
        mas[6] = { 2, 3 };

    }
    void inputPo();
    void lengthPo();
    void perimeterPo();
    void squarePo();
    void isopPo();
};


#endif PENTAGON
//Rectangle.cpp
#include "Rectangle.h"

void Rectangle::inputR() {
    cout << "Input left upper angle x coord";
    cin >> luAngle.x;
    cout << "Input left upper angle y coord";
    cin >> luAngle.y;
    cout << "Input right down angle x coord";
    cin >> rdAngle.x;
    cout << "Input right down angle y coord";
    cin >> rdAngle.y;
}

void Rectangle::lengthR() {
    Point ldAngle = { luAngle.x, rdAngle.y };
    Point ruAngle = { rdAngle.x,  luAngle.y };
    int q;
    cout << "(Rectangle) What side (1) for right and left, (2) for upper and down ";
    cin >> q;
    if (q == 1) {
        double len = pow(((luAngle.x - ldAngle.x) * (luAngle.x - ldAngle.x)) + ((luAngle.y - ldAngle.y) * (luAngle.y - ldAngle.y)), 0.5);
        cout << "(Rectangle) right and left sides length: " << len << endl;
    }
    if (q == 2) {
        double len = pow(((luAngle.x - ruAngle.x) * (luAngle.x - ruAngle.x)) + ((luAngle.y - ruAngle.y) * (luAngle.y - ruAngle.y)), 0.5);
        cout << "(Rectangle) upper and down sides length: " << len << endl;
    }
}

void Rectangle::perimeterR() {
    Point ldAngle = { luAngle.x, rdAngle.y };
    Point ruAngle = { rdAngle.x,  luAngle.y };

    double len1 = pow(((luAngle.x - ldAngle.x) * (luAngle.x - ldAngle.x)) + ((luAngle.y - ldAngle.y) * (luAngle.y - ldAngle.y)), 0.5);
    double len2 = pow(((luAngle.x - ruAngle.x) * (luAngle.x - ruAngle.x)) + ((luAngle.y - ruAngle.y) * (luAngle.y - ruAngle.y)), 0.5);

    cout << "(Rectangle) Perimeter: " << 2 * (len1 + len2) << endl;
}

void Rectangle::squareR() {
    Point ldAngle = { luAngle.x, rdAngle.y };
    Point ruAngle = { rdAngle.x,  luAngle.y };

    double len1 = pow(((luAngle.x - ldAngle.x) * (luAngle.x - ldAngle.x)) + ((luAngle.y - ldAngle.y) * (luAngle.y - ldAngle.y)), 0.5);
    double len2 = pow(((luAngle.x - ruAngle.x) * (luAngle.x - ruAngle.x)) + ((luAngle.y - ruAngle.y) * (luAngle.y - ruAngle.y)), 0.5);

    cout << "(Rectangle) Square: " << len1 * len2 << endl;
}

void Rectangle::isopR() {
    isop();
}
//Rectangle.h
#pragma once
#ifndef RECTANGLE
#define  RECTANGLE
#include "Figure.h"

class Rectangle :public Figure {
private:
    Point luAngle;
    Point rdAngle;

public:
    Rectangle() {
        luAngle = { 5,5 };
        rdAngle = { 1,1 };
    }
    void inputR();
    void lengthR();
    void perimeterR();
    void squareR();
    void isopR();
};


#endif RECTANGLE
//prog16_8 додаткова
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Pentagon.h"

int main() {
    Pentagon f3;
    //f3.inputPe();
    f3.set_name("Pentagon");
    f3.lengthPe();
    f3.squarePe();
    f3.perimeterPe();
    f3.isopPe();

    cout << "--------------------------------------------------" << endl;
    Polygon f2;
    //f2.inputPo();
    f2.set_name("Polygon");
    f2.lengthPo();
    f2.perimeterPo();
    f2.squarePo();
    f2.isopPo();

    cout << "--------------------------------------------------" << endl;

    Triangle f;
    //f.inputT();
    f.set_name("Triangle");
    f.lengthT();
    f.perimeterT();
    f.squareT();
    f.isopT();

    cout << "--------------------------------------------------" << endl;

    Rectangle f1;
    //f1.inputR();
    f1.set_name("Rectangle");
    f1.lengthR();
    f1.perimeterR();
    f1.squareR();
    f1.isopR();
}