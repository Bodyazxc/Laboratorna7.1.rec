#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int row = 0, int col = 0);
void Print(int** a, const int rowCount, const int colCount, int row = 0, int col = 0);
void Change(int** a, const int row1, const int row2, const int colCount, int col = 0);
void Sort(int** a, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int row = 0, int col = 0);

int main() {
    srand((unsigned)time(NULL));
    int Low = -41;
    int High = 23;
    int rowCount = 7;
    int colCount = 9;
    int** T = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        T[i] = new int[colCount];

    Create(T, rowCount, colCount, Low, High);
    cout << "" << endl;
    Print(T, rowCount, colCount);

    Sort(T, rowCount, colCount);
    cout << "" << endl;
    Print(T, rowCount, colCount);

    int S = 0;
    int k = 0;
    Calc(T, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "" << endl;
    Print(T, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] T[i];
    delete[] T;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int row, int col) 
{
    if (row >= rowCount) return;
    if (col >= colCount) 
    {
        Create(a, rowCount, colCount, Low, High, row + 1, 0);
        return;
    }
    a[row][col] = Low + rand() % (High - Low + 1);
    Create(a, rowCount, colCount, Low, High, row, col + 1);
}

void Print(int** a, const int rowCount, const int colCount, int row, int col) 
{
    if (row >= rowCount) return;
    if (col >= colCount) 
    {
        cout << endl;
        Print(a, rowCount, colCount, row + 1, 0);
        return;
    }
    cout << setw(4) << a[row][col];
    Print(a, rowCount, colCount, row, col + 1);
}

void Change(int** a, const int row1, const int row2, const int colCount, int col) 
{
    if (col >= colCount) return;
    int tmp = a[row1][col];
    a[row1][col] = a[row2][col];
    a[row2][col] = tmp;
    Change(a, row1, row2, colCount, col + 1);
}

void Sort(int** a, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 >= rowCount - 1) return;
    if (i1 >= rowCount - i0 - 1)
    {
        Sort(a, rowCount, colCount, i0 + 1, 0);
        return;
    }

    if ((a[i1][0] > a[i1 + 1][0]) ||
        (a[i1][0] == a[i1 + 1][0] && a[i1][1] > a[i1 + 1][1]) ||
        (a[i1][0] == a[i1 + 1][0] && a[i1][1] == a[i1 + 1][1] && a[i1][2] < a[i1 + 1][2]))
    {
        Change(a, i1, i1 + 1, colCount);
    }

    Sort(a, rowCount, colCount, i0, i1 + 1);
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int row, int col)
{
    if (row >= rowCount)
        return;
    if (col >= colCount)
    {
        Calc(a, rowCount, colCount, S, k, row + 1, 0);
        return;
    }
    if (a[row][col] % 2 == 0 && !(a[row][col] > 0 && (row % 2 == 1 || col % 2 == 1)))
    {
        S += a[row][col];
        k++;
        a[row][col] = 0;
    }
    Calc(a, rowCount, colCount, S, k, row, col + 1);
}
