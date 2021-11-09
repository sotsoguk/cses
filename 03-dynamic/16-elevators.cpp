#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 2e5;




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for (auto c:digits(123949)) cout <<c<<",";
    int n;long x;
    cin >> n >> x;
    vector<long> w(n);
    for (int i=0;i<n;i++) cin >> w[i];

    // array for all possible subsets => 2^n
    pair<int,long> dp[1 << n]; // {rides, min weight for last ride}
    dp[0] = {1,0};
    for (int ss = 1; ss <(1<<n);ss++) {
        // set initially to n+1 rides, bigger than at most needed
        dp[ss] = {n+1,0};
        for (int j=0;j<n;j++){ // iterate over all passengers
            // check if passenger in this subset
            if (ss & (1<<j) ){
                auto opt = dp[ss^(1<<j)]; // search best solution for subset without this passenger
                if (opt.second + w[j] <= x){
                    // add current passenger to a ride
                    opt.second += w[j];
                }
                else {
                    // new ride
                    opt.first++;
                    opt.second = w[j];
                }
                dp[ss] = min(dp[ss],opt);
            }
        }

    }
    cout << dp[(1<<n)-1].first << endl;
        
}