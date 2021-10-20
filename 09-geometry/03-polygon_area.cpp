#include <bits/stdc++.h>


using namespace std;

struct P2di {
    long x;
    long y;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long x,y,area(0);
    cin >> n;
    vector<P2di> v(n);
    for (int i=0;i<n;++i){
        cin >>x >>y;
        v[i].x = x;
        v[i].y = y;
    }
    for (int i=0;i<n;++i){
        int ni = (i+1) % n;
        area += (v[i].y + v[ni].y)*(v[i].x-v[ni].x);
    }
    area = abs(area);
    cout <<area<<"\n";


}