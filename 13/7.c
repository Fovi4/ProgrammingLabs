#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Структура Zodiac_Sign
struct Zodiac_Sign
{
    char surname[50];      // Фамилия
    char name[50];         // Имя
    char zodiac[20];       // Знак Зодиака
    int birth_date[3];     // Дата рождения: день, месяц, год
};

// Функция для сортировки по году рождения
int compareByYear(const void* a, const void* b)
{
    struct Zodiac_Sign* personA = (struct Zodiac_Sign*)a;
    struct Zodiac_Sign* personB = (struct Zodiac_Sign*)b;

    // Сравниваем года рождения
    return personA->birth_date[2] - personB->birth_date[2];
}

int main()
{
    int n;

    printf("Введите количество людей: ");
    scanf("%d", &n);
    
    struct Zodiac_Sign people[n];

    // Ввод данных о людях
    for (int i = 0; i < n; i++)
    {
        printf("\n\nВведите данные для человека %d:\n", i + 1);

        printf("Фамилия: ");
        scanf("%s", people[i].surname);

        printf("\nИмя: ");
        scanf("%s", people[i].name);

        printf("\nЗнак Зодиака: ");
        scanf("%s", people[i].zodiac);

        printf("\nДень рождения (день месяц год): ");
        scanf("%d %d %d", &people[i].birth_date[0], &people[i].birth_date[1], &people[i].birth_date[2]);
    }

    // Сортировка массива людей по году рождения
    qsort(people, n, sizeof(struct Zodiac_Sign), compareByYear);

    // Вывод отсортированных данных
    printf("\n\nЛюди, отсортированные по году рождения:\n");
    for (int i = 0; i < n; i++)
        printf("\n%s %s\nЗнак Зодиака: %s\nДата рождения: %d.%d.%d\n", people[i].surname, people[i].name, people[i].zodiac, people[i].birth_date[0], people[i].birth_date[1], people[i].birth_date[2]);

    return 0;
}
