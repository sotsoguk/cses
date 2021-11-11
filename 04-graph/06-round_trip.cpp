#include <bits/stdc++.h>

using namespace std;

#define ld long double

int dfs(int root, int par,vector<vector<int>> &adj, vector<int> &cycle, vector<bool> &visited){
    // parent[root] = par;
    visited[root] = true;
    // cout << "# "<<root<<", " <<par <<endl;
    for (auto c:adj[root]){
        
            cycle.push_back(c);
            if (!visited[c]){
                if (dfs(c,root,adj,cycle,visited) == 1)
                return 1;
            } else if (c!= par){
                return 1;
            }
            cycle.pop_back();
    }
    return 0;
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
    vector<int> cycle(n+1,0);

    for (int i=1;i<=k;i++) {
        int a,b;
        cin >>a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        cycle.push_back(i);
        if (!visited[i] && dfs(i,0,adj,cycle,visited)==1) {
            vector<int> solution{*cycle.rbegin()};
            for (auto j=cycle.rbegin()+1;j!=cycle.rend();j++) {
                solution.push_back(*j);
                if (*j == *cycle.rbegin()) break;
            }
            cout << solution.size() << endl;
            for (auto s:solution) cout << s << " ";
            cout << endl;
            return 0;
        }
        cycle.pop_back();
    }
    cout << "IMPOSSIBLE" << endl;
    
}