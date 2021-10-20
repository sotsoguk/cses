#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long> nums(n);
    for (int i=0;i<n;i++) cin >> nums[i];
    long max_sum = INT64_MIN;
    long curr_sum = 0;
    for (auto n:nums){
        curr_sum += n;
        max_sum = max(max_sum,curr_sum);
        curr_sum = max(0L,curr_sum);

    }
    cout << max_sum<<endl;
}