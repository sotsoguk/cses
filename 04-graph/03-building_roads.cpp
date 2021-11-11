#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 2e5+1;
vector<int> adj[MAXSIZE];
vector<int> city_in_component;
bool visited[MAXSIZE];
int n;

void dfs(int root) {
    if (visited[root]) {
        return;
    }
    visited[root] = true;
    for (int c:adj[root]){
        if (!visited[c]){
            dfs(c);
        }
    }
}
int count_connected_components() {
    int count = 0;
    for (int i=1;i<=n;i++){
        if (!visited[i]) {
            city_in_component[count] = i;
            count ++;
            dfs(i);
        }
    }
    return count;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> k;
    city_in_component =  vector<int>(n+1,0);
    for (int i=1;i<=k;i++) {
        int a,b;
        cin >>a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long result = count_connected_components();
    cout << result -1 << endl;
    for (int i=1;i<result;i++) cout << city_in_component[i-1] <<" " << city_in_component[i]<<endl;


    
    
}