// prog14_9
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;


void answering(const char* fname, int n) {
    ofstream fout(fname, ios::app);
    if (!fout.is_open()) return;
    string name;
    cout << "Your name: ";
    cin >> name;
    fout << name << " ";
    int i, j, ans;
    for (int k = 0; k < n; k++) {
        i = rand() % 20 + 1;
        j = rand() % 20 + 1;
        cout << i << " * " << j << " = ";
        cin >> ans;
        fout << i << "x" << j << "=" << ans << " ";
    }
    fout << endl;
}


void results(const char* fname) {
    ifstream file(fname);
    if (!file.is_open()) return;
    while (!file.eof()) {
        string line;
        getline(file, line);
        string name = line.substr(0, line.find(" "));
        line.erase(0, line.find(" ") + 1);
        double right = 0, total = 0;
        while (line != "") {
            string ex = line.substr(0, line.find(" "));
            if (line.find(" ") == string::npos) {
                ex = line;
                line = "";
            }
            else line.erase(0, line.find(" ") + 1);
            if (ex == "") continue;
            int i, j, res;
            i = stoi(ex.substr(0, ex.find("x")));
            ex.erase(0, ex.find("x") + 1);
            j = stoi(ex.substr(0, ex.find("=")));
            ex.erase(0, ex.find("=") + 1);
            res = stoi(ex);
            total++;
            if (i * j == res) right++;
        }
        double perc = (double)right / total;
        cout << name << " has " << perc * 100 << "% (" << right << "/" << total << ") of right answers!\n";
    }
}


void game(const char* fname, int m, int n) {
    for (int i = 0; i < m; i++) answering(fname, n);
    results(fname);
}


int main() {
    srand(time(0));
    results("14_9.txt");
    //game("14_9.txt", 3, 5);
}

// prog14_11
#include <iostream> 
#include <fstream> 
#include <string> 

using namespace std;

void align(const char* filename) {
    string arr[50];
    ifstream finp(filename);
    if (!finp.good())
        exit(1);
    int j = 0;
    while (finp.good()) {
        string s;
        getline(finp, s);
        if (finp.fail())
            break;
        int num_of_gaps;
        if (s.length() % 2 != 0) {
            num_of_gaps = (50 - s.length() + 1) / 2;
        }
        else if (s.length() % 2 == 0) {
            num_of_gaps = (50 - s.length()) / 2;
        }
        cout << s.length() << endl;
        arr[j] = "";
        int i = 0;
        while (i < num_of_gaps) {
            arr[j] += " ";
            i++;
        }
        arr[j] += s;
        j++;
    }
    finp.close();

    ofstream fout(filename);
    for (int i = 0; i < j; i++) {
        fout << arr[i] << endl;
    }
    fout.close();
}


int main() {
    align("input14.11.txt");
    return 0;
}