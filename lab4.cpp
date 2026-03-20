#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char str1[80] = "qwerty";
    char str2[] = "1234567890";

    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    cout << "\nДлина str1 = " << strlen(str1) << endl;
    cout << "Длина str2 = " << strlen(str2) << endl;

    cout << "\nСравнение строк strcmp(str1, str2) = " << strcmp(str1, str2) << endl;

    char copy1[100];
    strcpy(copy1, str1);
    cout << "\nКопия str1: " << copy1 << endl;

    strcat(str1, str2);
    cout << "После сцепления str1 + str2: " << str1 << endl;

    char* d1 = new char[100];
    char* d2 = new char[100];

    strcpy(d1, "динамическая_строка_1");
    strcpy(d2, "динамическая_строка_2");

    cout << "\nДинамические строки:\n";
    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;

    cout << "strlen(d1) = " << strlen(d1) << endl;
    cout << "strcmp(d1, d2) = " << strcmp(d1, d2) << endl;

    strcat(d1, d2);
    cout << "После strcat(d1, d2): " << d1 << endl;

    delete[] d1;
    delete[] d2;

    return 0;
}
