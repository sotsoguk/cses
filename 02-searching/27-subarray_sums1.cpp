#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long x, n, tmp;
    long result(0);
    cin >> n >> x;
    vector<long> array(n, 0);
    for (int i = 0; i < n; i++)
        cin >> array[i];
    int lo(0), hi(1);
    long long subsum = array[0];
    // long long result(0);
    while (lo < n && hi <= n)
    {
        if (subsum == x)
        {
            result++;
            subsum -= array[lo];
            lo++;
        }
        else if (subsum < x)
        {
            subsum += array[hi];
            hi++;
        }
        else
        {
            subsum -= array[lo];
            lo++;
        }
    }
    cout << result << endl;
}
