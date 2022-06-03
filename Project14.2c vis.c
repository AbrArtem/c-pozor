#include<locale.h>
#include <fcntl.h>
#include <wchar.h>
#include <uchar.h>
#include <windows.h>
#include <io.h>
#include <stdio.h>
int main() {
    //задаємо можливість виводу тексту українською мовою з кодуванням UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    printf("Задача №2\n");
    printf("Введіть ім'я :");//виведення тексту українською мовою з кодуванням UTF-8
    SetConsoleCP(1251);//задаємо локаль для введення тексту українською мовою
    SetConsoleOutputCP(1251);
    char name[20];//виділяємо 20 символів для введення імені українською мовою

    scanf("%s", &name);//вводимо ім'я українською мовою
    SetConsoleCP(65001);//задаємо можливість виводу тексту українською мовою з кодуванням UTF-8
    SetConsoleOutputCP(65001);
    printf("Привіт ");//виведення тексту українською мовою з кодуванням UTF-8
    SetConsoleCP(1251);//задаємо локаль для виведення тексту українською мовою
    SetConsoleOutputCP(1251);
    printf("%s", name);//виводимо ім'я, введене українською мовою
    printf("!");//закінчення виводу
}