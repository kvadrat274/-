#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793; // Константа числа π

// Функция для вычисления количества дней в году
int daysInYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 366; // Високосный год
    } else {
        return 365; // Обычный год
    }
}

// Функция для вычисления площади фигуры
double calculateArea(double r) {
    double sectorArea = PI * r * r / 4;   // Площадь сектора
    double triangleArea = r * r / 2;     // Площадь треугольника
    return sectorArea + triangleArea;   // Общая площадь
}

// Функция для вычисления периметра фигуры
double calculatePerimeter(double r) {
    double arcLength = PI * r / 2;       // Длина дуги
    double triangleSides = 2 * r;        // Две стороны треугольника
    return arcLength + triangleSides;   // Общий периметр
}

int main() {
    // Первая задача: вычисление количества дней в году
    cout << "=== Задача 1: Количество дней в году ===" << endl;
    int year;
    cout << "Введите номер года: ";
    cin >> year;

    int days = daysInYear(year);
    cout << "Количество дней в " << year << " году: " << days << endl;

    // Вторая задача: проверка принадлежности точки к фигуре
    cout << "\n=== Задача 2: Проверка принадлежности точки и вычисление параметров фигуры ===" << endl;
    double x, y, r;

    // Ввод координат точки и радиуса
    cout << "Введите координаты точки (x, y): ";
    cin >> x >> y;
    cout << "Введите радиус r: ";
    cin >> r;

    // Проверка, принадлежит ли точка фигуре
    if ((x * x + y * y <= r * r && x <= 0 && y >= 0)) {
        cout << "Точка принадлежит зеленому сектору (второй квадрант)." << endl;
    } else if ((x <= 0 && y <= 0 && y >= x - r)) {
        cout << "Точка принадлежит зеленому треугольнику (третий квадрант)." << endl;
    } else {
        cout << "Точка не принадлежит ни одной из фигур." << endl;
    }

    // Вычисление площади и периметра фигуры
    double area = calculateArea(r);
    double perimeter = calculatePerimeter(r);

    cout << "Площадь фигуры: " << area << endl;
    cout << "Периметр фигуры: " << perimeter << endl;

    return 0;
}
