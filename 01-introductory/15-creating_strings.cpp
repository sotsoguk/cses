#include <bits/stdc++.h>


using namespace std;


void permute(string s, int l, int r, set<string> &p){
    if (l==r) p.insert(s);
    else{
        for (int i=l;i<=r;i++){
            swap(s[l],s[i]);
            permute(s,l+1,r,p);
            swap(s[l],s[i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n;
    cin >> n;
    set<string> result;
    permute(n,0,n.length()-1,result);
    cout <<result.size()<<"\n";
    for (auto i:result) cout <<i<<"\n";
        


}