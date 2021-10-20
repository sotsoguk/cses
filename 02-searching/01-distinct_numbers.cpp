#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long xi(0);
    cin >> n;
    set<long> nums;
    for (int i=0;i<n;++i){
        cin >> xi;
        nums.insert(xi);
    }
    cout <<nums.size()<<endl;
}