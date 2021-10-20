#include <bits/stdc++.h>


using namespace std;

typedef long long int lli;

lli powerMod(lli x, lli y, lli mod){
    lli res = 1;
    while (y) {
        if (y%2 == 1){
            res *= x;
        }
        y /=2;
        x *= x;
        x %= mod;
        res %= mod;
    }
    return res % mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    lli mod = pow(10,9) +7;
    cin >> n;
    cout << powerMod(2,n,mod)<<"\n";

}