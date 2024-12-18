#include <stdio.h>

// Определение структуры Express
struct Date
{
    int day;
    int month;
    int year;
};

struct Express
{
    struct Date start_date;      // Дата начала действия билета
    struct Date expiry_date;     // Дата срока действия билета
    int route_number;            // Номер маршрута
    struct Date travel_date;     // Дата проезда
    char boarding_time[6];       // Время посадки (в формате ЧЧ:ММ)
};

int main()
{
    struct Express ticket;

    // Ввод данных билета
    printf("Введите дату начала действия билета (дд мм гггг): ");
    scanf("%d %d %d", &ticket.start_date.day, &ticket.start_date.month, &ticket.start_date.year);

    printf("Введите дату срока действия билета (дд мм гггг): ");
    scanf("%d %d %d", &ticket.expiry_date.day, &ticket.expiry_date.month, &ticket.expiry_date.year);

    printf("Введите номер маршрута: ");
    scanf("%d", &ticket.route_number);

    printf("Введите дату проезда (дд мм гггг): ");
    scanf("%d %d %d", &ticket.travel_date.day, &ticket.travel_date.month, &ticket.travel_date.year);

    printf("Введите время посадки (чч:мм): ");
    scanf("%s", ticket.boarding_time);

    // Вывод данных билета
    printf("\nИнформация о билете:\n");
    printf("Дата начала действия: %02d.%02d.%04d\n", ticket.start_date.day, ticket.start_date.month, ticket.start_date.year);
    printf("Дата срока действия: %02d.%02d.%04d\n", ticket.expiry_date.day, ticket.expiry_date.month, ticket.expiry_date.year);
    printf("Номер маршрута: %d\n", ticket.route_number);
    printf("Дата проезда: %02d.%02d.%04d\n", ticket.travel_date.day, ticket.travel_date.month, ticket.travel_date.year);
    printf("Время посадки: %s\n", ticket.boarding_time);

}
