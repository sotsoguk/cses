#include <bits/stdc++.h>

using namespace std;

#define ld long double
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin >>n>>a>>b;
    
    vector<vector<ld>> dp(n+1,vector<ld>(6*n+1,0));
    
    dp[0][0] = 1.0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=6*n;j++){
            for (int k=1;k<=6;k++){
                if (j>=k){
                    dp[i][j] += dp[i-1][j-k];
                }
            }
            dp[i][j] /= 6.0;
        }
    }
    ld result(0);
    for (int i=a;i<=b;i++) result += dp[n][i];
    cout << fixed<<setprecision(6)<< result<<endl;
    
}