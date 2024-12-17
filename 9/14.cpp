#include <iostream>
#include <cmath>
using namespace std;

int cnt( long long a, int b )
{
    int cnt = 0;
    while ( a )
    {
        if ( a % 10 == b )
            cnt ++;
        a /= 10;
    }
    return cnt;
}

int main()
{
    int N, n;
    cout << "Введите число: ";
    cin >> N;
    cout << "\nВведите степень: ";
    cin >> n;
    double a = pow(N,n);
    cout << "\nВаше число: " << a << "\nВ нем встречается: \n";
    cout << "Цифра 0: " << cnt(a, 0) << " раз\n";
    cout << "Цифра 1: " << cnt(a, 1) << " раз\n";
    cout << "Цифра 2: " << cnt(a, 2) << " раз\n";
    cout << "Цифра 3: " << cnt(a, 3) << " раз\n";
    cout << "Цифра 4: " << cnt(a, 4) << " раз\n";
    cout << "Цифра 5: " << cnt(a, 5) << " раз\n";
    cout << "Цифра 6: " << cnt(a, 6) << " раз\n";
    cout << "Цифра 7: " << cnt(a, 7) << " раз\n";
    cout << "Цифра 8: " << cnt(a, 8) << " раз\n";
    cout << "Цифра 9: " << cnt(a, 9) << " раз\n";
}
