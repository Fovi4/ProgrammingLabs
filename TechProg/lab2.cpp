#include <iostream>
using namespace std;

class vect
{
    private:
        int dim, num; // размерность и номер объекта
        double* b; // компаненты вектора
        static int count; // количество объектов, созданных программой
    public:
        // Конструктор
        vect( int d )
        {
            dim = d;
            b = new double[dim]{};
            
            /*for ( int i = 0; i < dim; i++ )
                b[i] = 0.0; */

            count ++;
            num = count;
            
            cout << "Вектор №" << num << " создан. Размерность вектора: " << dim << endl;
        }
        
        // Деструктор
        /*~vect()
        {
            cout << "Вектор №" << num << " уничтожен" << endl;
            delete[] b;
        }*/

        // Оператор присваивания (=)
        vect operator=(const vect& v)
        {
            // Проверка на совпадение 
            if (this == &v)
                return *this; 
            
            // Если другая размерность
            if (dim != v.dim)
            {
                delete[] b;
                dim = v.dim;
                b = new double[dim];
            }
            
            // Присвоение
            for ( int i = 0; i < dim; i++ )
                b[i] = v.b[i];
            
            cout << "Вектору №" << num << " присвоено значение вектора №" << v.num << endl;
            
            return *this;
        }
        
        // Оператор сложения (v+v)
        vect operator+(const vect& v)
        {
            vect res(dim); // Вектор, где хранится результат
            
            // Сложение
            for ( int i = 0; i < dim; i++ )
                res.b[i] = b[i] + v.b[i];

            cout << "Вектора №" << num << " и №" << v.num << " успешно сложены" << endl;
            
            return res;
        }
        
        // Оператор вычитания (v-v)
        vect operator-(const vect& v)
        {
            vect res(dim); // Вектор, где хранится результат
            
            // Вычитание
            for ( int i = 0; i < dim; i++ )
                res.b[i] = b[i] - v.b[i];

            cout << "Вектор №" << v.num << " успешно вычтен из вектора №" << num << endl;
            
            return res;
        }
        
        // Оператор противоположирования (мое авторское слово) (-v)
        vect operator-() const
        {
            vect res(dim); // Вектор, где хранится результат
            
            // Противоположирование
            for ( int i = 0; i < dim; i++ )
                res.b[i] = -b[i];

            cout << "Вектор №" << num << " успешно противоположился (как это называется:( )" << endl;
            
            return res;
        }
        
        // Оператор умножения вектора на вектор (v*v)
        double operator*(const vect& v) const
        {
            double res = 0.0; // Результат

            // Умножение
            for ( int i = 0; i < dim; i++ )
                res += b[i] * v.b[i];

            cout << "Вектор №" << num << " вектор №" << v.num << " успешно перемножены" << endl;
            
            return res;
        }
        
        // Оператор умножения вектора на число (v*k)
        vect operator*(double k) const
        {
            vect res(dim); // вектор, где хранятся результаты
            
            // Умножение
            for ( int i = 0; i < dim; i++ )
                res.b[i] = b[i] * k;
            
            cout << "Вектор №" << num << " успешно умножен на " << k << endl;
            
            return res;
        }
        
        // Умножение числа на вектор (k*v)
        friend vect operator*(double k, const vect& v)
        {
            cout << "Вектор №" << v.num << " успешно умножен на " << k << endl;
            return v * k;
        }
        
        friend ostream& operator<<(ostream& os, const vect& v)
        {
            os << "Вектор №" << v.num << "\n[";
            for ( int i = 0; i < v.dim; i++ )
            {
                if ( i > 0 ) os << ", ";
                os << v.b[i];
            }
            os << "]";
            return os;
        }
        
        friend class matr;
};

int vect::count = 0;

class matr
{
    private:
        int dim, num; // размерность матрицы и номер объекта
        double* a; // компаненты матрицы
        static int count; // количество объектов, созданных программой
    public:
        // Конструктор
        matr( int d )
        {
            dim = d;
            a = new double[dim*dim]{};

            count ++;
            num = count;
            
            cout << "Матрица №" << num << " создана. Размерность матрицы: " << dim << "*" << dim << endl;
        }
        
        // Деструктор
        ~matr()
        {
            cout << "Матрица №" << num << " уничтожена" << endl;
            delete[] a;
        }

