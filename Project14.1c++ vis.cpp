#include <iostream>
#include <windows.h>

using namespace std;
int main() {
    //������ ��������� ����� �� ������ ������ ���������� ����� � ���������� UTF-8
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//65001
    cout << "������ �1" << endl;
    double k1, k2, k3; //���������� ������ ���� '����� � ��������� �������' ��� ������ ������� ���������� ������
    k1 = 2 + 3; //���������� �������� ������� ������ �� ���������� ���� �������� ������ k1
    k2 = 4.5 * 56;//���������� �������� ������� ������ �� ���������� ���� �������� ������ k2
    k3 = 2 / 3.0;//���������� �������� ������� ������ �� ���������� ���� �������� ������ k3
    cout << "��������� ������� : " << k1 << "; " << k2 << "; " << k3;//���� ����� ���������� ����� � ��������� �������
}