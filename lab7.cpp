#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Point {
protected:
    int x, y;
    string color;

public:
    Point(int x = 0, int y = 0, string color = "white") : x(x), y(y), color(color) {}

    virtual void Show() const {
        cout << "Точка: x=" << x << ", y=" << y << ", color=" << color << endl;
    }

    virtual void Hide() const {
        cout << "Точка скрыта\n";
    }

    virtual void Move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    virtual ~Point() {}
};

class Krug : public Point {
protected:
    int radius;

public:
    Krug(int x = 0, int y = 0, int radius = 1, string color = "white")
        : Point(x, y, color), radius(radius) {}

    void Show() const override {
        cout << "Круг: центр=(" << x << ", " << y << "), radius=" << radius
             << ", color=" << color << endl;
    }

    void Hide() const override {
        cout << "Круг скрыт\n";
    }
};

class Ring : public Krug {
private:
    int width;

public:
    Ring(int x = 0, int y = 0, int radius = 1, int width = 1, string color = "white")
        : Krug(x, y, radius, color), width(width) {}

    void Show() const override {
        cout << "Кольцо: центр=(" << x << ", " << y << "), radius=" << radius
             << ", width=" << width << ", color=" << color << endl;
    }

    void Hide() const override {
        cout << "Кольцо скрыто\n";
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Point p(10, 20, "red");
    Krug k(30, 40, 15, "green");
    Ring r(50, 60, 20, 5, "blue");

    p.Show();
    k.Show();
    r.Show();

    cout << "\nПеремещение объектов:\n";
    p.Move(5, 5);
    k.Move(-10, 10);
    r.Move(0, -20);

    p.Show();
    k.Show();
    r.Show();

    return 0;
}
