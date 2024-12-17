#include <stdio.h>

// Функция
int min( int a, int b )
{
    if ( a <= b )
        return a;
    else
        return b;
}

int main()
{
    // Ввод переменных
    int a, b;
    printf("Введите значение a: ");
    scanf("%d", &a);
    printf("\nВведите значение b: ");
    scanf("%d", &b);
    
    // Запись результата функции в z
    int z = min(a, 3*b) * min(2*a-b, 2*b);
    
    // Вывод
    printf("\nmin(a, 3b)*min(2a-b, 2b): %d", &z);

}
