#include <iostream>
using namespace std;

class str {
public:
	int len;//довж
	char* s;//массив
	str(int num) {
		cout << "constr" << endl;
		len = num;
		//char* s = new char(num);
		s = new char(num);
	}

	void print() {
		cout << "print" << endl;
		for (int i = 0; i < len; i++) {
			cout << s[i];
		}
	}
	void input() {
		cout << "input" << endl;
		cout << len << endl;
		for (int i = 0; i < len; i++) {
			cout << "enter " << i << " part of massive" << endl;
			cin >> s[i];
		}
	}
	void free() {
		delete[] s;
	}
};

int main() {
	str s(10);
	s.input();
	s.print();
	s.free();
}