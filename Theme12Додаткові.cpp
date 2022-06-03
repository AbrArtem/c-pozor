// prog12_7
#include<iostream> 
#include<iomanip> 
#include<cmath> 
#include<fstream> 
using namespace std;

int main() {
    double inp[1000];
    ifstream finp;
    finp.open("input.txt");
    int i = 0;
    while (!finp.eof()) {
        finp >> inp[i];
        finp.ignore(256, ';');
        if (finp.fail())
            break;
        i++;

    }
    finp.close();

    for (int l = 0; l < i; l++)
        cout << inp[l] << ends;

    cout << endl;

    ofstream fout;
    fout.open("out_12.7.txt");
    double out[1000];
    int k = 0;
    for (int j = 0; j < i; j++) {
        if (abs(inp[j]) <= 1) {
            fout << scientific << asin(inp[j]) << ends;
            out[k] = asin(inp[j]);
            k++;
        }
    }
    fout.close();

    for (int p = 0; p < k; p++)
        cout << scientific << out[p] << ends;

}

// prog12_9
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    string line, temp = "";
    vector<int> v;
    ifstream F;
    F.open("input.txt", ios::in);
    int a, i, j, v1, n;
    while (getline(F, line)) {
        for (char c : line + " ") {
            if (isdigit(c)) {
                temp += c;
            }
            else if (temp.size() > 0) {
                a = atoi(temp.c_str());
                v.push_back(a);
                n = v.size();
                for (i = 0; i < n - 2; i++) {
                    for (j = 1; j < n - 1; j++) {
                        if (v[i] > v[j]) {
                            //i=find(v.begin(), v.end(), v[i])
                            v1 = v[i] * v[i];
                            v[i] = v1;
                            //cout<<v[i]<<endl;
                            //v.erase(i);
                            //v.insert(i,v1);
                        }
                    }
                }

                temp = "";
            }
        }
    }
    F.close();

    ofstream G;
    G.open("output.txt", ios::out);
    for (int i : v) {
        if (i >= 0)
            G << i << " ";
    }
    G.close();
    return 0;
}

// prog12_15
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;


int geometric_mean() {
    int count = 0;
    double geo, mul = 1;
    long long a;
    ifstream fin;
    fin.open("file1.txt");
    while (true) {
        fin >> a;
        if (!fin.good())
            break;
        mul = mul * a;
        count += 1;
    }
    if (mul < 0 and (count % 2 == 0)) {
        cout << "Incorrect result. Rewrite number in file1.txt";
    }
    else {
        geo = pow(mul, 1.0 / count);
    }
    fin.close();
    return geo;
}

int main() {
    ifstream fin;
    fin.open("file1.txt");
    if (!fin.is_open()) {
        cout << "file didn't open" << endl;
    }
    else {
        if (geometric_mean() == 0) {
            cout << endl << "Restart the program " << endl;
        }
        else {
            cout << "Geometric mean  = " << geometric_mean() << endl;
        }
    }
    fin.close();
    return 0;
}