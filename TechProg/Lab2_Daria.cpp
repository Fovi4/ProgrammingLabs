#include <iostream>
using namespace std; //ну куда же без этого

class vect 
{
private:
    int dim; //размерность нашего вектора
    double* b; //тут будут числа
    int num; //номерок
    static int count; //считаем сколько наворотили векторов

public:
    vect(int d) //конструктор, делаем новый векторчик
    {
        cout << "создаю вектор №" << count+1 << endl; //отчитываемся
        dim = d; //запоминаем размер
        b = new double[dim]{}; //выделяем память
        count++; //щелкаем счетчик
        num = count; //присваиваем номер
        cout << "вектор №" << num << " готов к работе!" << endl; //доложили о выполнении
    }

    ~vect() //деструктор, прибираем за собой
    {
        cout << "удаляю вектор №" << num << ", прощай!" << endl; //попрощались
        delete[] b; //освободили память
        cout << "память вектора №" << num << " успешно освобождена" << endl; //доложили
    }

    void fill(double* values) //заполняем значениями
    {
        cout << "заполняю вектор №" << num << " данными..." << endl; //начали процесс
        for (int i = 0; i < dim; i++)
            b[i] = values[i]; //по одному заполняем
        cout << "вектор №" << num << " успешно заполнен" << endl; //завершили
    }

    vect operator=(const vect& v) //присваивание одного вектора другому
    {
        cout << "выполняю присваивание для векторов..." << endl; //начало операции
        
        if (dim != v.dim) {
            cout << "размерности разные, пересоздаю вектор..." << endl; //информация
            delete[] b;
            dim = v.dim;
            b = new double[dim];
        }
        
        cout << "копирую данные..." << endl; //процесс пошел
        for (int i = 0; i < dim; i++)
            b[i] = v.b[i];
        
        cout << "присваивание завершено успешно!" << endl; //все ок
        return *this;
    }

    vect operator+(const vect& v) //сложение векторов
    {
        cout << "складываю векторы №" << num << " и №" << v.num << endl; //начало
        vect result(dim); //временный вектор
        
        for (int i = 0; i < dim; i++) {
            result.b[i] = b[i] + v.b[i];
            cout << "элемент " << i << ": " << b[i] << " + " << v.b[i] 
                 << " = " << result.b[i] << endl; //отчет по каждому
        }
        
        cout << "сложение завершено" << endl; //готово
        return result;
    }

    vect operator-(const vect& v) //вычитание векторов
    {
        cout << "вычитаю вектор №" << v.num << " из вектора №" << num << endl;
        vect result(dim);
        
        for (int i = 0; i < dim; i++) {
            result.b[i] = b[i] - v.b[i];
            cout << "элемент " << i << ": " << b[i] << " - " << v.b[i] 
                 << " = " << result.b[i] << endl;
        }
        
        cout << "вычитание выполнено!" << endl;
        return result;
    }

    vect operator-() const //унарный минус
    {
        cout << "инвертирую вектор №" << num << endl;
        vect result(dim);
        
        for (int i = 0; i < dim; i++) {
            result.b[i] = -b[i];
            cout << "элемент " << i << ": " << b[i] << " -> " << result.b[i] << endl;
        }
        
        cout << "инверсия завершена" << endl;
        return result;
    }

    double operator*(const vect& v) const //умножение векторов
    {
        cout << "вычисляю произведение векторов №" << num << " и №" << v.num << endl;
        double result = 0.0;
        
        for (int i = 0; i < dim; i++) {
            result += b[i] * v.b[i];
            cout << "промежуточный результат: " << result << endl;
        }
        
        cout << "произведение = " << result << endl;
        return result;
    }

    vect operator*(double k) const //умножение на число
    {
        cout << "умножаю вектор №" << num << " на число " << k << endl;
        vect result(dim);
        
        for (int i = 0; i < dim; i++) {
            result.b[i] = b[i] * k;
            cout << "элемент " << i << ": " << b[i] << " * " << k 
                 << " = " << result.b[i] << endl;
        }
        
        cout << "умножение на число выполнено" << endl;
        return result;
    }

    friend vect operator*(double k, const vect& v) //дружественная функция
    {
        cout << "умножаю число " << k << " на вектор №" << v.num << " (дружественная функция)" << endl;
        return v * k;
    }
    
    friend ostream& operator<<(ostream& os, const vect& v) //вывод в поток
    {
        os << "вектор №" << v.num << "\n[";
        for (int i = 0; i < v.dim; i++) {
            if (i > 0) os << ", ";
            os << v.b[i];
        }
        os << "]";
        cout << "\nвывод вектора №" << v.num << " выполнен" << endl;
        return os;
    }
    
    friend class matr; //дружественный класс
};

int vect::count = 0; //обнулили счетчик

class matr 
{
private:
    int dim; //размер матрицы
    double* a; //тут храним элементы
    int num; //порядковый номер
    static int count; //счетчик матриц

public:
    matr(int d) //конструктор матрицы
    {
        cout << "создаю матрицу №" << count+1 << " размером " << d << "x" << d << endl;
        dim = d;
        a = new double[dim*dim]{};
        count++;
        num = count;
        cout << "матрица №" << num << " готова к использованию" << endl;
    }

    ~matr() //деструктор матрицы
    {
        cout << "уничтожаю матрицу №" << num << endl;
        delete[] a;
        cout << "матрица №" << num << " успешно удалена" << endl;
    }

