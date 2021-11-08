#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;
    vector<int> coins(n, 0);
    for (int &c : coins)
        cin >> c;

    long mod = 1e9 + 7;
    vector<long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] += dp[i - coins[j]];
                dp[i] %= mod;
            }
        }
    }
    // for (auto t:dp) {
    //     cout <<t<<",";
    // }
    // cout << endl;
    cout << dp[target] % mod << endl;
}