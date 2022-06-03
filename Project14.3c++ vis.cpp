#include <iostream>
#include<locale>
#include <codecvt>
#include <cmath>
#include <iostream>
#include<locale.h>
#include <fcntl.h>
#include <fcntl.h>
#include <cstring>
#include <windows.h>
#include <io.h>
using namespace std;
int main() {
    //задаємо можливість виводу тексту українською мовою з кодуванням UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout << endl << "Задача №3" << endl;
    int money, coins; //оголошення цілочисельних змінних
    cout << "Введіть кількість гривень:";
    cin >> money;//введення суми в гривнях, яку слід задавати в різних локалях
    cout << "Введіть кількість копійок:";
    cin >> coins;//введення суми в копійках, яку слід задавати в різних локалях
    cout << "В українській локалі : ";
    if (coins >= 100) {//перетворення суми грошей в коректну форму
        money = money + coins / 100;
        coins = coins % 100;
    }
    //задаємо можливість виводу тексту українською мовою з кодуванням UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    cout << endl << money << " гривні " << coins << " копійок ₴" << endl;//вивід в українській локалі
    cout << "В американській локалі : ";
    cout << money << " dollars " << coins << " cents $" << endl;//вивід в американській локалі
    cout << "В англійській локалі : ";
    SetConsoleCP(856);
    SetConsoleOutputCP(856);
    cout << money << " pounds " << coins << " pence ₤" << endl;//вивід в британській локалі
}