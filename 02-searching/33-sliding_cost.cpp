#include <bits/stdc++.h>

using namespace std;

long maxSize = 2e5+10;
multiset<long> hi;
multiset<long> low;
long sumLow = 0;
long sumHi = 0;
long n,k;

void insert(long x) {
    long med = *low.rbegin(); //current median
    if (x > med) {
        hi.insert(x);
        sumHi += x;
        if (hi.size() > k/2) {
            long delta = *hi.begin();
            low.insert(*hi.begin());
            hi.erase(hi.find(*hi.begin()));
            sumHi -= delta;
            sumLow += delta;
        }
    }
    else {
        low.insert(x);
        sumLow += x;
        if (low.size() > (k+1)/2) {
            long delta = *low.rbegin();
            hi.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
            sumHi += delta;
            sumLow -= delta;
        }
    }
}

void erase(long x){
    if (hi.find(x) != hi.end()){
        hi.erase(hi.find(x));
        sumHi -= x;
    } else{
        low.erase(low.find(x));
        sumLow -= x;
    }
    if (low.empty()){
        long delta = *hi.begin();
        low.insert(*hi.begin());
        hi.erase(hi.find(*hi.begin()));
        sumHi -=delta;
        sumLow += delta;
    }
}
long median() {
    if (k%2 == 0){
        return 0;
    } else{
        return *low.rbegin();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long totalSum(0);
    long result(0);
    cin >> n >> k;
    vector<long> array(n, 0);
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    // insert first k values in to sliding windows
    low.insert(array[0]); 
    sumLow += array[0];
    for (int i=1;i<k;i++) insert(array[i]);
    cout << sumHi-sumLow + median() << " ";
    for (long i = k; i<n;i++){
        if (k==1) {
            insert(array[i]);
            erase(array[i-1]);
        }
        else{
            erase(array[i-k]);
            insert(array[i]);
        }
        cout << sumHi-sumLow + median() << " ";
    }
    cout << endl;
    
    

}
