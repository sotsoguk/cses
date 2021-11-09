#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 2e5;




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for (auto c:digits(123949)) cout <<c<<",";
    long n;
    cin >> n;
    map <int,int> compress;
    vector<int> a(n), b(n),p(n);
    for (int i=0;i<n;i++){
        cin >> a[i] >> b[i] >> p[i];
        b[i]++;
        compress[a[i]];
        compress[b[i]];
    }
    int coords = 0;
    for  (auto &v:compress) {
        v.second = coords++;
    }

    vector<vector<pair<int,int>>> projects(coords);
    for (int i=0;i<n;i++) {
        projects[compress[b[i]]].emplace_back(compress[a[i]],p[i]);
    }
    // for (auto i:array) cout <<i<<",";
    vector<long long> dp(coords,0);
    for (int i=0;i<coords;i++){ 
        if (i>0){ 
            dp[i] = dp[i-1];
        }
        for (auto p: projects[i]){
            dp[i] = max(dp[i], dp[p.first]+p.second);
        }
    }
    cout << dp[coords-1] <<endl;
        
}