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
    vector<tuple<long,long>> pf;
    for (int i=0;i<n;i++) {
        long p,nr;
        cin >>p >> nr;
        pf.push_back(make_tuple(p,nr));
    }
    long sum(1);
    long sum2(1);
    long prod(1);
    long number(1);
    long pp2(1);
    for (auto [p,nr]: pf){
        
        sum *= (nr+1);
        pp2 = expmod(pp2,nr+1,mod) * expmod(expmod(p,(nr*(nr+1))/2,mod),sum2,mod) % mod;
        sum2 *= (nr+1);
        prod *= (expmod(p,nr+1,mod)-1) % mod * expmod(p-1,mod-2,mod) % mod;
        prod %= mod;
        sum %= mod;
        sum2 %= (mod-1);
        number *= expmod(p,nr,mod);
        number %= mod;
        
        // cout << "!"<<nr<<","<<sum<<endl;
    }
    
    cout << sum<<" "<<prod<<" "<<pp2<<endl;
    
}