// prog14_1

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {
    const char* fname = "test.txt";
    fstream f(fname, fstream::in);

    if (!f) {
        cerr << "cannot open file " << fname << "!";
        return -1;
    }

    string buf;
    f >> buf;
    clog << "Buf=" << buf << ";\n";

    int sum_expr = 0;
    int num = 0;
    int prevSign = 0;
    for (size_t i = 0; i < buf.length(); i++) {
        if (isdigit(buf[i])) {
            num = 10 * num;
            num += (buf[i] - '0');
        }
        else if (buf[i] == '+') {
            if (prevSign = 0) {
                sum_expr += num;
            }
            else {
                sum_expr -= num;
            }
            num = 0;
            prevSign = 0;
        }
        else if (buf[i] == '-') {
            if (prevSign = 0) {
                sum_expr += num;
            }
            else {
                sum_expr -= num;
            }
            num = 0;
            prevSign = 1;
        }
        else if (buf[i] == '=') {
            if (prevSign = 0) {
                sum_expr += num;
            }
            else {
                sum_expr -= num;
            }
            break;
        }
        else {
            cerr << "Cannot read char";
        }
    }
    cout << sum_expr;
}
//prog14_2
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    const char* filename = "test.txt";
    fstream f(filename, fstream::in);
    string buff, word(""), res("");

    while (!f.eof()) {
        getline(f, buff);
        for (size_t i = 0; i < buff.size(); i++) {
            if (isalpha(buff[i])) {
                word += buff[i];
            }
            else if (buff[i] == ' ' || buff[i] == ',' || buff[i] == '?' || buff[i] == '!' || buff[i] == ';') {
                for (int i = 0; i < word.length() / 2; i++)
                    swap(word[i], word[word.length() - i - 1]);
                res += word + buff[i];
                word = "";
            }
        }
        for (int i = 0; i < word.length() / 2; i++)
            swap(word[i], word[word.length() - i - 1]);
        res += word + '\n';
    }
    cout << res << '\n';
    f.close();
}
// prog14_3
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

int main() {
    const char* fname = "test.txt";

    fstream f;
    f.open(fname, fstream::in);

    if (!f) {
        cerr << "cannot open file" << fname << "!";
        return -1;
    }

    string articles[] = { "der", "das", "die" };
    int num_articles = 3;

    string buf;
    bool isArticle = false;

    fstream g;
    g.open("file.txt", fstream::out);

    if (!g) {
        cerr << "cannot open file\n" << "file.txt" << "!";
        return -1;
    }

    while (!f.eof()) {
        f >> buf;

        if (isArticle) {
            buf[0] = toupper(buf[0]);
        }
        g << buf << " ";
        cout << buf << " ";
        isArticle = false;
        for (int i = 0; i < num_articles; i++) {
            if (buf == articles[i]) {
                isArticle = true;
                break;
            }
        }
    }
    f.close();
    g.close();

    rename("file.txt", fname);

}
// prog14_4
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const char* fname = "test.txt";

    fstream f;
    f.open(fname, fstream::in);

    if (!f) {
        cerr << "cannot open file" << fname << "!";
        return;
    }

    string tagOpen = "<td>";
    string tagClose = "<\\td>";

    string line;
    int count = 0;
    while (f.is_open()) {
        getline(f, line);

        string::size_type k = 0;
        string::size_type posOpen = line.find(tagOpen);
        string::size_type posClose = line.find(tagClose);

        while (true) {
            posOpen = line.find(tagOpen, k);
            posClose = line.find(tagClose, k);
            if (posOpen == string::npos && posClose == string::npos) {
                break;
            }
            if (posOpen < posClose && posOpen != string::npos) {
                k = posOpen;
            }
            else if (posOpen > posClose && posClose != string::npos) {
                k = posClose + 1;
                count--;
            }
            if (count < 0) {
                isCorrect = false;
                break;
            }
        }
        if (!isCorrect) {
            break;
        }

    }
    f.close();
    std::cout << boolalpha << std::isCorrect && (count == 0);

}
// prog14_5
#include <iostream>
#include <fstream>
using namespace std;

