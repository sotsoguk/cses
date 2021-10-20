#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<long> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int lo(0), hi(n - 1), result(0);
    while (lo <= hi)
    {
        // pair heaviest with lightest child
        if (lo == hi)
        {
            result++;
            break;
        }
        else
        {
            if (p[lo] + p[hi] > x)
            {
                hi--;
                result++;
            }
            else
            {
                result++;
                hi--;
                lo++;
            }
        }
    }
        cout << result << endl;
    }