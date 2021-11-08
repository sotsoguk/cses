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
// long fact_mod(long n, long k, long mod, const vector<long> &facs,const vector<long> &invs){
//     long num(1), denom(1);
//     //for (int i=n;i>n-k;i--) num = (num*i) % mod;
//     //for (int i=1;i<=k;i++) denom = (denom * i) %mod;
//     num = facs[n];
//     denom = (facs[k] * facs[n-k]) % mod;
//     // return (num * expmod(denom,mod-2,mod) % mod);
    
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long mod = 1e9 +7;
    int n;
    cin >> n;
    if (n==0){
        cout <<1<<endl;
        return 1;
    }
    if (n==1){
        cout <<1<<endl;
        return 0;
    }
    vector<long> subfac(n+1,0);
    subfac[0] = 1;
    for (int i=2;i<=n;i++){
        subfac[i] += (subfac[i-2] + subfac[i-1]) % mod;
        subfac[i] %= mod;
        subfac[i] *= (i-1);
        subfac[i] %= mod;
    }
    
    cout << subfac[n] << endl;
    
}