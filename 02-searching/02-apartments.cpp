#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k, result(0), mi(0), ni(0);

    cin >> n >> m >> k;
    vector<long> apartments(m);
    vector<long> applic(n);
    for (int i = 0; i < n; i++)
    {
        cin >> applic[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> apartments[i];
    }
    sort(applic.begin(), applic.end());
    sort(apartments.begin(), apartments.end());

    while (ni < n && mi < m)
    {
        // 1. case apartment too big, step one applicant
        if (apartments[mi] > (applic[ni] + k))
        {
            ni++;
        }
        // 2. case apartment to small, step one apartment 
        else if (apartments[mi] < (applic[ni] - k))
        {
            mi++;
        }
        else // apartment fits
        {
            mi++;
            ni++;
            result++;
        }
    }
    cout << result << endl;
}