#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    cin >> n;
    
    if (n%4==0 || n%4 == 3) {
        vector<long> set1,set2;
        long k(1);
        if (n%4 == 3){
            set1.push_back(1);
            set1.push_back(2);
            set2.push_back(3);
            k = 4;
        }
        for (k;k<n;k+=4){
            set1.push_back(k);
            set1.push_back(k+3);
            set2.push_back(k+2);
            set2.push_back(k+1);
        }
        cout <<"YES\n";
        cout <<set1.size()<<"\n";
        for (auto i:set1)
            cout <<i<<" ";
        cout <<"\n";
        cout <<set2.size()<<"\n";
        for (auto i:set2)
            cout <<i<<" ";
        cout <<"\n";

    }
    else {
        cout <<"NO\n";
    }

}