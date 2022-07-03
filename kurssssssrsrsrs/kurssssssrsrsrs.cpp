#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <clocale>
#include <ctime>

using namespace std;

int myfunction(double i, double j) { return (i < j); }

class Matrix
{
private:
    
    double** mas;

public:

    double* operator [](int i) 
    {
        return mas[i];
    }

    double Second(double* mas, int num)
    {
        double a = 0.0;
        double t = 0.0;
        for (int i = 0, j = 0; i < num; i++) {
            if (((i + 1) % 2) == 0) {
                if (mas[i] >= 0) {
                    t = mas[i];
                    a = t + a;
                }
            }
        }
        return a;
    }

    void Third(double* mas, int k, int num)
    {
        cout << "до" << endl;
        int g;
        g = num;
        num = k;
        k = g;
        Fourth(mas, num);
        cout << "после" << endl;
        double* mas2 = new double[k];
        int c = 0;
        int m = 0;

        for (int i = 0; i < num; i++)
        {
            m += 1;
            if (m > (num - k)) {
                mas2[c] = mas[i];
                c++;
            }

        }

        int ff = k - 1;
        m = 0;
        c = 0;
        for (int i = 0; i < num; i++)
        {
            m += 1;
            if (m > (num - k)) {
                mas[i] = mas2[ff];
                ff--;
            }

        }

        for (int i = 0; i < num; i++)
        {
            cout << mas[i] << "  ";

        }
        cout << endl;

    }

    void Fourth(double* mas, int num)
    {
        for (int i = 0; i < num; i++) {
            cout << mas[i] << "   ";
        }
        cout << endl;
    }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    double Rand();
    Matrix res;
    double viv;
    int num = 0; // размер массива
    int choise = 2, choise2 = 0;
    bool choise3 = true;
    double* mas = nullptr;

    cout << "Введите размер массива:";
    cin >> num;

    int k;
    cout << "Введите количество елементов которые надо остортировать:" << endl;
    cin >> k;
    while (k > num || k < 0)
    {
        cout << "Так нельзя!" << endl;
        cout << "Введите число не выходящее за границы количества символов в массиве:" << endl;
        cin >> k;
    }

    clock_t start, end;
    start = clock();

    mas = new double[num]; // Выделение памяти для массива
    for (int i = 0; i < num; i++) // Заполнение массива и вывод значений его элементов
    {
         mas[i] = (round(Rand() * 1000.0) / 1000.0);
         cout << mas[i] << "   ";

    }
    cout << endl;

    viv = res.Second(mas, num);
    cout << "Сумма положительных элементов с парными индексами: " << viv << endl;

    res.Third(mas, num, k);

    delete[] mas; // очистка памяти
    end = clock();
    double b;
    b = (double)end - start;
    b = b / 1000;
    cout << "Время выполнения программы:" << b;
    return 0;

}
double Rand()
{
    double min = -10.009;// Левая граница нужного промежутка.
    double range = 20.018;// Разница между минимумом и максимумом
    return(double)rand() / RAND_MAX * range + min;
}