int getDoubles(const char* fname, char delim, double* mas, int n) {
    double x;
    int k = 0;
    char d;
    std::string s;
    std::ifstream f1(fname);

    if (f1.bad()) {
        std::cerr << "error opening file " << fname << std::endl;
    }

    while (!f1.eof() && k < n) {

        if (f1 >> x) {
            mas[k++] = x;
        }
        else { break; }
        if (f1 >> d) {
            if (d == delim)continue;
            else {
                std::cerr << "error in file";
            }
        }
        else { break; }
        k++;
    }
    f1.close();
    return k;
}


int main() {

    std::string fname;//char fname[10]
    std::cout << "Input filename:";
    std::cin >> fname;
    std::cout << "Input n and delimiter:";
    int n;
    std::cin >> n;
    char delim;
    std::cin >> delim;
    double* mas = new double[n];

    int k = getDoubles(fname.c_str(), delim, mas, n);

    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << ", ";
    }

    delete[] mas;
}
// prog14_15
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int isInteger(const string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return 0;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

string toBinary(const string s) {
    int n = atoi(s.c_str());
    string number;

    bool negative = (n < 0);
    if (negative)
        n = -n;
    do
    {
        number += char('0' + n % 2);
        n = n / 2;
    } while (n > 0);

    if (negative)
        number += '-';
    return string(number.crbegin(), number.crend());
}


int main() {
    /* file.txt :
        -15.5 6 6ds
        asd 4a6
        a + a7s
        7 d 56.89 -18
    */
    string filename = "file.txt";

    ifstream fin(filename);
    if (!fin.good()) exit(1);
    string line, ss;
    vector<vector<string>> vec;
    while (getline(fin, line)) {
        vector<string> v;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ') ss += line[i];
            if (line[i] == ' ' || i == line.size() - 1) {
                v.push_back(ss);
                ss = "";
            }
        }
        vec.push_back(v);
    }
    fin.close();
    cout << endl;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (isInteger(vec[i][j]))
                vec[i][j] = toBinary(vec[i][j]);
        }
    }

    ofstream fout(filename);
    if (!fout.good()) exit(1);
    else {
        for (auto i : vec) {
            for (auto j : i)
                fout << j << " ";
            fout << endl;
        }
    }
    vec.clear();
    fout.close();
    return 0;
}
// prog14_18
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int main() {
    int N = 5;
    ofstream F2;
    ifstream F1;
    F1.open("C:\\Users\\Andrii\\Desktop\\учебное\\C\\Project2\\file1.txt", ios::in);
    F2.open("C:\\Users\\Andrii\\Desktop\\учебное\\C\\Project2\\file2.txt", ios::out);

    string min_str;
    string max_str;
    int min_len = 1000;
    int max_len = 0;
    char value;
    int k = 1;
    while (k < N) {
        string str;
        getline(F1, str);
        int len = str.length();
        if (len > max_len) {
            max_len = len;
            max_str = str;
        }
        if (len < min_len) {
            min_len = len;
            min_str = str;
        }
        k++;
    }
    F2 << "max string: " << max_str << endl;
    F2 << "min string: " << min_str << endl;

    F1.close();
    F2.close();
}
// prog14_15 доп номер
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int isInteger(const string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return 0;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

string toBinary(const string s) {
    int n = atoi(s.c_str());
    string number;

    bool negative = (n < 0);
    if (negative)
        n = -n;
    do
    {
        number += char('0' + n % 2);
        n = n / 2;
    } while (n > 0);

    if (negative)
        number += '-';
    return string(number.crbegin(), number.crend());
}


int main() {
    string filename = "file.txt";

    ifstream fin(filename);
    if (!fin.good()) exit(1);
    string line, ss;
    vector<vector<string>> v1;
    while (getline(fin, line)) {
        vector<string> v2;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ') ss += line[i];
            if (line[i] == ' ' || i == line.size() - 1) {
                v2.push_back(ss);
                ss = "";
            }
        }
        v1.push_back(v2);
    }
    fin.close();
    cout << endl;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1[i].size(); j++) {
            if (isInteger(v1[i][j]))
                v1[i][j] = toBinary(v1[i][j]);
        }
    }

    ofstream fout(filename);
    if (!fout.good()) exit(1);
    else {
        for (auto i : v1) {
            for (auto j : i)
                fout << j << " ";
            fout << endl;
        }
    }
    v1.clear();
    fout.close();
    return 0;
}