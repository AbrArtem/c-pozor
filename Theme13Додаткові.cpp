// prog13_24
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


char mostCommonVowel(string line) {
    int a, o, i, e, u;
    const char* l = line.c_str();
    for (int i = 0; i < strlen(l); i++) {
        char c = line[i];
        c = tolower(c);
        switch (c) {
        case 'a': a++;
        case 'o': o++;
        case 'i': i++;
        case 'e': e++;
        case 'u': u++;
        }
    }
    int m = 0;
    if (a > m) m = a;
    if (o > m) m = o;
    if (i > m) m = i;
    if (u > m) m = u;
    if (e > m) m = e;
    if (a == m) return 'a';
    if (o == m) return 'o';
    if (i == m) return 'i';
    if (u == m) return 'u';
    if (e == m) return 'e';
    return '0';
}


int main() {
    string line = "Hello mister and missis Smith!";
    //    cout << "Write smth: ";
    //    getline(cin, line);
    cout << "Most common vowel: " << mostCommonVowel(line);
}

// prog13_18
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;
int main() {
    char filename[100] = "file.txt";
    ifstream f(filename);
    string buf, st = "ings ";
    ofstream f2("file1.txt");

    while (f >> buf) {
        buf = buf + ' ';
        int p = buf.find(st, 0);
        if (p >= 1) {
            cout << buf << endl;
            f2 << buf << endl;
        }
    }
    f.close();
    f2.close();
}

