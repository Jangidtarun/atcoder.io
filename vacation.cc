#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int a[N + 1], b[N + 1], c[N + 1];
int dp[N + 1][4];

int happiness(int day, int pactivity)
{
    if (day == 0)
        return 0;
    if (dp[day][pactivity] != -1)
        return dp[day][pactivity];
    int cost = 0;
    if (pactivity != 0)
        cost = max(cost, happiness(day - 1, 0) + a[day]);
    if (pactivity != 1)
        cost = max(cost, happiness(day - 1, 1) + b[day]);
    if (pactivity != 2)
        cost = max(cost, happiness(day - 1, 2) + c[day]);
    dp[day][pactivity] = cost;
    return cost;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];

    cout << happiness(n, 1) << endl;
}