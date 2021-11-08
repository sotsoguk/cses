#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int x;
    int maxX = 1e6+5;
    vector<int> divisors(maxX,0);
    cin >> n;
    for (int i=1;i<maxX;i++){
        for (int j=i;j<maxX;j+=i)
            divisors[j]++;
    }

    for (int i=0;i<n;i++) {
        cin >> x;
        cout << divisors[x]<<endl;
        
    }
    
}