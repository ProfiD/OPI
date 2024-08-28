#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Функция для анализа последовательности температур
int analyze_sequence(const vector<int>& temperatures) {
    int max_thaw = 0;
    int current_thaw = 0;

    for (int temp : temperatures) {
        if (temp > 0) {  // Условие: температура должна быть строго больше 0
            current_thaw++;
        }
        else {
            max_thaw = max(max_thaw, current_thaw);
            current_thaw = 0;
        }
    }
    max_thaw = max(max_thaw, current_thaw);  // Проверка последней серии положительных температур
    return max_thaw;
}

// Функция для тестирования analyze_sequence
void test_analyze_sequence() {
    assert(analyze_sequence({ 10, 20, 30, 1, -10, 1, 2, 3 }) == 4);
    assert(analyze_sequence({ -10, 0, -10, 0, -10 }) == 0);
    assert(analyze_sequence({ -20, 30, -40, 50, 10, -10 }) == 2);
    assert(analyze_sequence({ -5, -10, 1, 2, 3, -1, 4 }) == 3);
    assert(analyze_sequence({ 0, 1, 2, 3, 4, 5 }) == 5);  // Исправлено
    assert(analyze_sequence({ -1, -1, -1, -1 }) == 0);
    cout << "Все тесты пройдены." << endl;
}

int main() {
    test_analyze_sequence();
    return 0;
}
