#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string seq;// = "ATTCGGGAAAAA";
    cin >> seq;
    char curr_ch(0), prev_ch(0);
    int curr_seq(1), long_seq(0);
    for (auto s:seq){
        prev_ch = curr_ch;
        curr_ch = s;
        if (prev_ch == curr_ch){
            curr_seq += 1;
        }
        else {
            long_seq = max(curr_seq,long_seq);
            curr_seq = 1;
        }
    }
    long_seq = max(curr_seq,long_seq);
    cout <<long_seq <<"\n";
}