#include <iostream>
#include <string>
using namespace std;

// Определение структуры Phone
struct Phone
{
    string country;         // Страна-производитель
    float weight;           // Вес телефона (в граммах)
    float screen_size;      // Размер диагонали экрана (в дюймах)
    float price;            // Цена телефона (в у.е.)
};

int main()
{
    Phone phone;

    // Ввод данных о телефоне
    cout << "Введите страну-производитель: ";
    getline(cin, phone.country);

    cout << "\nВведите вес телефона (г): ";
    cin >> phone.weight;

    cout << "\nВведите размер диагонали экрана (дюймы): ";
    cin >> phone.screen_size;

    cout << "\nВведите цену телефона: ";
    cin >> phone.price;

    // Вывод данных о телефоне
    cout << "\nИнформация о телефоне:\n";
    cout << "Страна-производитель: " << phone.country << endl;
    cout << "Вес телефона: " << phone.weight << " г" << endl;
    cout << "Размер диагонали экрана: " << phone.screen_size << " дюймов" << endl;
    cout << "Цена телефона: " << phone.price << " у.е." << endl;

}
