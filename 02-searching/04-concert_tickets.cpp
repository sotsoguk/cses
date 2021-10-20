#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m(0);
    long tmp(0);
    long p(0);
    cin >> n >> m;
    multiset<long> tickets;
    vector<long> customers(m);
    for (int i=0;i<n;i++){
        cin >> tmp;
        tickets.insert(tmp);

    }
    for (int i=0;i<m;i++) {
        cin >> p;
        auto it = tickets.upper_bound(p);
        if (it == tickets.begin()){
            cout <<"-1\n";
        }else{
            
            cout <<*(--it)<<endl;
            tickets.erase(it);
        }
        
    }
}