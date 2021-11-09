#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 2e5;
vector<int> adj[MAXSIZE];
int toLeaf[MAXSIZE], maxLength[MAXSIZE];


// void dfs_size(int node){
//     subtree_size[node] = 1; // the node itself
//     for (int child: children[node]) {
//         dfs_size(child);
//         subtree_size[node] += subtree_size[child];
//     }
// }
void calcLeaf(int root, int par){
   
    if (adj[root].size() == 0)
        toLeaf[root] = 0;
    else {
        int tL = 0;
        int largestA(-1), largestB(-1);
        for (auto c: adj[root]) {
            if (c != par) {
                calcLeaf(c,root);
                int tmp = toLeaf[c];
                tL = max(tmp + 1,tL);
                if (tmp > largestA) {
                    largestB = largestA;
                    largestA = tmp;
                }
                else if (tmp >largestB){
                    largestB = tmp;
                }
            }
        }
        toLeaf[root] = tL;
        if (largestA == -1) {
            maxLength[root] = 0;
        } else if (largestB == -1){
            maxLength[root] = largestA + 1;
        }
        
        else {
            maxLength[root] = largestA + largestB + 2;
        }
   
        
    }
}
// void calcMaxLength(int root, int parent){
//     // find maxLength
//     for (int i=0;i<n;i++){
//         int largestA(0), largestB(0);
//         for (auto c: adj[i]){
            
//         }
//         maxLength[i] = largestA + largestB;
//     }
//     int largestA(0), largestB(0);
//     for (auto c:adj[root]){
        
//         if (c != parent){
//             int tmp = toLeaf[c];
//             if (tmp > largestA) {
//                 largestB = largestA;
//                 largestA = tmp;
//             }
//             else if (tmp >largestB){
//                 largestB = tmp;
//             }
//         }
//     }

// }
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
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // for (auto t:dp) {
    //     cout <<t<<",";
    // }
    // cout << endl;
    // for (int i=0;i<n;i++){
    //     for (auto c:adj[i])
    //         cout << c << " ";
    //     cout << endl;
    // }
    // fill(toLeaf,toLeaf+n,0);
    // fill(maxLength,maxLength+n,0);
    
    calcLeaf(0,0);
    // for (int i=0;i<n;i++) 
    //     cout <<toLeaf[i]<<" ";
    // cout << endl;
    
    // for (int i=0;i<n;i++){
    //     cout <<maxLength[i] << " ";
    // }
    auto result = max_element(maxLength,maxLength+n);
    cout << (*result);
    cout << endl;
        
}