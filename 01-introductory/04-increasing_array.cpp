#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long moves(0);
    long prev_num(0);
    long x;
    int n;
    // cin >> i;
    // int n,x,xx;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x;
        if (x<prev_num){
            moves += (prev_num-x);
        }
        else {
            prev_num = x;
        }
    }
    
    cout <<moves<<"\n";
}