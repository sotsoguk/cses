#include <bits/stdc++.h>

using namespace std;

#define ld long double
bool possible = true;
void dfs(int root, int parent,vector<vector<int>> &adj, vector<int> &color, vector<bool> &visited){
    int childColor =(color[root] == 1)?2:1;
    for (auto c:adj[root]){
        if (c!= parent){
            if (!visited[c]){
                color[c] = childColor;
                visited[c] = true;
                dfs(c,root,adj,color,visited);
            }
            else{
                if (color[c] != childColor){
                    possible = false;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
   
    vector<vector<int>> adj(n+1);
    // vector<bool> visited(n+1,false);
    vector<int> color(n+1,0);
    vector<bool> visited(n+1,false);

    for (int i=1;i<=k;i++) {
        int a,b;
        cin >>a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n;i++){
        if (!visited[i]){
            color[i] = 1;
            dfs(i,0,adj,color,visited);
        }
    }
    if (possible){
        for (int i=1;i<=n;i++) cout << color[i] <<" ";
        cout << endl;
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    
    
}