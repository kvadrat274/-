#include <iostream>
#include <cmath>
#include <limits> // Для використання epsilon

using namespace std;

// Функція для обчислення добутку парних чисел (знаменник)
long long factorialEven(int k) {
    long long result = 1;
    for (int i = 2; i <= 2 * k; i += 2) {
        result *= i;
    }
    return result;
}

// Функція для обчислення добутку непарних чисел (чисельник)
long long factorialOdd(int k) {
    long long result = 1;
    for (int i = 1; i <= 2 * k - 1; i += 2) {
        result *= i;
    }
    return result;
}

int main() {
    double epsilon, g; // Значення epsilon і g для перевірки збіжності та розбіжності
    cout << "Введіть epsilon (малу величину для збіжності, наприклад 1e-5): ";
    cin >> epsilon;
    cout << "Введіть g (граничне значення для розбіжності, наприклад 1e2): ";
    cin >> g;

    if (epsilon <= 0 || g <= 0) {
        cout << "epsilon і g мають бути додатніми числами." << endl;
        return 1;
    }

    double sum1 = 0.0; // Сума для ряду збіжності/розбіжності
    int n = 1;         // Індекс елементу ряду
    double term1;      // Поточний член ряду

    // Розрахунок ряду збіжності/розбіжності
    while (true) {
        term1 = (pow(n, 2) + 5) / pow(2, n); // Формула u_n = (n^2 + 5) / 2^n

        // Умова збіжності
        if (fabs(term1) < epsilon) {
            cout << "Ряд збігається за умовою |u_n| < epsilon." << endl;
            break;
        }

        // Умова розбіжності
        if (fabs(term1) > g) {
            cout << "Ряд розбігається за умовою |u_n| > g." << endl;
            break;
        }

        sum1 += term1; // Додавання члена до суми
        n++;
    }

    cout << "Сума ряду (збіжність/розбіжність): " << sum1 << endl;
    cout << "Кількість доданків: " << n << endl;

    // Введення для другого завдання
    double x;
    int maxN; // Кількість елементів для формули
    cout << "\nВведіть x для другого ряду: ";
    cin >> x;
    cout << "Введіть n для другого ряду: ";
    cin >> maxN;

    double sum2 = x; // Сума для другого завдання (початковий доданок)
    double term2 = x;
    cout << "Елементи ряду:\n";

    for (int k = 1; k <= maxN; ++k) {
        // Обчислення наступного члена
        long long oddFactorial = factorialOdd(k);     // Чисельник
        long long evenFactorial = factorialEven(k);   // Знаменник
        term2 = (oddFactorial * pow(x, 2 * k + 1)) / (evenFactorial * (2 * k + 1));

        sum2 += term2;

        // Виведення кожного третього або четвертого елемента
        if ((k % 3 == 0 && maxN % 2 == 0) || (k % 4 == 0 && maxN % 2 != 0)) {
            cout << "Елемент " << k << ": " << term2 << endl;
        }
    }

    cout << "Сума другого ряду: " << sum2 << endl;

    return 0;
}