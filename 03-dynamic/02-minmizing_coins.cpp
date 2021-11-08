#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, target;
    cin >>n >> target;
    vector<int> coins(n,0);
    for (int &c:coins) cin >>c;

    vector<long> dp(target+1,1e9);
    dp[0] = 0;
    for (int i=1;i<=target;i++) {
        for (int j=0;j<n;j++) {
            if (i-coins[j] >= 0) {
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    if (dp[target] == 1e9) {
        cout << -1 <<endl;

    }
    else {
        cout << dp[target] << endl;
    }
}