#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// ������� ��� ������� ������������������ ����������
int analyze_sequence(const vector<int>& temperatures) {
    int max_thaw = 0;
    int current_thaw = 0;

    for (int temp : temperatures) {
        if (temp > 0) {  // �������: ����������� ������ ���� ������ ������ 0
            current_thaw++;
        }
        else {
            max_thaw = max(max_thaw, current_thaw);
            current_thaw = 0;
        }
    }
    max_thaw = max(max_thaw, current_thaw);  // �������� ��������� ����� ������������� ����������
    return max_thaw;
}

// ������� ��� ������������ analyze_sequence
void test_analyze_sequence() {
    assert(analyze_sequence({ 10, 20, 30, 1, -10, 1, 2, 3 }) == 4);
    assert(analyze_sequence({ -10, 0, -10, 0, -10 }) == 0);
    assert(analyze_sequence({ -20, 30, -40, 50, 10, -10 }) == 2);
    assert(analyze_sequence({ -5, -10, 1, 2, 3, -1, 4 }) == 3);
    assert(analyze_sequence({ 0, 1, 2, 3, 4, 5 }) == 5);  // ����������
    assert(analyze_sequence({ -1, -1, -1, -1 }) == 0);
    cout << "��� ����� ��������." << endl;
}

int main() {
    test_analyze_sequence();
    return 0;
}
