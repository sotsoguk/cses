#include <bits/stdc++.h>

using namespace std;

#define ld long double
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> r(n,0);
    for (auto &i:r) cin >> i;
    long double result = 0.0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++){
            long double totalPoss = r[i]*r[j];
            long long k = 0;
            if (r[j] <= r[i]) {
                k = (r[j]*(r[j]-1)) /2;
            }
            else{
                k= (r[i]*(r[i]-1)/2) + (r[j]-r[i]) * r[i];
            }
            result += (long double) k / totalPoss;
        }
    }
    cout << fixed<<setprecision(6)<< result<<endl;
    
}