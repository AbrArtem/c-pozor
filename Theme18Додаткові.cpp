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

// prog18_4 додаткова
#include <iostream>
#include <exception>\
#include <string>
#include <vector>
#include <cmath>

#define N 100

using namespace std;

class moreThanN : public exception {
public:
    const char* what() const throw() {
        return "You wanted to enter more elements than allowed";
    }
};

class oor : public exception {
public:
    const char* what() const throw() {
        return "The element you wanted to return is out of range";
    }
};

template <class T>
class Mediana {
    vector<T> arr;
public:

    Mediana() = default;

    Mediana(vector<T>& array) {
        if (array.size() > N)  throw moreThanN();
        this->arr = array;
    }

    template <class T>
    friend bool& operator>(const Mediana& m1, const Mediana& m2) {
        for (int i = 0; i < min(m1.arr.size(), m2.arr.size(); i++) {
            if (m1.arr.at(i) != m2.arr.at(i)) { return m1.arr.at(i) > m2.arr.at(i); }
        }
    }

    template <class T>
    friend bool& operator<(const Mediana& m1, const Mediana& m2) {
        for (int i = 0; i < min(m1.arr.size(), m2.arr.size(); i++) {
            if (m1.arr.at(i) != m2.arr.at(i)) { return m1.arr.at(i) < m2.arr.at(i); }
        }
    }

    void push(T element) {
        arr.push_back(element);
    }

    T pop(int n) {
        if (n > arr.size()) throw oor();
            T item = arr.at(n);
        arr.erase(arr.begin() + n);
        return item;
    }

    //element in the middle
    T median() {
        size_t l = arr.size();
        if (l % 2 == 0) {
            T prev = arr.at(l / 2);
            T nex = arr.at((l / 2) - 1);
            return prev + nex;
        }
        else {
            return arr.at((int)(l / 2) + 1);
        }
    }

};


int main() {
    try {
        vector<int> items = { 1, 5, 2, 6 }; //01234
        Mediana<int> med(items);
        med.push(0); //5
        int n;
        cout << "What el do you want to return ";
        cin >> n;
        cout << n << " element is " << med.pop(n) << '\n';
        cout << "median is " << med.median();
    }
    catch (exception& e) {
        cerr << e.what();
    }
}