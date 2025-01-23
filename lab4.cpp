#include <iostream>

// Процедура Swap, яка міняє вміст двох змінних
void Swap(int &X, int &Y) {
    int temp = X;
    X = Y;
    Y = temp;
}

// Функція для перевірки подвійної нерівності
bool checkInequality(int A, int B, int C) {
    return (A < B && B < C);
}

// Функція для перевірки, чи рівно два з чисел є додатними
bool checkTwoPositive(int A, int B, int C) {
    int positiveCount = 0;
    if (A > 0) positiveCount++;
    if (B > 0) positiveCount++;
    if (C > 0) positiveCount++;
    return (positiveCount == 2);
}

// Функція для перестановки цифр сотень і десятків у тризначному числі
int rearrangeDigits(int number) {
    int hundreds = number / 100;
    int tens = (number / 10) % 10;
    int units = number % 10;
    return (tens * 100 + hundreds * 10 + units);
}

int main() {
    int A, B, C, D, number;

    // Введення значень для A, B, C і D
    std::cout << "Введіть значення для A: ";
    std::cin >> A;
    std::cout << "Введіть значення для B: ";
    std::cin >> B;
    std::cout << "Введіть значення для C: ";
    std::cin >> C;
    std::cout << "Введіть значення для D: ";
    std::cin >> D;

    // Використання процедури Swap для обміну значень
    Swap(A, B); // Обмін значень A і B
    Swap(C, D); // Обмін значень C і D
    Swap(B, C); // Обмін значень B і C

    // Виведення нових значень
    std::cout << "Нові значення після обміну:\n";
    std::cout << "A: " << A << "\n";
    std::cout << "B: " << B << "\n";
    std::cout << "C: " << C << "\n";
    std::cout << "D: " << D << "\n";

    // Перевірка умови A < B < C
    if (checkInequality(A, B, C)) {
        std::cout << "Висловлювання A < B < C є істинним.\n";
    } else {
        std::cout << "Висловлювання A < B < C є хибним.\n";
    }

    // Перевірка умови "рівно два з чисел є додатними"
    if (checkTwoPositive(A, B, C)) {
        std::cout << "Висловлювання «Рівно два з чисел A, B, C є додатними» є істинним.\n";
    } else {
        std::cout << "Висловлювання «Рівно два з чисел A, B, C є додатними» є хибним.\n";
    }

    // Введення тризначного числа
    std::cout << "Введіть тризначне число: ";
    std::cin >> number;

    // Перевірка, чи є число тризначним
    if (number < 100 || number > 999) {
        std::cout << "Число не є тризначним.\n";
    } else {
        // Перестановка цифр сотень і десятків
        int newNumber = rearrangeDigits(number);
        std::cout << "Число після перестановки цифр сотень і десятків: " << newNumber << "\n";
    }

    return 0;
}