        // Оператор присваивания (=)
        matr& operator=(const matr& m)
        {
            // Проверка на совпадение 
            if (this == &m)
                return *this; 
            
            // Если другая размерность
            if (dim != m.dim)
            {
                delete[] a;
                dim = m.dim;
                a = new double[dim*dim];
            }
            
            // Присвоение
            for ( int i = 0; i < dim*dim; i++ )
                a[i] = m.a[i];
            
            cout << "Матрице №" << num << " присвоено значение матрицы №" << m.num << endl;
            
            return *this;
        }
        
        // Оператор сложения (m+m)
        matr& operator+(const matr& m)
        {
            matr res(dim); // Матрица, где хранится результат
            
            // Сложение
            for ( int i = 0; i < dim*dim; i++ )
                res.a[i] = a[i] + m.a[i];

            cout << "Матрицы №" << num << " и №" << m.num << " успешно сложены" << endl;
            
            return res;
        }
        
        // Оператор вычитания (m-m)
        matr& operator-(const matr& m)
        {
            matr res(dim); // Матрица, где хранится результат
            
            // Вычитание
            for ( int i = 0; i < dim*dim; i++ )
                res.a[i] = a[i] - m.a[i];

            cout << "Матрица №" << m.num << " успешно вычтена из матрицы №" << num << endl;
            
            return res;
        }
        
        // Оператор противоположирования (мое авторское слово) (-m)
        matr& operator-() const
        {
            matr res(dim); // Матрица, где хранится результат
            
            // Противоположирование
            for ( int i = 0; i < dim*dim; i++ )
                res.a[i] = -a[i];

            cout << "Матрица №" << num << " успешно противоположилась (как это называется >:0 )" << endl;
            
            return res;
        }
        
        // Оператор умножения матрицы на матрицу (m*m)
        matr& operator*(const matr& m) const
        {
            matr res(dim); // Матрица, где хранится результат
            
            // Умножение
            for ( int i = 0; i < dim; i++ )
                for (int j = 0; j < dim; j++ )
                {
                    double sum = 0;
                    for ( int k = 0; k < dim; k++ )
                        sum += a[i*dim + k] * m.a[k*dim + j];
                    res.a[i*dim + j] = sum;
                }

            cout << "Матрица №" << num << " и матрица №" << m.num << " успешно перемножены" << endl;
            
            return res;
        }
        
        // Оператор умножения матрицы на число (v*k)
        matr& operator*(double k) const
        {
            matr res(dim); // матрица, где хранятся результаты
            
            // Умножение
            for ( int i = 0; i < dim*dim; i++ )
                res.a[i] = k * a[i];
            
            cout << "Матрица №" << num << " успешно умножена на " << k << endl;
            
            return res;
        }
        
        // Умножение числа на матрицу (k*m)
        friend matr operator*(double k, const matr& m)
        {
            cout << "Матрица №" << m.num << " успешно умножена на " << k << endl;
            return m * k;
        }
        
        vect operator*(const vect& v) const {
            cout << "Умножение матрицы №" << num << " на вектор №" << v.num << endl;
            vect res(dim);
            for (int i = 0; i < dim; i++)
            {
                double sum = 0;
                for (int j = 0; j < dim; j++)
                    sum += a[i * dim + j] * v.b[j];
                res.b[i] = sum;
            }
            return res;
        }
};

int matr::count = 0;

/*int main()
{
    vect v1(3), v2(3);
    vect v3(3), v4(3), v5(3), v6(3);

    v3 = v1 + v2;
    cout << v3 << endl;

    v4 = v1 - v2;
    cout << v4 << endl;
    
    v5 = -v1;
    cout << v5 << endl;
    
    double mult = v1 * v2;
    cout << mult << endl;
    
    v6 = 3.5 * v1;
    cout << v6 << endl;
    
    return 0;
} */

int main() {
    vect v1(3), v2(3);
    
    // Заполнение векторов
    vect v3 = v1 + v2;
    double dot = v1 * v2;
    vect v4 = -v1;
    vect v5 = 2.5 * v1;
    
    cout << "v1: " << v1 << std::endl;
    cout << "v2: " << v2 << std::endl;
    cout << "v1 + v2: " << v3 << std::endl;
    cout << "Скалярное произведение: " << dot << std::endl;
    //cout << "-v1: " << v4 << std::endl;
    cout << "2.5 * v1: " << v5 << std::endl;
    
    return 0;
}
