
#include <stdio.h>
#include<locale.h>
#include <fcntl.h>
#include <fcntl.h>
#include <windows.h>
#include <io.h>
#include <math.h>
#include <stdlib.h>

int main() {
    SetConsoleCP(65001);//
    SetConsoleOutputCP(65001);

    printf("Задача №4\n");
    double a, b, gm;//оголошення змінних для запису значень обчислення виразу
    printf("Введіть значення a та b через пробіл для знаходження середнього геометричного: \n");
    scanf("%lf%lf", &a, &b);    //введення чисел для знаходження середнього геометричного

    gm = sqrt(a * b);//знаходження середнього геометричного
    printf("Середнє геометричне рівне :");
    printf("%lf", gm);//вивід середнього геометричного
}