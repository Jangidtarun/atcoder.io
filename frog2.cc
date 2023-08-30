#include <bits/stdc++.h>
using namespace std;

int mcost(int n, int k, vector<int> &h, vector<int> &cost)
{
    if (n == 1)
        return 0;
    if (cost[n] != -1)
        return cost[n];
    int mincost = INT_MAX;
    int tmpk = n - k > 0 ? k : n - 1;
    for (int i = 1; i <= tmpk; i++)
        mincost = min(mcost(n - i, k, h, cost) + abs(h[n] - h[n - i]), mincost);
    return cost[n] = mincost;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n + 1), cost(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    cout << mcost(n, k, h, cost) << endl;
}