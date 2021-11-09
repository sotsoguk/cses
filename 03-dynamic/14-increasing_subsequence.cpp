#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 2e5;




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for (auto c:digits(123949)) cout <<c<<",";
    long n;
    cin >> n;
    vector<long> array(n,0);
    vector<int> dp(n,0);
    vector<long> c(n+1,0);
    for (long &a:array) {
        cin >> a;
        
    }
    // for (auto i:array) cout <<i<<",";
    int size = 1;
    c[0] = array[0];
    for (int i=1;i<n;i++){
        auto b = c.begin(), e = c.begin()+size;
        auto it = lower_bound(b,e,array[i]);
        if (it == e) {
            c[size++] = array[i];
        }else{
            *it = array[i];
        }
    }
    // for (int i=1;i<n;i++) {
    //     if (array[i]<c[1]) {
    //         c[1] = array[i];
    //     } else if (array[i] > c[size]){
    //         size++;
    //         c[size] = array[i];
    //     } else{
    //         // int k = binary_search(c.begin(), c.begin()+size, array[i]);
    //         auto k = lower_bound(c.begin(), c.begin()+size,array[i]);
    //         k--;
    //         c[*k] = array[i]; cout << "FOUND:" << *k<<endl;
    //     }
    //     cout << i <<": "<<array[i]<<"\n";
    //     for (int k = 1;k<=size;k++) cout <<c[k] <<",";
    //     cout <<endl;

    // }
    // for (auto t:dp) {
    //     cout <<t<<",";
    // }
    // cout << endl;
    
    // cout << endl;
    cout << size<<endl;
        
}