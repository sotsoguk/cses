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
    long n,m;
    long mod = 1e9+7;
    cin >> n >> m;
    long result(0);
    for (long i=0;i<n;i++) {
        result += expmod(m,__gcd(i,n),mod);
        result %= mod;
    }
    result *= expmod(n,mod-2,mod);
    result %= mod;
    cout <<result<<endl;
}