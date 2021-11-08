#include <bits/stdc++.h>
using namespace std;
vector<int> digits(long n){
    int num_digits = floor(log10(n))+1;
    vector<int> d(num_digits,0);
    for (int i=0;i<num_digits;i++){
        d[i] = n % 10;
        n /= 10;
    }
    return d;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for (auto c:digits(123949)) cout <<c<<",";
    long n;
    cin >> n;
    

    long mod = 1e9 + 7;
    vector<long> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto d:digits(i)){
            dp[i] = min(dp[i],dp[i-d]+1);
        }
    }
    // for (auto t:dp) {
    //     cout <<t<<",";
    // }
    // cout << endl;
    cout << dp[n]  << endl;
}