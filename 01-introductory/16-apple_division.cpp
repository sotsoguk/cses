#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long p,w,tw(0),result(0);
    vector<long> ws;
    // cin >> i;
    
    cin >> n;
    for (int i=0;i< n;i++){
        cin >>w;
        tw += w;
        ws.push_back(w);
    }
   
  
    
    result = 0;
    p = 1<<n;
    
    for (long i=0;i<p;i++){
        long cw(0);
        for (long j=0;j<n;j++){
            // cout <<j<<".";
            if (i>>j &1){
                cw+=ws[j];
            }
        }
        // cout <<i<<": "<<cw<<"\n";
        if (cw <= tw/2){
            result = max(result,cw);
        }
    }
    cout <<abs(2*result-tw) <<"\n";
}