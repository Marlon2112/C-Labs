#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

class Stroka {
private:
    char str[80];

public:
    Stroka(const char* s = "") {
        strcpy(str, s);
    }

    Stroka(const Stroka& s) {
        strcpy(str, s.str);
    }

    Stroka& operator=(const Stroka& s) {
        if (this != &s) {
            strcpy(str, s.str);
        }
        return *this;
    }

    Stroka operator+(const Stroka& s) const {
        Stroka temp(*this);
        strcat(temp.str, s.str);
        return temp;
    }

    int operator==(const Stroka& s) const {
        return strcmp(str, s.str) == 0;
    }

    int dlina() const {
        return strlen(str);
    }

    void vvod() {
        cin.getline(str, 80);
    }

    void vyvod() const {
        cout << str;
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Stroka s1("qwert"), s3, s4(s1), s5;

    cout << "Введите строку: ";
    s3.vvod();

    cout << "Введенная строка: ";
    s3.vyvod();
    cout << endl;

    s5 = s4 + s3;
    cout << "Результат сложения строк: ";
    s5.vyvod();
    cout << endl;

    cout << "Длина s5 = " << s5.dlina() << endl;

    if (s3 == s4)
        cout << "Строки s3 и s4 равны\n";
    else
        cout << "Строки s3 и s4 не равны\n";

    return 0;
}
