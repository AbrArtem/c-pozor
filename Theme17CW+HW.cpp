// prog17_1
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <exception>
using namespace std;


class RationalError : public logic_error {

public:
    RationalError(string message) : logic_error(message) {}
};


class ZeroDenominatorError : public RationalError {

public:
    ZeroDenominatorError() : RationalError("Zero denominator!") {}
};


class NegativeDenominatorError : public RationalError {

public:
    NegativeDenominatorError(int64_t d) :
        RationalError("Negative denominator! " + to_string(d)) {}
};


class Rational {

private:

    int64_t numer;
    int64_t denom;

    void to_irreducible() {
        int64_t d = gcd(abs(numer), denom);
        numer /= d;
        denom /= d;
    }

    void initialize(int64_t numer, int64_t denom) {
        if (denom == 0)
            throw ZeroDenominatorError();
        if (denom < 0)
            throw NegativeDenominatorError(denom);
        this->numer = numer;
        this->denom = denom;
        to_irreducible();
    }

public:

    Rational(int64_t numer, int64_t denom) {
        initialize(numer, denom);
    }

    Rational() : Rational(1, 1) {}
    Rational(int64_t number) : Rational(number, 1) {}
    Rational(const Rational& a) : Rational(a.numer, a.denom) {}

    Rational(const string& random) {
        int sign = rand() % 2 ? 1 : -1;
        initialize(sign * rand() % 100, rand() % 100 + 1);
    }

    void print(ostream& out = cout) {
        out << numer << "/" << denom;
    }

    void input(istream& inp = cin) {
        int64_t numer, denom;
        inp >> numer;
        inp.ignore(256, '/');
        inp >> denom;
        initialize(numer, denom);
    }

    void add(const Rational& other) {
        numer = numer * other.denom + other.numer * denom;
        denom = denom * other.denom;
        to_irreducible();
    }

    void multiply(const Rational& other) {
        numer = numer * other.numer;
        denom = denom * other.denom;
        to_irreducible();
    }

    Rational operator+() { return Rational(*this); }
    friend Rational operator-(const Rational& self) { return Rational(-self.numer, self.denom); }

    Rational operator+(const Rational& other) {
        Rational result(*this);
        result.add(other);
        return result;
    }

    Rational operator-(const Rational& other) {
        Rational result(*this);
        result.add(-other);
        return result;
    }

    Rational operator*(const Rational& other) {
        Rational result(*this);
        result.multiply(other);
        return result;
    }

    Rational& operator+=(const Rational& other) { add(other); return *this; }
    Rational& operator-=(const Rational& other) { add(-other); return *this; }
    Rational& operator*=(const Rational& other) { multiply(other); return *this; }

    bool operator<(const Rational& other) { return numer * other.denom < other.numer* denom; }
    bool operator<(const int other) { return numer < denom* other; }
    bool operator>(const Rational& other) { return numer * other.denom > other.numer * denom; }
    bool operator>(const int other) { return numer > denom * other; }
    bool operator<=(const Rational& other) { return numer * other.denom <= other.numer * denom; }
    bool operator>=(const Rational& other) { return numer * other.denom >= other.numer * denom; }
    bool operator==(const Rational& other) { return numer == other.numer && denom == other.denom; }
    bool operator!=(const Rational& other) { return numer != other.numer || denom != other.denom; }

    double to_double() { return (double)numer / denom; }

    static int64_t gcd(int64_t a, int64_t b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    static int64_t abs(int64_t a) {
        return a > 0 ? a : -a;
    }

    friend Rational abs(Rational& a) {
        return a > 0 ? +a : -a;
    }

    friend ostream& operator<<(ostream& out, Rational& a) {
        a.print(out);
        return out;
    }

    friend istream& operator>>(istream& inp, Rational& a) {
        a.input(inp);
        return inp;
    }

};


int main() {
    int n;
    cin >> n;
    Rational* arr = new Rational[n];
    int i = 0;
    while (i < n) {
        try {
            cin >> arr[i];
        }
        catch (RationalError& e) {
            cout << e.what() << endl;
            cout << "Try again" << endl;
            continue;
        }
        catch (exception& e) {
            cout << e.what() << endl;
            break;
        }
        catch (...) {
            cout << "Unknown exception was caught" << endl;
            break;
        }
        i++;
    }
    for (i = 0; i < n; i++)
        cout << arr[i] << ' ';

    delete[] arr;

    return 0;
}
// prog17_2
#include <iostream>
#include <string>
#define DEBUG 0
#define N 100
using namespace std;


class Human {

protected:

    string name;
    string sex;
    int age;

public:

    Human(string name, string sex, int age) : name(name), sex(sex), age(age) {
        if (DEBUG) cout << "Create Human " + name << endl;
    }

    virtual ~Human() {
        if (DEBUG) cout << "Delete Human " + name << endl;
    }

    virtual void print() {
        cout << name << ' ' << age << ' ' << sex;
    }

    void hello() {
        print();
        cout << endl;
    }

};


class Student : virtual public Human {

protected:

    int course;
    string group;
    string univ;

public:

    Student(string name, string sex, int age, int course = 1, string group = "stat1", string univ = "NUK") :
        Human(name, sex, age), course(course), group(group), univ(univ) {

        if (DEBUG) cout << "Create Student " + name << endl;
    }

