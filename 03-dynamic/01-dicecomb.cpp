#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long n;
    cin >>n;
    long mod = pow(10,9)+7;
    vector<long> combs(n+1,0);
    combs[0] = 1;
    for (long i=1;i<=n;i++) {
        
        for (int j=1;j<=6;j++){
            if ( (i-j) >=0) {
                combs[i] += combs[i-j];
            }            
        }
        combs[i] %= mod;
        

    }
    cout << combs[n] <<"\n";
}