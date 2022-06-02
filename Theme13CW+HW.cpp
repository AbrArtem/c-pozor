// prog13_1
#include <iostream>

using namespace std;

void task1() {
    string s;
    cin >> s;

    string res;
    int pos_ddot = -1;
    int pos_semicol = -1;
    int k = 0;

    for (int i = 0; i < s.length(); i++) {
        char a = s[i];
        if (a == ":" && pos_ddot == -1) {
            pos_ddot = i;
        }

        if (a == ";" && pos_semicol == -1 && pos_ddot >= 0) {
            pos_semicol = i;
        }

        if (pos_ddot >= 0 && pos_semicol == -1) {
            res.push_back(a);
        }
    }

    if (pos_ddot == -1) {
        res = s;
    }

    cout << "result:" << res;
}
// prog13_2
void task2() {
    string s;
    getline(cin, s);

    string::size_type pos_first_stop = s.find('.');
    string::size_type pos_last_stop = s.rfind('.');

    if (pos_first_stop < pos_last_stop) {
        s.erase(pos_last_stop, s.length() - pos_last_stop);
        s.erase(0, pos_first_stop + 1);
    }
    else if (pos_first_stop != string::npos && pos_first_stop == pos_last_stop) {
        s.erase(0, pos_first_stop);
    }
    else {
        size_t k = 0;
        while (s[k] == ' ') {
            k++;
        }
        s.erase(0, k);
    }
    cout << "r=" << s;
}

// prog13_3
void task3() {
    string s;
    getline(cin, s);
    cout << "get" << s;

    string words[100];
    size_t k = 0;
    string::size_type pos = 0;
    string::size_type del = s.find(" ", 0);

    while (k < 100 && s.find("") != string::npos) {
        if (del > pos + 1) {
            words[k++] = s.substr(pos, del);
        }
        pos = del;
        del = s.find(" ", pos);
    }

    cout << "";
    for (size_t i = 0; i < k; i++) {
        cout << words[i] << " ";
    }
    for (int i = 0; i < k; i++) {
        words[k].erase(words[k].length() - 1, 1);
    }
    for (int i = 0; i < k; i++) {
        cout << words[i] << " ";
    }

}

int tesk4(const string& s, int n, int* arr);

int main(int argc, char** argv) {

    //task1();
    //task2();
    task3();

}
// prog13_5-6+їх main
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <climits>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::stringstream;

int parseWords(string s, char del, int n, string words[]) {
    stringstream sstream(s);
    string word;
    int k = 0;
    while (std::getline(sstream, word, del) && k < n) {
        words[k++] = word;
    }
    return k;
}

// prog13_5 - minimal words
string words_a(string s, char del) {
    stringstream sstream(s);
    string word;
    int k = 0;
    int min_word_len = INT_MAX;
    string min_word = "";
    while (std::getline(sstream, word, del)) {
        if (word.size() < min_word_len) {
            min_word = word;
            min_word_len = word.size();
        }
    }
    return min_word;
}

// prog13_6
void words_c(string s, char del) {
    stringstream sstream(s);
    stringstream sstream2(s);
    string word;
    int k = 0;
    int min_word_len = INT_MAX;
    string min_word = "";
    while (std::getline(sstream, word, del)) {
        if (word.size() < min_word_len) {
            min_word_len = word.size();
        }
    }
    while (std::getline(sstream, word, del)) {
        if (word.size() == min_word_len) {
            cout << "word = " << ",";
        }
    }
}

int main() {
    string text = "He said. The challenge Hector heard with joy, "
        "Then with his spear restrain`d the youth of Troy ";
    char del = ' ';
    /*vector<string> words{};
    stringstream sstream(text);
    string word;
    while(std::getline(sstream,word,del))
        words.push_back(word);
    for(const auto &str : words){
        cout << str << endl;
    }*/
    cout << "First min len word = " << words_a(text, del) << "\n";
    cout << "Last min len word = " << words_b(text, del) << "\n";
    words_c(text, del);
}
// prog13_12
#include <iostream>
#include <string>
#include <sstream>
#define N 100
using namespace std;


void find_longest_word(string words[N], string longest_words[N], int& words_number, int& longest_words_number) {

    string longest_word = words[0];

    for (int i = 1; i < words_number; i++) {
        if (words[i].length() > longest_word.length()) {
            longest_word = words[i];
        }
    }
    //cout<<longest_word;
    for (int i = 0; i < words_number; i++)
        if (words[i].length() == longest_word.length()) {
            longest_words[longest_words_number] = words[i];
            longest_words_number += 1;
        }

}

int main() {

    string s;
    getline(cin, s);

    stringstream ss;

    ss << s;

    int words_number = 0;
    int longest_words_number = 0;

    string* words = new string[N];
    string* longest_words = new string[N];

    while (ss.good()) {
        ss >> words[words_number];
        words_number += 1;
        if (ss.fail())
            break;
    }

    find_longest_word(words, longest_words, words_number, longest_words_number);

    for (int i = 0; i < longest_words_number; i++) {
        cout << longest_words[i] << endl;
    }


    delete[] words;
    delete[] longest_words;

    return 0;
}