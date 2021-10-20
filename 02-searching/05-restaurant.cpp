#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int a,b;
    cin >> n;
    vector<pair<int,int>> intervals;
    for (int i=0;i<n;i++){
        cin >> a >> b;
        intervals.push_back(make_pair(a,1)); // entry
        intervals.push_back(make_pair(b,-1));

    }
    sort(begin(intervals), end(intervals));
    int result(0);
    int sum(0);
    for (auto i: intervals){
        sum += i.second;
        result = max(result,sum);
    }
    cout << result << endl;
}