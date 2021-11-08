#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long x, n,tmp;
    long result(0);
    cin >> x >> n;
    set<long> lights;
    multiset<long> dist;
    
    lights.insert(0);
    lights.insert(x);
    dist.insert(x);
    for (int i=0;i<n;i++){
        cin >> tmp;
        auto it1 = lights.upper_bound(tmp), it2 = it1;
        --it2;
        dist.erase(dist.find(*it1 - *it2));
        dist.insert(tmp-*it2);
        dist.insert(*it1 - tmp);
        lights.insert(tmp);
        auto ans = dist.end(); --ans;
        cout << *ans<<" ";
    }
    
}
