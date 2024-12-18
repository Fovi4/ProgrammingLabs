#include <iostream>
using namespace std;

// Функция для вычисления суммы нечетных элементов строки
int sumOfOddElements(int row[], int M)
{
    int sum = 0;
    for (int j = 0; j < M; j++)
        if (row[j] % 2 != 0)
            sum += row[j];
    return sum;
}

int main()
{
    int N, M;

    cout << "Введите количество строк и столбцов: ";
    cin >> N >> M;

    int A[N][M];

    cout << "\nВведите элементы матрицы:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    cout << "Сумма нечетных элементов в каждой строке:\n";
    for (int i = 0; i < N; i++) {
        int sum = sumOfOddElements(A[i], M);
        cout << "Строка " << i + 1 << ": " << sum << endl;
    }
}
