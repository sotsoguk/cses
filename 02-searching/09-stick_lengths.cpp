#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long result(0);
    cin >> n;
    vector<long> sticks(n);
    for (int i=0;i<n;i++) cin>>sticks[i];
    sort(sticks.begin(), sticks.end());
    long target = sticks[n/2];
    for (auto i:sticks)
        result += abs(target - i);
    cout << result<<endl;
}