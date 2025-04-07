#include <iostream>
using namespace std;

class vect
{
    private:
        int dim;
        double* b;
        int num;
        static int count;
    public:
        vect( int d )
        {
            dim = d;
            b = new double[dim]{};
            count ++;
            num = count;
        }
        ~vect()
        {
            delete[] b;
        }
        void fill(double* values)
        {
            for (int i = 0; i < dim; i++)
                b[i] = values[i];
        }
        vect operator=(const vect& v)
        {
            if (this == &v)
                return *this; 
            if (dim != v.dim)
            {
                delete[] b;
                dim = v.dim;
                b = new double[dim];
            }
            for ( int i = 0; i < dim; i++ )
                b[i] = v.b[i];
            return *this;
        }
        vect operator+(const vect& v)
        {
            vect res(dim);
            for ( int i = 0; i < dim; i++ )
                res.b[i] = b[i] + v.b[i];
            return res;
        }
        vect operator-(const vect& v)
        {
            vect res(dim);
            for ( int i = 0; i < dim; i++ )
                res.b[i] = b[i] - v.b[i];
            return res;
        }
        vect operator-() const
        {
            vect res(dim);
            for ( int i = 0; i < dim; i++ )
                res.b[i] = -b[i];
            return res;
        }
        double operator*(const vect& v) const
        {
            double res = 0.0;
            for ( int i = 0; i < dim; i++ )
                res += b[i] * v.b[i];
            return res;
        }
        vect operator*(double k) const
        {
            vect res(dim);
            for ( int i = 0; i < dim; i++ )
                res.b[i] = b[i] * k;
            return res;
        }
        friend vect operator*(double k, const vect& v)
        {
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
        int dim;
        double* a; 
        int num;
        static int count;
    public:
        matr( int d )
        {
            dim = d;
            a = new double[dim*dim]{};

            count ++;
            num = count;
        }
        ~matr()
        {
            delete[] a;
        }
        void fill(double* values)
        {
            for (int i = 0; i < dim*dim; i++)
                a[i] = values[i];
        }
        matr operator=(const matr& m)
        {
            if (this == &m)
                return *this; 
            if (dim != m.dim)
            {
                delete[] a;
                dim = m.dim;
                a = new double[dim*dim];
            }
            for ( int i = 0; i < dim*dim; i++ )
                a[i] = m.a[i];
            return *this;
        }
        matr operator+(const matr& m)
        {
            matr res(dim);
            for ( int i = 0; i < dim*dim; i++ )
                res.a[i] = a[i] + m.a[i];

            cout << "Матрицы №" << num << " и №" << m.num << " успешно сложены" << endl;
            
            return res;
        }
        matr operator-(const matr& m)
        {
            matr res(dim);
            for ( int i = 0; i < dim*dim; i++ )
                res.a[i] = a[i] - m.a[i];
            return res;
        }
        matr operator-() const
        {
            matr res(dim);
            for ( int i = 0; i < dim*dim; i++ )
                res.a[i] = -a[i];
            return res;
        }
        matr operator*(const matr& m) const
        {
            matr res(dim*dim);
            for ( int i = 0; i < dim; i++ )
                for (int j = 0; j < dim; j++ )
                {
                    double sum = 0;
                    for ( int k = 0; k < dim; k++ )
                        sum += a[i*dim + k] * m.a[k*dim + j];
                    res.a[i*dim + j] = sum;
                }
            return res;
        }
        matr operator*(double k) const
        {
            matr res(dim);
            for ( int i = 0; i < dim*dim; i++ )
                res.a[i] = k * a[i];
            return res;
        }
        friend matr operator*(double k, const matr& m)
        {
            return m * k;
        }
        
        vect operator*(const vect& v) const {
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
        
        friend ostream& operator<<(ostream& os, const matr& m)
        {
            os << "Матрица №" << m.num << "\n[";
            for ( int i = 0; i < m.dim; i++ )
            {
                if ( i > 0 ) os << ", ";
                os << m.a[i];
            }
            os << "]";
            return os;
        }
};

int matr::count = 0;

int main()
{
    vect v1(3), v2(3);
    double a1[3] = {1, 2, 3}, a2[3] = {4, 5, 6};
    
    v1.fill(a1);
    v2.fill(a2);
    cout << endl;
    
    cout << v1 << endl << v2 << endl;
    
    cout << endl;
    vect v3 = v1 + v2;
    cout << v3 << endl;
    
    cout << endl;
    double dot = v1 * v2;
    cout << "Результат умножения: " << dot << endl;
    
    cout << endl;
    vect v4 = -v1;
    cout << v4 << endl;
    
    cout << endl;
    vect v5 = 2.5 * v1;
    cout << endl;
    
    // Создаем матрицы 2x2
    matr m1(2), m2(2);
    
    // Данные для заполнения
    double data1[] = {1, 2, 3, 4};
    double data2[] = {5, 6, 7, 8};
    
    // Заполняем матрицы
    m1.fill(data1);
    m2.fill(data2);
    
    cout << m1 << endl;
    cout << m2 << endl;
    
    // Сложение матриц
    matr m3 = m1 + m2;
    cout << "Сумма матриц:\n" << m3 << endl;
    
    // Скалярное произведение
    matr m4 = m1 * m2;
    cout << "Скалярное произведение: " << m4 << endl << endl;
    
    vect v6 = m1 * v1;
    cout << v6 << endl << endl;
    
    return 0;
}
