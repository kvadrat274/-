#include <iostream>
using namespace std;

int main() {
    int number;
    
    // Введення тризначного числа
    cout << "Введіть тризначне число: ";
    cin >> number;

    // Отримання цифр сотень, десятків і одиниць
    int hundreds = number / 100;        // Сотні: ділимо на 100
    int tens = (number / 10) % 10;      // Десятки: ділимо на 10 і беремо залишок від ділення на 10
    int ones = number % 10;             // Одиниці: беремо залишок від ділення на 10

    // Перестановка цифр сотень і десятків
    int newNumber = tens * 100 + hundreds * 10 + ones;

    // Виведення результату
    cout << "Число після перестановки цифр сотень і десятків: " << newNumber << endl;

    return 0;
}
