#include <bits/stdc++.h>

using namespace std;
vector<long> facs(1e6+1);
vector<long> invs(1e6+1);

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
long f_mod(long n, long mod) {
    long result = 1;
    for (long i=1;i<=n;i++){
        result *= i;
        result %= mod;
    }
    return result;
}
long inv_mod(long n, long mod){
    return expmod(n,mod-2,mod) % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n,k;
    long mod = 1e9+7;
    
    cin >> n>>k;
    // long f_nk1 =  f_mod(n+k-1,mod);
    // long f_k = f_mod(k,mod);
    // long f_n1 = f_mod(n-1,mod);
    long f_nk1(1),f_k(1),f_n1(1);
    for (long i=1;i<=n+k-1;i++){
        f_nk1 *= i;
        f_nk1 %= mod;
        if (i==k) f_k = f_nk1;
        if (i==n-1) f_n1 = f_nk1;
    }


    long result = ((f_nk1 * inv_mod(f_k,mod))%mod)*inv_mod(f_n1,mod) % mod;
    cout << result << endl;
    
    
}