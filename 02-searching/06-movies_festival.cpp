#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> movies(n);
    for (int i=0;i<n;i++) {
        int a,b;
        cin >>a >>b;
        movies[i] = make_pair(a,b);
    }
    sort(movies.begin(),movies.end(),[](auto &left, auto &right){
        return left.second < right.second;
    });
    // for (auto i:movies){
    //     cout << i.first <<","<<i.second<<endl;
    // }
    long currentEndTime = -1;
    long moviesToWatch = 0;
    for (auto m:movies){
        if (m.first >= currentEndTime){
            moviesToWatch++;
            currentEndTime = m.second;
        }
            
            
    }
    cout << moviesToWatch<<endl;
}



// std::sort(v.begin(), v.end(), [](auto &left, auto &right) {
//     return left.second < right.second;
// });