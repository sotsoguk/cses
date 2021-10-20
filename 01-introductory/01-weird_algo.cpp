#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long i;
    cin >> i;
    vector<long> numbers{i};
    while (i > 1)
    {
        if (i % 2)
        {
            i = i * 3 + 1;
        }
        else
        {
            i /= 2;
        }
        numbers.push_back(i);
    }
    for (auto n : numbers)
    {
        cout << n << " ";
    }
    cout << "\n";
}