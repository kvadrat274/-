#include <iostream>

// Функція для обчислення факторіала
double Fact(int N) {
    if (N <= 0) {
        throw std::invalid_argument("N має бути більше 0");
    }
    
    double result = 1.0;
    for (int i = 1; i <= N; i++) {
        result *= i;
    }
    return result;
}

int main() {
    try {
        // Знаходимо факторіали п'яти чисел
        int numbers[] = {5, 7, 10, 3, 8};
        for (int i = 0; i < 5; i++) {
            std::cout << "Факторіал " << numbers[i] << " = " << Fact(numbers[i]) << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}