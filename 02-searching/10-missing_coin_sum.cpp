#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    cin >> n;
    vector<long> coins(n);
    vector<long> dp(n+1);
    for (int i=0;i<n;i++) cin>>coins[i];
    sort(coins.begin(),coins.end());
    dp[0] = 1;
    for (int i=1;i<=n; i++) {
        if (dp[i-1] < coins[i-1]) {
            cout << dp[i-1]<<endl;
            return 0 ;
        }
        dp[i] = dp[i-1] + coins[i-1];
    }
    cout << dp[n] << endl;
    

}