#include <bits/stdc++.h>


using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    long z(0);
    cin >>n;
    while (n){
        n /= 5;
        z+=n;
    }
    cout <<z<<"\n";


}