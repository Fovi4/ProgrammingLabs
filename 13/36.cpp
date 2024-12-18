#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Определение структуры Phone
struct Phone
{
    string country;         // Страна-производитель
    float weight;           // Вес телефона (в граммах)
    float screen_size;      // Размер диагонали экрана (в дюймах)
    float price;            // Цена телефона (в у.е.)
};

// Функция для сортировки телефонов по цене
void sortPhonesByPrice(vector<Phone>& phones)
{
    sort(phones.begin(), phones.end(), [](const Phone& a, const Phone& b)
    {
        return a.price < b.price;
    });
}

int main()
{
    int n;
    cout << "Введите количество телефонов: ";
    cin >> n;
    cin.ignore();
    cout << endl;
    
    vector <Phone> phones(n);

    // Ввод данных о телефонах
    for (int i = 0; i < n; i++) {
        cout << "\nВведите данные для телефона " << i + 1 << ":\n";
        cout << "Страна-производитель: ";
        cin.ignore();

        getline(cin, phones[i].country);
        
        cout << "\nВес телефона (г): ";
        cin >> phones[i].weight;
        cin.ignore();


        cout << "\nРазмер диагонали экрана (дюймы): ";
        cin >> phones[i].screen_size;
        cin.ignore();

        cout << "\nЦена телефона: ";
        cin >> phones[i].price;
        cin.ignore();
        
        cout << endl;
    }

    // Сортировка телефонов по цене
    sortPhonesByPrice(phones);

    // Вывод отсортированных телефонов
    cout << "\nТелефоны, отсортированные по цене:\n";
    for (const auto& phone : phones)
    {
        cout << "Страна-производитель: " << phone.country << endl;
        cout << "Вес телефона: " << phone.weight << " г" << endl;
        cout << "Размер диагонали экрана: " << phone.screen_size << " дюймов" << endl;
        cout << "Цена телефона: " << phone.price << " у.е.\n" << endl;
    }

    return 0;
}
