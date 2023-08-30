#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int W = 1e9 + 5;
const int V = 1e5 + 5;
long long dp[N][V];
int w[N], v[N];

long long f(int ind, int value)
{
    if (value == 0)
        return 0;
    if (ind < 0)
        return 1e15;
    if (dp[ind][value] != -1)
        return dp[ind][value];

    long long ans = f(ind - 1, value);
    if (value - v[ind] >= 0)
        ans = min(ans, f(ind - 1, value - v[ind]) + w[ind]);
    return dp[ind][value] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, wmax;
    cin >> n >> wmax;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    int maxvalue = 1e5;
    for (int i = maxvalue; i >= 0; i--)
    {
        if (f(n - 1, i) <= wmax)
        {
            cout << i << endl;
            break;
        }
    }
}