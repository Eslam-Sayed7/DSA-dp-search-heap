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

void mekkawy()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

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

void solve()
{
    cout << fibonacci_dp(9);
}

int main()
{
    mekkawy();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
