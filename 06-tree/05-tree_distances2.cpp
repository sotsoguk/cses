#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 2e5+1;
vector<int> adj[MAXSIZE];

long long result[MAXSIZE];
long long subtreeSize[MAXSIZE];


// void dfs_size(int node){
//     subtree_size[node] = 1; // the node itself
//     for (int child: children[node]) {
//         dfs_size(child);
//         subtree_size[node] += subtree_size[child];
//     }
// }

void dfs(int root, int par, long long depth){
    result[1] += depth;
    subtreeSize[root] = 1;
    for (auto c: adj[root]){
        if (c!= par) {
            dfs(c,root,depth+1);
            subtreeSize[root] += subtreeSize[c];
        }
    }
}

void dfs_reroot(int root, int par, int n) {
    for (auto c: adj[root]){
        if (c != par){
            result[c] = result[root] + n -2*subtreeSize[c];
            dfs_reroot(c,root,n);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for (auto c:digits(123949)) cout <<c<<",";
    long n;
    cin >> n;
    for (int i=0; i<n-1;i++) {
        int a,b; 
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

   dfs(1,0,0);
   dfs_reroot(1,0,n);
   for (int i=1;i<=n;i++) cout << result[i] <<" ";
   cout <<endl;

        
}