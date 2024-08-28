#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для ввода данных
vector<int> input_data(int& N) {
    setlocale(LC_ALL, "RU");
    cout << "Введите количество дней: ";
    cin >> N;
    vector<int> temperatures(N);
    cout << "Введите температуры: ";
    for (int i = 0; i < N; i++) {
        cin >> temperatures[i];
    }
    return temperatures;
}

// Функция для анализа последовательности температур
int analyze_sequence(const vector<int>& temperatures) {
    int max_thaw = 0;
    int current_thaw = 0;

    for (int temp : temperatures) {
        if (temp > 0) {
            current_thaw++;
        }
        else {
            max_thaw = max(max_thaw, current_thaw);
            current_thaw = 0;
        }
    }
    max_thaw = max(max_thaw, current_thaw);
    return max_thaw;
}

// Функция для вывода результата
void output_result(int result) {
    setlocale(LC_ALL, "RU");
    cout << "Длина самой продолжительной оттепели: " << result << " дней." << endl;
}

// Основная функция
int main() {
    int N;
    vector<int> temperatures = input_data(N);
    int max_thaw = analyze_sequence(temperatures);
    output_result(max_thaw);
    return 0;
}
