#include <bits/stdc++.h>


using namespace std;

long long fastpow(long long x, unsigned long long y){
    long long result = 1;
    while (y>0){
        if (y%2 == 1) {
            result *=x;
        }
        x *= x;
        y/= 2;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long k;
    int n;
    cin >> n;
    for (int i=0; i< n;i++){
        cin >> k;
        // compute number of digits
        long long digits = 1;
        while (k > 9*digits*fastpow(10,digits-1)) {
            k -= 9*digits*fastpow(10,digits-1);
            digits += 1 ;
        }
        long long number = (k-1) / digits;
        long long offset = (k-1) % digits;
        long long nn = fastpow(10,digits-1) + number;
     
        cout << to_string(nn)[offset]<<"\n";
    }
}