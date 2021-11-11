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

void dijkstra(int root, vector<vector<pair<int,int>>> &adj, vector<bool> &visited,
                vector<long> &lens) {
    // cout << "# "<<root << endl;
    
    
    priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> q;
    // q.push({root,0});
    q.push({0,root});
    while (!q.empty()){
        auto node = q.top().second;q.pop();
        // cout << "#Node: " << node<<endl;
        if (visited[node]) continue;
        visited[node] = true;
        for (auto [b,c] : adj[node]){
            if (lens[b] > lens[node] + c) {
                lens[b] = lens[node] + c;
                // q.push({b, lens[b]});
                q.push({lens[b],b});
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
   
    vector<vector<pair<int,int>>> adj(n+1);
    // vector<bool> visited(n+1,false);
    
    vector<bool> visited(n+1,false);
    vector<long> lens(n+1,LONG_MAX);
    lens[1] = 0;

    for (int i=1;i<=k;i++) {
        int a,b,c;
        cin >>a >>b >> c;
        adj[a].push_back(make_pair(b,c));
        
    }
    // for (auto i:adj){
    //     for (auto j:i) {
    //         cout << j.first <<";" << j.second << endl;
    //     }
    // }
    dijkstra(1,adj, visited,lens);
    for (int i=1;i<=n;i++) cout << lens[i] <<" ";
    cout << endl;
    
}