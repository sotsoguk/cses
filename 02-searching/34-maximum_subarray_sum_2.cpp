#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n,a,b;

    cin >> n >>a>>b;

    
    vector<long long> prefix_sum(n+1,0);

    for (int i = 0; i < n; i++){
        long tmp;
        cin >> tmp;
        prefix_sum[i+1] = tmp + prefix_sum[i];
    }
    long long result = -1e18;
    
    multiset<long long> windowSums;
    // long long result(0);
    for (int i=a;i<=n;i++) {
        if (i>b){ //remove prefixes outside the windows
            windowSums.erase(windowSums.find(prefix_sum[i-b-1]));
        }
        windowSums.insert(prefix_sum[i-a]);
        result = max(result, prefix_sum[i]-*windowSums.begin());
    }
    cout << result << endl;
}
