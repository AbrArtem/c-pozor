
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


    cout << "Задача №4" << endl;
    double a, b, gm;//оголошення змінних для запису значень обчислення виразу
    cout << "Введіть значення a та b для знаходження середнього геометричного: ";
    cout << endl << "a = ";//введення чисел для знаходження середнього геометричного
    cin >> a;
    cout << "b = ";
    cin >> b;
    gm = sqrt(a * b);//знаходження середнього геометричного

    cout << "Середнє геометричне рівне :" << gm;//вивід середнього геометричного
}