    virtual ~Student() {
        if (DEBUG) cout << "Delete Student " + name << endl;
    }

    virtual void print() {
        Human::print();
        cout << ' ' << univ << ' ' << course << ' ' << group;
    }
};


class Teacher : virtual public Human {

protected:

    string position;
    double salary;
    string univ;

public:

    Teacher(string name, string sex, int age, string position = "Programming Teacher", double salary = 11.1, string univ = "KNUBA") :
        Human(name, sex, age), position(position), salary(salary), univ(univ) {

        if (DEBUG) cout << "Create Teacher " + name << endl;
    }

    virtual ~Teacher() {
        if (DEBUG) cout << "Delete Teacher " + name << endl;
    }

    virtual void print() {
        Human::print();
        cout << ' ' << univ << ' ' << salary << ' ' << position;
    }
};


class PGS : public Student, public Teacher { //, public Teacher

public:

    PGS(string name, string sex, int age, int course = 2, string group = "stat1", string position = "Teacher", double salary = 9.5, string univ = "KPI") : //string position = "Teacher", double salary = 9.5, 
        Human(name, sex, age), Student(name, sex, age, course, group, univ), Teacher(name, sex, age, position, salary, univ) { //, Teacher(name, sex, age, position, salary, univ)

        if (DEBUG) cout << "Create PGS " + Student::name << endl;
    }

    virtual ~PGS() {
        if (DEBUG) cout << "Delete PGS " + Student::name << endl;
    }

    virtual void print() {
        Student::print();
        //cout << ' ' << salary;
    }
};



int main() {
    int n = 4;
    Human* arr[N] = {
        new Human("Alex the Human", "M", 50),
        new Student("Masha the Student", "W", 18),
        new Teacher("Gosha the Teacher", "M", 26),
        new PGS("Liza the PGS", "W", 30)
    };
    for (int i = 0; i < n; i++)
        arr[i]->hello();
    for (int i = 0; i < n; i++)
        delete arr[i];

}
// prog17_4
#include<iostream>
#include<complex>
#include<cmath>

using namespace std;

class InputError : public logic_error {
public:
    InputError(const char* message) : logic_error(message) {}
};


class ValueError : public logic_error {
public:
    ValueError(const char* message) : logic_error(message) {}
};


template<class T>
ostream& operator<<(ostream& out, complex<T>& z) {
    out << real(z) << " + " << imag(z) << "i";
    return out;
}


void InputWithExceptions(complex<double>* z) {
    while (true) {
        try {
            double real, imag;
            cout << "enter a and b: ";
            cin >> real >> imag;

            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw InputError("Wrong input. It is not a comlex number. Enter a b\nTry again");
            }
            *z = complex<double>(real, imag);
            if (abs(*z) >= 1) throw InputError("|z| must be less than 1. Enter a b\nTry again");
            break;
        }
        catch (InputError& error) {
            cout << error.what() << endl;
            cin.ignore();
        }
    }
}
complex<double> arctan(complex<double> z) {
    double eps = 0.0001;
    complex<double> ans(0.0, 0.0);
    try {
        for (double i = 0;; i++) {
            if (abs((pow(-1, i) * pow(z, 2 * i + 1)) / (2 * i + 1)) < eps)
                throw ValueError((char*)"The element is less than eps = 0.0001.\n");
            ans += pow(-1, i) * pow(z, 2 * i + 1) / (2 * i + 1);
            cout << pow(-1, i) * pow(z, 2 * i + 1) / (2 * i + 1) << endl;
        }
    }
    catch (ValueError& error) {
        cout << error.what() << endl;
    }

    return ans;
}

int main() {
    complex<double> z, ans;
    InputWithExceptions(&z);
    cout << z << endl;
    ans = arctan(z);
    cout << "atctan(" << z << ")" << " = " << ans << endl << endl;
    return 0;
}
// prog18_9 додаткова
#include <iostream>

template<typename T>
auto sum(T* arr, size_t n) {
    if constexpr (std::is_pointer<T>::value) {
        T res;
        typedef typename std::remove_pointer<T>::type A;
        res = new A[n];
        for (int i = 0; i < n; i++) {
            res[i] = *arr[i];
        }
        return res;
    }
    else if constexpr (std::is_same<T, char>::value) {
        std::string tmp;
        for (int i = 0; i < n; i++) {
            tmp += arr[i];
        }
        return tmp;
    }
    else {
        T res;
        if constexpr (!std::is_same<T, std::string>::value) res = 0;
        for (int i = 0; i < n; i++) {
            res += arr[i];
        }
        return res;
    }
}

int main() {
    int size = 3;
    int v1[] = { 1, 2, 3 };
    double v2[] = { 1.0, 2.0, 3.0 };
    std::string v3[] = { "ab", "cd", "ef" };
    char v4[] = { 'a', 'b', 'c' };

    int v5_1[] = { 1, 4 };
    int v5_2[] = { 2 };
    int v5_3[] = { 3 };
    int* v5[] = { v5_1, v5_2, v5_3 };

    std::cout << sum(v1, size) << std::endl;
    std::cout << sum(v2, size) << std::endl;
    std::cout << sum(v3, size) << std::endl;
    std::cout << sum(v4, size) << std::endl;

    int* tmp = sum(v5, size);
    for (int i = 0; i < size; i++) {
        std::cout << tmp[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
