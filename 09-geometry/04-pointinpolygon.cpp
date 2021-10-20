#include <bits/stdc++.h>


using namespace std;

struct P2di {
    long x;
    long y;
};

int cross2d(P2di &a, P2di &b ,P2di &c){
    return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
}
int pointInside(vector<P2di> &v, P2di &p){

    int n = v.size();
    vector<int> tmp(n);
    for (int i=0;i<n;i++) {
        int ni= (i+1) % n;
        tmp[i] = cross2d(v[i],v[ni],p);
    }
    // for (auto i:tmp){
    //     cout <<i<<",";
        
    // }
    if (all_of(tmp.cbegin(), tmp.cend(),[](int i){return i<0;}) || 
        all_of(tmp.cbegin(), tmp.cend(),[](int i){return i>0;})){
            cout <<"INSIDE\n";
        }
    else if (any_of(tmp.cbegin(), tmp.cend(),[](int i){return i==0;})){
        cout << "TOUCHING\n";

    }
    else {
        cout <<"OUTSIDE\n";
    }
    // cout <<"\n";
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    long x,y;
    cin >> n>>m;
    vector<P2di> v(n);
    vector<P2di> p(m);
    for (int i=0;i<n;++i){
        cin >>x >>y;
        v[i].x = x;
        v[i].y = y;
    }
    for (int i=0;i<m;++i){
        cin >>x >>y;
        p[i].x = x;
        p[i].y = y;
    }
    for (int i=0;i<m;i++){
        pointInside(v,p[i]);
    }
    // P2di a{0,0};
    // P2di b{4,0};
    // P2di c{4,4};
    // P2di d{0,4};
    // P2di p{6,6};
    // vector<P2di> t;
    // t.push_back(a);
    // t.push_back(b);
    // t.push_back(c);
    // t.push_back(d);
    // pointInside(t,p);
    // cout <<cross2d(a,b,c)<<"\n";


}