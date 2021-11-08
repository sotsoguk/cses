#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n,tmp,result(1);
    cin >> n;
    vector<long> idx(n+1);
    for (int i=0;i<n;i++) {
        cin>>tmp;
        idx[tmp] =i;
    }
    
    for (int i=2;i<=n;i++){
        if (idx[i] < idx[i-1]) result++;
    }
    cout << result <<endl;
}