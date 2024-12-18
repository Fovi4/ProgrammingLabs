#include <stdio.h>
#include <stdbool.h>

// Функция для проверки, содержит ли столбец только положительные элементы
bool isPositiveColumn(int n, int m, int A[n][m], int ind)
{
    for (int i = 0; i < n; i++)
        if (A[i][ind] <= 0)
            return false;
    
    return true;
}

// Процедура для замены столбцов
void swapColumns(int n, int m, int A[n][m])
{
    int lastPositiveCol = -1;

    // Поиск последнего столбца, содержащего только положительные элементы
    for (int j = 0; j < m; j++)
        if (isPositiveColumn(n, m, A, j))
            lastPositiveCol = j;

    // Если подходящий столбец найден, меняем его местами с первым
    if (lastPositiveCol != -1 && lastPositiveCol != 0)
        for (int i = 0; i < m; i++)
        {
            int temp = A[i][0];
            A[i][0] = A[i][lastPositiveCol];
            A[i][lastPositiveCol] = temp;
        }
}

int main()
{
    int N, M;
    printf("Введите количество строк и столбцов: ");
    scanf("%d %d", &N, &M);

    int A[N][M];

    printf("\nВведите элементы матрицы:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &A[i][j]);

    swapColumns(N, M, A);

    printf("Преобразованная матрица:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

}
