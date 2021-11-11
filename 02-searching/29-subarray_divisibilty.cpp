#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long x, n, tmp;
    long result(0);
    cin >> n;
    vector<long> array(n, 0);
    for (int i = 0; i < n; i++)
        cin >> array[i];
    long long currsum(0);
    vector<long> mods(n, 0);
    mods[0] = 1;
    for (auto i : array)
    {
        currsum = (((currsum + i) % n) + n) % n;
        mods[currsum]++;
    }
    for (int i = 0; i < n; i++)
    {
        result += (mods[i] * (mods[i]-1)) / 2;
    }
    cout << result << endl;
}
