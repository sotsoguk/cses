#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    multiset<long> towers;
    cin >> n;
    vector<long> cubes(n);
    long result(0);
    for (int i=0;i<n;i++) cin>>cubes[i];
    for (long j = 0;j<n;j++) {
        auto it = towers.upper_bound(cubes[j]);
        if (it == towers.end()) towers.insert(cubes[j]);
        else {
            towers.erase(it);
            towers.insert(cubes[j]);
        }
    }
    cout << towers.size() << endl;
}