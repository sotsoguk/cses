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
long inverse(long n, long mod) {
    return expmod(n,mod-2,mod);
    // if (n == 1) return 1;
    // return (mod - ((mod/n)*inverse(mod%n,mod))%mod+mod)%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    long mod = 1e9+7;
    cin >> n;
    if (n%2 == 1) {
        cout <<0<<endl;
        return 0;
    }
    n /= 2;
    // Catalan Number
    long result(0);
    long f_2n(1), f_n(1);
    for (long i =1;i<=2*n;i++) {
        f_2n *= i;
        f_2n %= mod;
    }
    for (long i=1;i<=n;i++){
        f_n *= i;
        f_n %= mod;
    }
    result = (f_2n * inverse(f_n,mod)) % mod;
    result *= (inverse(f_n,mod)*inverse(n+1,mod)) % mod;
    result %= mod;
    cout << result << endl;
    
}