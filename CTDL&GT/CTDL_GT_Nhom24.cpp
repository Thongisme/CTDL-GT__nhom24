#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Tangent Numbers
void TanggentNumbers(int n, int arr[])
{

    arr[1] = 1;
    int A[100];
    int m = 1;
    for (int k = 2; k <= n; k++)
    {
        arr[k] = (k - 1) * arr[k - 1];
    }
    for (int k = 2; k <= n; k++)
    {
        for (int j = k; j <= n; j++)
        {
            arr[j] = (j - k) * arr[j - 1] + (j - k + 2) * arr[j];

        }
    }
    for (int i = 1; i < n; i++)
    {
        A[m] = arr[i];
        cout << "T(" << right << setw(1) << m << ") = ";
        cout << right << setw(44) << A[m] << " " << endl;
        m += 2;
    }
}

// Ham tinh C(k,n)
int ToHop(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return (ToHop(n - 1, k - 1) + ToHop(n - 1, k));
}


// Bernoulli Numbers
float Bernoulli(int n)
{
    if (n == 0)
        return 1;
    else
    {
        float t = 1;
        for (int i = 0; i < n; i++)
            t += ToHop(n, i) * Bernoulli(i) / (n - i + 1);
        return float(1 - t);
    }
}

void TBernoulli()
{
    for (size_t n = 0; n <= 15; n += n >= 2 ? 2 : 1)
    {

        cout << "B(" << right << setw(1) << n << ") = ";
        cout << right << setw(44) << Bernoulli(n) << endl;
    }
}


// Eulers Numbers
int EulerNumbers(int  n)
{
    if (n == 0)
        return 1;
    else
    {
        float t = 0;
        for (int i = 0; i < n; i++)
            t += ToHop(n, i) * EulerNumbers(i) * pow(2, (n - i - 1));
        return float(1 - t);
    }
}
void TEulerNumbers()
{
    for (int n = 0; n < 14; n++)
    {
        if (EulerNumbers(n) != 0)
        {
            cout << "E(" << right << setw(1) << n << ") = ";
            cout << right << setw(44) << abs(EulerNumbers(n)) << endl;
        }
    }
} 


int main()
{
    //Tangent Number
    cout << "Tangent Number \n";
    int arr[100];
    TanggentNumbers(8, arr);
    cout << endl;
    
    //Bernoulli Number
    cout << "Bernoulli Number \n";
    TBernoulli();
    cout << endl;

    //Euler Number
    cout << "Euler Number \n";
    TEulerNumbers();
    return 1;
}
