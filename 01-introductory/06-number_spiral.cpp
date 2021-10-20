#include <bits/stdc++.h>


using namespace std;


long spiral(long x, long y){
    long l = max(x,y);
    long c = l*(l-1) +1;
    long d = x-y;
    if (l%2 == 0){
        return c+d;
    }else{
        return c-d;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    long x,y;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >>x>>y;
        cout << spiral(x,y)<<"\n";
    }


}