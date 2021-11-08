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
long fact_mod(long n, long k, long mod, const vector<long> &facs,const vector<long> &invs){
    long num(1), denom(1);
    //for (int i=n;i>n-k;i--) num = (num*i) % mod;
    //for (int i=1;i<=k;i++) denom = (denom * i) %mod;
    num = facs[n];
    denom = (facs[k] * facs[n-k]) % mod;
    // return (num * expmod(denom,mod-2,mod) % mod);
    return (num*invs[denom]%mod);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long mod = 1e9+7;
    facs[0] = 1;
    invs[1] = 1;
    for (long i=1;i<=1e6;i++) facs[i] = (facs[i-1] * i) %mod;
    for (long i=2;i<=1e6;i++) invs[i] = mod - (mod/i) * invs[mod%i] % mod;
    cin >> n;
    
    for (int i=0;i<n;i++) {
        long a, b;
        cin >>a >> b;
        cout <<fact_mod(a,b,mod,facs,invs) <<endl;
    }
    
}