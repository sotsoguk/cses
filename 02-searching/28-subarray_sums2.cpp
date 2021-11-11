#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long x, n;

    cin >> n >> x;
    vector<long> array(n, 0);
    for (int i = 0; i < n; i++)
        cin >> array[i];
    long long result(0), prefix_sum(0);
    map<long long, int> seen;
    seen[0] = 1;
    // long long result(0);
    for (auto i : array)
    {
        prefix_sum += i;
        result += seen[prefix_sum - x];
        seen[prefix_sum]++;
    }
    cout << result << endl;
}
