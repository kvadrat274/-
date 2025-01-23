#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip> // Для форматування виводу

const double PI = 3.141592653589793; // Константа числа π
//Integer15. Дано тризначне число. Вивести число, отримане при перестановці
//цифр сотень і десятків вихідного числа 
//(наприклад, 123 перейде в 213).
// Функція для перестановки сотень і десятків у тризначному числі
int swapHundredsAndTens(int num) {
    // Перевірка, що число тризначне (враховуючи від’ємні числа)
    if ((num < 100 && num > -100) || num > 999 || num < -999) {
        std::cerr << "Введіть тризначне число" << std::endl;
        return -1;
    }

    // Отримуємо абсолютні значення сотень, десятків та одиниць
    int absNum = std::abs(num);
    int hundreds = absNum / 100;
    int tens = (absNum / 10) % 10;
    int units = absNum % 10;

    // Переставляємо сотні і десятки
    int newAbsNum = tens * 100 + hundreds * 10 + units;

    // Повертаємо результат з урахуванням знака числа
    return (num < 0) ? -newAbsNum : newAbsNum;
}

//Boolean6. Дано три цілих числа: A, B, C. Перевірити істинність висловлювання:
//«Справедливо подвійне нерівність A <B <C».

// Функція для перевірки, чи знаходиться B між A і C
bool isBetween(int A, int B, int C) {
    return (A < B && B < C) || (C < B && B < A);
}
// (tab.3 N26)
// Обчислення складного математичного виразу
void calculateExpression() {
    std::cout << "\n=== Задача 3: Обчислення виразу ===" << std::endl;

    double x; // Змінна дійсного типу
    std::cout << "Введіть значення x: ";
    std::cin >> x;

    // Перевірка на допустимість обчислень
    if (x == 0 || std::sin(x * x * x) == 0 || std::tan(2 * x) == 0) {
        std::cerr << "Помилка: обчислення неможливі для заданого x через ділення на нуль або недопустимі аргументи." << std::endl;
        return;
    }

    // Обчислення чисельника
    double numerator = std::pow(1.5, std::pow(x, 2) * std::sin(x * x)) *
        std::cbrt(2 * std::abs(std::sin(3 * x + 24 * PI / 180) * std::log(std::abs(x * x * x))));

    // Обчислення знаменника
    double denominator = std::tan(2 * x) * std::sin(std::pow(x, 3));

    // Обчислення y
    double y = numerator / denominator;

    // Виведення результату
    std::cout << std::fixed << std::setprecision(6); // Форматування результату
    std::cout << "Результат: y = " << y << std::endl;
}

int main() {
    // Задача 1: Перестановка сотень і десятків
    std::cout << "=== Задача 1: Перестановка сотень і десятків ===" << std::endl;
    int num;
    std::cout << "Введіть тризначне число: ";
    std::cin >> num;

    int result = swapHundredsAndTens(num);
    if (result != -1) {
        std::cout << "Число після перестановки цифр сотень і десятків: " << result << std::endl;
    }

    // Задача 2: Перевірка подвійної нерівності
    std::cout << "\n=== Задача 2: Перевірка подвійної нерівності ===" << std::endl;
    int A, B, C;
    std::cout << "Введіть число A: ";
    std::cin >> A;
    std::cout << "Введіть число B: ";
    std::cin >> B;
    std::cout << "Введіть число C: ";
    std::cin >> C;

    if (isBetween(A, B, C)) {
        std::cout << "Число B знаходиться між числами A і C." << std::endl;
    }
    else {
        std::cout << "Число B не знаходиться між числами A і C." << std::endl;
    }

    // Задача 3: Обчислення виразу
    calculateExpression();

    return 0;
}