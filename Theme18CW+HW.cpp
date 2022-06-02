// prog18_1
#include <iostream>
#include <string>

namespace MM {
    template<typename T>
    T max(T a, T b) {
        if (a > b)
            return a;
        return b;
    }
}

int main() {
    int a = 3, b = 4;
    int x = MM::max(a, b);
    std::cout << x << std::endl;
    long long unsigned a1 = 6L, b1 = 7L;
    long long unsigned x1 = MM::max(a1, b1);
    std::cout << x1 << std::endl;
    std::string s1("aaaa");
    std::string s2("bbbb");
    std::string s = MM::max(s1, s2);
    std::cout << s << std::endl;
    return 0;
}
// prog18_2
#include <iostream>
#include <stack>
using namespace std;

template<class T>
struct Node {
    Node<T>* next;
    T item;
};

template<class T>
class MyStack {
private:
    int _size;
    Node<T>* head;
public:
    MyStack() : _size(0), head(nullptr) {}
    ~MyStack() {
        while (!empty())
            pop();
    }
    bool empty() { return head == nullptr; }
    int size() { return _size; }
    T top() {
        if (empty())
            throw logic_error("Stack is empty");
        return head->item;
    }
    void pop() {
        if (empty())
            throw logic_error("Stack is empty");
        Node<T>* node = head;
        head = node->next;
        delete node;
        _size--;
    }
    void push(T item) {
        Node<T>* node = new Node<T>();
        node->item = item;
        node->next = head;
        head = node;
        _size++;
    }
};

int main() {
    stack<int> stl_stack;
    MyStack<int> my_stack;
    for (int i = 0; i < 10; i++) {
        stl_stack.push(i);
        cout << stl_stack.top() << ends;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        my_stack.push(i);
        cout << my_stack.top() << ends;
    }
    cout << endl << endl;

    while (!stl_stack.empty()) {
        cout << stl_stack.top() << ends;
        stl_stack.pop();
    }
    cout << endl;
    while (!my_stack.empty()) {
        cout << my_stack.top() << ends;
        my_stack.pop();
    }
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
