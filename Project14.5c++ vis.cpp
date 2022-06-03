#include <ctime>
#include <iostream>
#include <locale>


using namespace std;
int main() {
    tm tm{};//створення структури для заповнення датою
    int mm, dd, yyyy;//оголошення змінних
    cout << "Enter number of months :" << endl << "months = ";//введення змінних місяця, дня, року
    cin >> mm;
    cout << "Enter number of days :" << endl << "days = ";
    cin >> dd;
    cout << "Enter number of years :" << endl << "years = ";
    cin >> yyyy;
    tm.tm_year = yyyy - 1900;//зведення даних до правильного формату використання
    tm.tm_mon = mm - 1;
    tm.tm_mday = dd;
    char mbstr[100];//виділяємо сто символів для дати
    setlocale(LC_ALL, "de_DE.utf8");//оголошення німецької локалі
    if (strftime(mbstr, sizeof(mbstr), "%A %c", &tm)) {//перевірка коректності даних
        cout << mbstr << endl;//виведення дати в німецькій локалі
    }
    setlocale(LC_ALL, "en_US.utf8");//оголошення американської локалі
    if (strftime(mbstr, sizeof(mbstr), "%A %c", &tm)) {//перевірка коректності даних
        cout << mbstr << endl;//виведення дати в американській локалі
    }
    setlocale(LC_ALL, "uk_UA.utf8");//оголошення української локалі
    if (strftime(mbstr, sizeof(mbstr), "%A %c", &tm)) {//перевірка коректності даних
        cout << mbstr << endl;//виведення дати в українській локалі
    }
}