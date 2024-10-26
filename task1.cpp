#include <bits/stdc++.h>
using namespace std;
#define yes cout << "YES"
#define no cout << "NO"
#define ll long long
#define fr(n) for (ll i = 0; i < n; ++i)
#define frj(n) for (ll j = 0; j < n; ++j)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define exit return 0;


/*--------- start of recursive fibonacci implementation ---------- */

long long fibonacci_recursive(long long n)
{
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

/*--------- end of recursive fibonacci implementation ---------- */

/*---------------------------------------------------------------------------------*/

/*------ start of matrix multiplication fibonacci implementation ---- */

void multiply_matrix(long long F[2][2], long long M[2][2])
{
    long long a = (F[0][0] * M[0][0] + F[0][1] * M[1][0]);
    long long b = (F[0][0] * M[0][1] + F[0][1] * M[1][1]);
    long long c = (F[1][0] * M[0][0] + F[1][1] * M[1][0]);
    long long d = (F[1][0] * M[0][1] + F[1][1] * M[1][1]);

    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}
void matrix_power(long long F[2][2], long long n)
{
    if (n == 0 || n == 1)
        return;

    long long M[2][2] = {{1, 1}, {1, 0}};

    matrix_power(F, n / 2);
    multiply_matrix(F, F);

    if (n % 2 != 0)
    {
        multiply_matrix(F, M);
    }
}

long long fibonacci_matrix_mult(long long n)
{
    if (n == 0)
        return 0;

    long long F[2][2] = {{1, 1}, {1, 0}};
    matrix_power(F, n - 1);

    return F[0][0];
}

/*--------- end of matrix multiplication fibonacci implementation ---------- */

/*---------------------------------------------------------------------------------*/

/*------ start of dynamic programming fibonacci implementation ---- */

const int N = 2e6 + 10;
vector<long long> mem(N, -1);

long long fibonacci_dp(long long n)
{
    if (n <= 1)
        return n;
    if (mem[n] != -1)
        return mem[n];
    return mem[n] = fibonacci_dp(n - 1) + fibonacci_dp(n - 2);
}

/*------ end of dynamic programming fibonacci implementation ---- */

int main()
{
    cout << "Welcome To Fiboncci Series Calculator\n\n";
    int n;
    while (true)
    {
        cout << "Chose Which Function Would you like to use\n\nEnter A Number From 1 to 4\n\n1-Recursive Fibonacci\n\n2-Matrix Multiplication Fiboncci\n\n3-DP Fibonacci\n\n4-exit\n\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter The Number You Would Like To Calculate Recursive Fibonacci For\n";
            cin >> n;
            cout << "fibonacci for number " << n << " is " << fibonacci_matrix_mult(n) << "\n\n-----------------------------------------\n";
            break;
        case 2:
            cout << "Enter The Number You Would Like To Calculate Matrix Multiplication Fibonacci For\n";
            cin >> n;
            cout << "fibonacci for number " << n << " is " << fibonacci_matrix_mult(n) << "\n\n-----------------------------------------\n";
            break;
        case 3:
            cout << "Enter The Number You Would Like To Calculate DP Fibonacci For\n";
            cin >> n;
            cout << "fibonacci for number " << n << " is " << fibonacci_matrix_mult(n) << "\n\n-----------------------------------------\n";
            break;

        default:
            return 0;
            break;
        }
    }
}
