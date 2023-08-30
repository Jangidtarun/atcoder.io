#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int W = 1e5 + 5;
const int V = 1e9 + 10;
long long dp[N][W];
int w[N], v[N];

long long f(int index, int currentw)
{
    if (index < 0)
        return 0;
    if (currentw == 0)
        return 0;
    
    if (dp[index][currentw] != -1)
        return dp[index][currentw];

    long long ans = f(index - 1, currentw);
    if (currentw - w[index] >= 0)
        ans = max(ans, f(index - 1, currentw - w[index]) + v[index]);
    return dp[index][currentw] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, wmax;
    cin >> n >> wmax;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    long long ans = 0;
    ans = f(n - 1, wmax);
    cout << ans << endl;
}