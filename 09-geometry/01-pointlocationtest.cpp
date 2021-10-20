#include <bits/stdc++.h>
using namespace std;

string cross2d(long x1,long y1,long x2,long y2,long x3,long y3) {
    long cp = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    if (cp < 0) {
        return "RIGHT";
    }
    else if (cp>0) {
        return "LEFT";
    }
    return "TOUCH";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    long x1,x2,x3,y1,y2,y3;
    cin >> t;

    for (int i=0;i<t;i++){
        cin >>x1>>y1>>x2>>y2>>x3>>y3;
        cout <<cross2d(x1,y1,x2,y2,x3,y3)<<"\n";
    }
}