    void fill(double* values) //заполнение матрицы
    {
        cout << "заполняю матрицу №" << num << " значениями..." << endl;
        for (int i = 0; i < dim*dim; i++)
            a[i] = values[i];
        cout << "матрица №" << num << " успешно заполнена" << endl;
    }

    matr operator=(const matr& m) //присваивание
    {
        cout << "выполняю присваивание для матриц..." << endl;
        
        if (this == &m) {
            cout << "это самоприсваивание, пропускаем" << endl;
            return *this;
        }
        
        if (dim != m.dim) {
            cout << "размеры разные, пересоздаю матрицу..." << endl;
            delete[] a;
            dim = m.dim;
            a = new double[dim*dim];
        }
        
        cout << "копирую данные матрицы..." << endl;
        for (int i = 0; i < dim*dim; i++)
            a[i] = m.a[i];
        
        cout << "присваивание матриц завершено" << endl;
        return *this;
    }

    matr operator+(const matr& m) //сложение
    {
        cout << "складываю матрицы №" << num << " и №" << m.num << endl;
        matr result(dim);
        
        for (int i = 0; i < dim*dim; i++) {
            result.a[i] = a[i] + m.a[i];
            cout << "элемент " << i << ": " << a[i] << " + " << m.a[i] 
                 << " = " << result.a[i] << endl;
        }
        
        cout << "сложение матриц выполнено" << endl;
        return result;
    }

    matr operator-(const matr& m) //вычитание
    {
        cout << "вычитаю матрицу №" << m.num << " из матрицы №" << num << endl;
        matr result(dim);
        
        for (int i = 0; i < dim*dim; i++) {
            result.a[i] = a[i] - m.a[i];
            cout << "элемент " << i << ": " << a[i] << " - " << m.a[i] 
                 << " = " << result.a[i] << endl;
        }
        
        cout << "вычитание матриц завершено" << endl;
        return result;
    }

    matr operator-() const //унарный минус
    {
        cout << "инвертирую матрицу №" << num << endl;
        matr result(dim);
        
        for (int i = 0; i < dim*dim; i++) {
            result.a[i] = -a[i];
            cout << "элемент " << i << ": " << a[i] << " -> " << result.a[i] << endl;
        }
        
        cout << "инверсия матрицы выполнена" << endl;
        return result;
    }

    matr operator*(const matr& m) const //умножение матриц
    {
        cout << "умножаю матрицы №" << num << " и №" << m.num << endl;
        matr result(dim);
        
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                double sum = 0;
                for (int k = 0; k < dim; k++) {
                    sum += a[i*dim + k] * m.a[k*dim + j];
                    cout << "промежуточный результат [" << i << "," << j << "]: " << sum << endl;
                }
                result.a[i*dim + j] = sum;
            }
        }
        
        cout << "умножение матриц завершено" << endl;
        return result;
    }

    matr operator*(double k) const //умножение на число
    {
        cout << "умножаю матрицу №" << num << " на число " << k << endl;
        matr result(dim);
        
        for (int i = 0; i < dim*dim; i++) {
            result.a[i] = a[i] * k;
            cout << "элемент " << i << ": " << a[i] << " * " << k 
                 << " = " << result.a[i] << endl;
        }
        
        cout << "умножение матрицы на число выполнено" << endl;
        return result;
    }

    friend matr operator*(double k, const matr& m) //дружественная функция
    {
        cout << "умножаю число " << k << " на матрицу №" << m.num << " (дружественная функция)" << endl;
        return m * k;
    }
    
    vect operator*(const vect& v) const //умножение на вектор
    {
        cout << "умножаю матрицу №" << num << " на вектор №" << v.num << endl;
        vect result(dim);
        
        for (int i = 0; i < dim; i++) {
            double sum = 0;
            for (int j = 0; j < dim; j++) {
                sum += a[i*dim + j] * v.b[j];
                cout << "промежуточный результат [" << i << "]: " << sum << endl;
            }
            result.b[i] = sum;
        }
        
        cout << "умножение матрицы на вектор выполнено" << endl;
        return result;
    }
    
    friend ostream& operator<<(ostream& os, const matr& m) //вывод в поток
    {
        os << "матрица №" << m.num << "\n[";
        for (int i = 0; i < m.dim; i++) {
            if (i > 0) os << ", ";
            os << m.a[i];
        }
        os << "]";
        cout << "\nвывод матрицы №" << m.num << " выполнен" << endl;
        return os;
    }
};

int matr::count = 0; //инициализация счетчика

int main() 
{
    cout << "векторы" << endl;
    vect v1(3), v2(3);
    double a1[3] = {1, 2, 3}, a2[3] = {4, 5, 6};
    
    v1.fill(a1);
    v2.fill(a2);
    
    cout << endl;
    vect v3 = v1 + v2;
    vect v4 = v1 - v2;
    vect v5 = -v1;
    double dot = v1 * v2;
    vect v6 = 2.5 * v1;
    cout << endl;
    
    cout << "матрицы\n";
    matr m1(2), m2(2);
    double data1[] = {1, 2, 3, 4};
    double data2[] = {5, 6, 7, 8};
    
    m1.fill(data1);
    m2.fill(data2);
    
    matr m3 = m1 + m2;
    matr m4 = m1 - m2;
    matr m5 = -m1;
    matr m6 = m1 * m2;
    matr m7 = 3.0 * m1;
    vect v7 = m1 * v1;
    cout << endl;
    
    return 0;
}
