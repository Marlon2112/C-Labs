#include <iostream>
#include <fstream>
#include <stdexcept>
#include <windows.h>
using namespace std;

class FileException : public exception {
private:
    string message;
public:
    FileException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileEncryptor {
private:
    string inputFile;
    string outputFile;
    int key;

public:
    FileEncryptor(string in, string out, int k) : inputFile(in), outputFile(out), key(k) {}

    void encrypt() {
        ifstream fin(inputFile);
        if (!fin) throw FileException("Не удалось открыть входной файл.");

        ofstream fout(outputFile);
        if (!fout) throw FileException("Не удалось открыть выходной файл.");

        char ch;
        while (fin.get(ch)) {
            fout.put(ch + key);
        }

        fin.close();
        fout.close();
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    try {
        FileEncryptor enc("text.txt", "encrypted.txt", 2);
        enc.encrypt();
        cout << "Файл успешно зашифрован.\n";
    }
    catch (const FileException& e) {
        cout << "Ошибка файла: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Общая ошибка: " << e.what() << endl;
    }

    return 0;
}
