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
    int lo(0), hi(0);
    multiset<long> seen;
    
    // long long result(0);
    while (hi <n)
    {
        seen.insert(array[hi]);
        for (auto i:seen) {cout <<i <<" ";}
        cout << endl;
        if (seen.size() > x)
        {
            auto it(seen.find(array[lo]));
            if (it != seen.end()) 
                seen.erase(array[lo]);
            lo++;
        }
        result += hi-lo+1;
        cout << lo<<", "<<hi<<": "<<result<<" :\t";
        for (auto i:seen) {cout <<i <<" ";}
        cout << endl;
        hi ++;
    }
    // int lo(0), hi(0);
    // map<long,int> seen;
    // while (hi < n) {
    //     // if (seen.find(array[hi]) == seen.end())
    //     //     seen[array[hi]] = 0;
    //     seen[array[hi]] ++;
    //     while (seen.size() > x) {

    //     }
    // }

    // long count = 0;
 
    // // Left boundary of window
    // long left = 0;
 
    // // Right boundary of window
    // long right = 0;
 
    // // Map to keep track of number of distinct
    // // elements in the current window
    // map<long,long> map;
    // // Loop to calculate the count
    // while (right < n) {
 
    //     // Calculating the frequency of each
    //     // element in the current window
    //     if (map.find(array[right])==map.end())
    //         map[array[right]]=0;
    //     map[array[right]]++;
 
    //     // Shrinking the window from left if the
    //     // count of distinct elements exceeds K
    //     while (map.size() > x) {
    //         map[array[left]]= map[array[left]] - 1;
    //         if (map[array[left]] == 0)
    //             map.erase(array[left]);
    //         left++;
    //     }
 
    //     // Adding the count of subarrays with at most
    //     // K distinct elements in the current window
    //     count += right - left + 1;
    //     right++;
    // }
    cout << result << endl;
}
