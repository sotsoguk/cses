#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n,x;
    cin >> n>>x;
    multimap<long,long> nums;
    for (int i=0;i<n;i++) {
        int t;
        cin >> t;
        nums.insert(make_pair(t,i));

    }
    for (auto n:nums){
        long target = x-n.first;
        //auto it = nums.find(target);
        auto ret = nums.equal_range(target);
        if (ret.first != ret.second){
            for (auto it=ret.first;it!= ret.second;++it){
                if (it->second != n.second){
                    cout << n.second+1<<" "<<(*it).second+1<<endl;
                    return 0;
                }
            }
            
        }
    }
    cout << "IMPOSSIBLE\n";
}