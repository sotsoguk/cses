#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long k, n, maxVal(0);
    long long totalSum(0);
    long result(0);
    cin >> n >> k;
    vector<long> array(n, 0);
    for (int i = 0; i < n; i++){
        cin >> array[i];
        maxVal = max(maxVal,array[i]);
        totalSum += array[i];
    }
    
    long lo = maxVal;
    long hi = totalSum;
    result = totalSum;
    while (lo <= hi) {
        long mid = (lo + hi) / 2;
        long currSubSum(0), maxSubSum(0);
        int currK= 1;
        for (int i=0;i<n;i++){
            if (currSubSum + array[i] > mid) {
                maxSubSum = max(maxSubSum,currSubSum);
                currSubSum = array[i];
                currK ++;
            }else{
                currSubSum += array[i];
            }
        }
        maxSubSum = max(maxSubSum,currSubSum);
        if (currK <= k){
            result = min(result,maxSubSum);
            hi = mid -1;
        } else{
            lo = mid +1;
        }
    }
    
    
    cout << result << endl;
}
