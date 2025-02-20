#include <iostream>
#include <vector>
using namespace std;

struct NKA03
{
    string name, sex, group;
    int age;
    NKA03* next;
};

int main()
{
    
    cout << "Menu: \n0. Add information\n1. Add the person to the beginning\n2. Add the person to the end\n3. Remove a person\n4. Show the structure\n";
    vector <NKA03> nka;
    NKA03 A;
    int a;
    while (a >= 0 and a <= 4)
    {
        cin >> a;
        switch(a)
        {
            case 0:
            {
                cout << "Имя: ";
                cin >> A.name;
                cout << "Пол: ";
                cin >> A.sex;
                cout << "Возраст: ";
                cin >> A.age;
                cout << "Группа: ";
                cin >> A.group;
                break;
            }
        
            case 1:
            {
                nka.insert(nka.begin(), A);
                break;
            }

            case 2:
            {
                nka.push_back(A);
                break;
            }
            
            /*case 3:
            {
                int index;
                cout << "Введите номер человека, которого нужно удалить: ";
                cin >> index;
                nka.erase(nka.begin() + index);
            }*/
            
            case 4:
            {
                cout << endl;
                for (const auto& A : nka)
                    cout << "Имя: " << A.name << "\nПол: " << A.sex << "\nВозраст: " << A.age << "\nГруппа: " << A.group << "\n\n";                
            }
        
            default:
            {
                cout << endl;
                break;        
            }
        }        
    }
}
