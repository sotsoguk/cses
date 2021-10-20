#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    // cin >> i;
    cin >> n;
    // special case 1
    if (n==1) {
        cout <<"1\n";
    }
    // even case
    if (n%2 == 0){
        if (n<4) {
            cout << "NO SOLUTION\n";
            return 0;
        }
        for (long i = n-1;i>=1;i-=2) {
            cout <<i<<" ";
        }
        for (long i = n;i>=2;i-=2) {
            cout <<i <<" ";
        }
    }
    // odd case
    else{
        if (n<5){
            cout << "NO SOLUTION\n";
            return 0 ;
        }
        for (long i = n;i>=1;i-=2) {
            cout <<i<<" ";
        }
        for (long i = n-1;i>=2;i-=2) {
            cout <<i <<" ";
        }
    }
    cout <<"\n";
}