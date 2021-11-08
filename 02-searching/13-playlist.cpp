#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    cin >> n;
    vector<long> songs(n+1);
    for (int i=1;i<=n;i++) cin>>songs[i];
    map<long,long> lastIndx;
    long i = 1;
    long ans = 0;
    for (long j=1;j<=n;j++){
        i = max(i, lastIndx[songs[j]]+1);
        ans = max(ans,j-i+1);
        lastIndx[songs[j]] = j;
    }
    cout << ans <<endl;
}