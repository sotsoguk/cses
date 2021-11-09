#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 2e5;
vector<int> adj[MAXSIZE];

void matches(int root, int parent, vector<bool> &used, int &num_edges)
{
    for (auto c : adj[root])
    {
        // cout << root <<":"<<c<<endl;
        if (c == parent)
            continue;
        // ! DFS has to occur BEFORE marking edges
        matches(c, root, used, num_edges);
        if (used[root] == false && used[c] == false)
        {
            used[root] = true;
            used[c] = true;
            num_edges++;
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
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> used(n + 1, false);

    int result(0);
    matches(1, 0, used, result);
    cout << result << endl;
}