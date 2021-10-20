#include <bits/stdc++.h>


using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    
    cin >> n;
    // n = 10000;
    long long int p(0);
    cout <<"0\n";
    for (long long  i = 1;i<n;i++){
        p += (8LL+i*(-7+i*(3+(i<<1))));
        // p = (i*i)*(i*i-1)/2-4*(i-1)*(i-2);
        // cout <<1LL*(i*i)*(i*i-1)/2-4*(i-1)*(i-2)<<"\n";
        cout <<p<<"\n";
    }


}