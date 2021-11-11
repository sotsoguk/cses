#include <bits/stdc++.h>

using namespace std;

#define ld long double
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
   
    vector<vector<int>> adj(n+1);
    vector<int> distances(n+1,INT_MAX);
    vector<int> parent(n+1,0);

    for (int i=1;i<=k;i++) {
        int a,b;
        cin >>a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // BFS
    queue<int> q;
    distances[1] = 0;
    long dist = 0;
    q.push(1);
    while (!q.empty()) {
        
        int node = q.front();
        q.pop();
        for (auto c:adj[node]){
            if (distances[c]== INT_MAX){
                distances[c] = distances[node] +1;
                parent[c] = node;
                q.push(c);
            }
        }



    }
    if (distances[n] == INT_MAX) cout <<"IMPOSSIBLE\n";
    else{
        // construct way
        cout << distances[n] +1<< endl;
        vector<int> path{n};
        while (path.back() != 1) {
            path.push_back(parent[path.back()]);
        }
        for (auto it = path.rbegin(); it!= path.rend();it++) {
            cout << (*it) << " ";
        }
    }
    
}