#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 2e5;
vector<int> children[MAXSIZE];
int subtree_size[MAXSIZE], depth[MAXSIZE];


void dfs_size(int node){
    subtree_size[node] = 1; // the node itself
    for (int child: children[node]) {
        dfs_size(child);
        subtree_size[node] += subtree_size[child]
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for (auto c:digits(123949)) cout <<c<<",";
    long n;
    cin >> n;
    for (int i=1; i<n;i++) {
        int parent; 
        cin >> parent;
        parent --;
        children[parent].push_back(i);
    }
    // for (auto t:dp) {
    //     cout <<t<<",";
    // }
    // cout << endl;
    dfs_size(0);
    for (int i=0; i<n;i++){
        cout << subtree_size[i]-1;
        if (i != n-1) cout <<" ";
    }
    cout << endl;
        
}