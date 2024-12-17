#include <stdio.h>
#include <stdbool.h>

// Функция для проверки на локальный минимум
bool local_min(int n0, int n1, int n2)
{
    if ( n0 > n1 && n1 < n2 )
        return true;
    else
        return false;
}

int main()
{
	int N;
	printf("Введите количество элементов: ");
	scanf("%d", &N);
	
	int A[N];
	printf("\nВведите элементы: ");
	for ( int i = 0; i < N; i += 1 )
	    scanf("%d", &A[i]);
	
	int max_rez = -100000000;
	
	// Прохождение по массиву и поиск максимума
	for ( int i = 0; i < N; i++ )
	{
	    // Проверка первого элемента
	    if ( !i )
	        if ( local_min( A[i+1], A[i], A[i+1] ) && A[i] > max_rez )
	            max_rez = A[i];
	            
	    // Проверка последнего элемента
	    if ( i == N-1 )
	        if ( local_min( A[i-1], A[i], A[i-1] ) && A[i] > max_rez )
	            max_rez = A[i];
	            
	    // Проверка остальных элементов
	    if ( i && i < N-1 )
	        if ( local_min( A[i-1], A[i], A[i+1] ) && A[i] > max_rez )
	            max_rez = A[i];
	}
	if ( max_rez == -100000000 )
        printf("\nЛокальных минимумов нет.");
    else
	    printf("\nМаксимальный локальный минимум: %d", max_rez);
}

