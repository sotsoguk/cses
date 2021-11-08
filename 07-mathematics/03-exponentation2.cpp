#include <bits/stdc++.h>

using namespace std;

long expmod(long a, long b, long mod){
    long result = 1;
    while (b)
    {
        if (b&1){
            result *= a;
        }
        a*=a;
        a %= mod;
        result %= mod;
        b /= 2;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long mod = 1e9+7;
    cin >> n;
    
    for (int i=0;i<n;i++) {
        long a, b,c;
        cin >>a >> b>>c;
        cout <<expmod(a,expmod(b,c,mod-1),mod) <<endl;
    }
    
}