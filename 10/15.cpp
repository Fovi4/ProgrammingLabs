#include <iostream>
using namespace std;

string ReOrdered(int A[], int N)
{
    int left = 0;         // Индекс с начала массива
    int right = N - 1;    // Индекс с конца массива
    string result = "";  // Строка для хранения результата

    while (left <= right)
    {
        if (left == right)
            // Если остался один элемент, добавляем его
            result += to_string(A[left]) + " ";
            
        else
            // Добавляем элементы с начала и с конца
            result += to_string(A[left]) + " " + to_string(A[right]) + " ";

        left++;
        right--;
    }

    return result;
}

int main()
{
    int N;
    cout << "Введите количество элементов: ";
    cin >> N;

    int A[N];
    cout << "\nВведите элементы массива: ";
    for ( int i = 0; i < N; i++ )
        cin >> A[i];
        
    cout << "\nПреобразованный массив: " << ReOrdered(A, N);
}
