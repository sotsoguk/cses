#include <bits/stdc++.h>


using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    long a,b;
    cin >> t;
    for (int i = 0;i<t;i++){
        cin >>a >>b;
        if ((a+b)%3 != 0){
            cout <<"NO\n";

        }
        else{
            long aa,bb;
            aa = max(a,b);
            bb = min(a,b);
            if (bb >= aa/2) {
                cout <<"YES\n";
            }
            else{
                cout <<"NO\n";
            }
                
        }
    }


}