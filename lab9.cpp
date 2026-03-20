#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

template <class T>
void Sort(T array[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                T tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

template <class T>
T getmax(T t1, T t2) {
    return (t1 > t2) ? t1 : t2;
}

template <class T>
T getmax(T t[], size_t size) {
    T result = t[0];
    for (size_t i = 1; i < size; i++)
        if (t[i] > result) result = t[i];
    return result;
}

char* getmax(char* s1, char* s2) {
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}

template <class T, int maxSize>
class TStack {
private:
    T items[maxSize];
    int topIndex;

public:
    TStack() : topIndex(-1) {}

    bool push(T item) {
        if (topIndex >= maxSize - 1) return false;
        items[++topIndex] = item;
        return true;
    }

    bool pop(T& item) {
        if (topIndex < 0) return false;
        item = items[topIndex--];
        return true;
    }

    bool empty() const {
        return topIndex == -1;
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int a[] = {10, 20, 30, 11, 25, 32, 0};
    int n = sizeof(a) / sizeof(a[0]);

    Sort(a, n);
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    int x = 3, y = 5;
    cout << "max(" << x << ", " << y << ") = " << getmax(x, y) << endl;
    cout << "max массива = " << getmax(a, n) << endl;

    char s1[] = "строка1";
    char s2[] = "строка2";
    cout << "max строк = " << getmax(s1, s2) << endl;

    TStack<int, 10> st;
    st.push(5);
    st.push(15);
    st.push(25);

    cout << "Стек:\n";
    int val;
    while (st.pop(val)) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
