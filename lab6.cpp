#include <iostream>
#include <vector>
using namespace std;

// Функція для пошуку першого локального мінімуму
int findFirstLocalMinimum(const vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        // Перевіряємо перший елемент
        if (i == 0 && n > 1 && arr[i] < arr[i + 1]) {
            return i;
        }
        // Перевіряємо останній елемент
        if (i == n - 1 && arr[i] < arr[i - 1]) {
            return i;
        }
        // Перевіряємо середні елементи
        if (i > 0 && i < n - 1 && arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            return i;
        }
    }

    return -1; // Локальних мінімумів немає
}

int main() {
    int n; // Розмір масиву
    cout << "Введіть розмір масиву (N): ";
    cin >> n;

    if (n <= 0) {
        cout << "Розмір масиву повинен бути більшим за 0." << endl;
        return 1;
    }

    vector<int> arr(n); // Масив розміром n

    // Введення елементів масиву
    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Виведення початкового масиву
    cout << "Початковий масив:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Пошук першого локального мінімуму
    int localMinIndex = findFirstLocalMinimum(arr);
    if (localMinIndex != -1) {
        cout << "Перший локальний мінімум знаходиться на індексі: " << localMinIndex << endl;
        cout << "Значення: " << arr[localMinIndex] << endl;
    } else {
        cout << "Локальних мінімумів немає." << endl;
    }

    // Введення K і L
    int k, l;
    cout << "Введіть значення K і L (1 ≤ K < L ≤ N): ";
    cin >> k >> l;

    if (k < 1 || l > n || k >= l) {
        cout << "Неправильні значення K і L. Введіть K і L згідно з умовами (1 ≤ K < L ≤ N)." << endl;
        return 1;
    }

    // Перетворення K і L в індекси масиву (з 0-ої позиції)
    k--; // Зміщення K на 0-у позицію
    l--; // Зміщення L на 0-у позицію

    // Видалення елементів від K до L
    arr.erase(arr.begin() + k, arr.begin() + l + 1);

    // Виведення зміненого масиву
    cout << "Змінений масив:" << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Виведення розміру зміненого масиву
    cout << "Розмір зміненого масиву: " << arr.size() << endl;

    return 0;
}


