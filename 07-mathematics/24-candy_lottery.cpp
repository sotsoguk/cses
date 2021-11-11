#include <bits/stdc++.h>

using namespace std;

#define ld long double
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
   
    long double result = 0.0;
    vector<long double> pows(n+1,0.0);
    for (int i=1;i<=k;i++) {
        long double tmp(1.0);
        for (int j=1;j<=n;j++) {
            tmp *= (long double) i / k;
        }
        pows[i] = tmp;
    }
    for (int i=1;i<=k;i++){
        result += (long double) i* (pows[i]-pows[i-1]);
    }
    cout << fixed<<setprecision(6)<< result<<endl;
    
}