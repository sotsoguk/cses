#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // cin >> i;
    int n,x,xx;
    cin >> n;
    for (int i=1;i<= n;i++)
        xx ^= i;
    for (int i=0;i< n-1;i++){
        cin >> x;
        xx ^= x;
    }
    cout <<xx<<"\n";
}