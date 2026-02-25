#include "Matrix.h"
#include <iostream>
using namespace std;

bool Matrix::Init(int r, int c)
{
    if (r > 0 && r <= 10 && c > 0 && c <= 10)
    {
        R = r;
        C = c;
        return true;
    }
    return false;
}

void Matrix::Read()
{
    do
    {
        cout << "Input rows: ";
        cin >> R;
        cout << "Input cols: ";
        cin >> C;
    } while (!Init(R, C));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << "m[" << i << "][" << j << "] = ";
            cin >> m[i][j];
        }
    }
}

void Matrix::Display() const
{
    cout << endl;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

int Matrix::GetElement(int i, int j) const
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return m[i][j];
    return 0;
}

Matrix Matrix::Add(const Matrix& other) const
{
    Matrix result;
    result.Init(R, C);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            result.m[i][j] = m[i][j] + other.m[i][j];

    return result;
}

Matrix Matrix::Sub(const Matrix& other) const
{
    Matrix result;
    result.Init(R, C);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            result.m[i][j] = m[i][j] - other.m[i][j];

    return result;
}

Matrix Matrix::Mul(const Matrix& other) const
{
    Matrix result;
    result.Init(R, other.C);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < other.C; j++)
        {
            result.m[i][j] = 0;
            for (int k = 0; k < C; k++)
            {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }

    return result;
}

Matrix Matrix::MulByNumber(int num) const
{
    Matrix result;
    result.Init(R, C);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            result.m[i][j] = m[i][j] * num;

    return result;
}