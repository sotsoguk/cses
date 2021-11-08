#include <bits/stdc++.h>

using namespace std;

long expmod(long a, long b, long mod){
    long result = 1;
    while (b)
    {
        if (b&1){
            result *= a;
        }
        a*=a;
        a %= mod;
        result %= mod;
        b /= 2;
    }
    return result;
}
long **matrix_allocate(int r, int c){
    long **m = new long*[r];
    for (int i=0;i<r;i++){
        m[i] = new long[c]{0};
    }
    return m;
}
long **matrix_mml(long **m1, int r1, int c1, long **m2, int r2, int c2, long mod){
    if (c1 != r2){
        return nullptr;
    }
    auto res = matrix_allocate(r1, c2);
    int i,j,k;
    for (int i=0;i<r1;i++) {
        for (int j=0;j<c2;j++){
            for (int k=0;k<c1;k++){
                res[i][j] += (m1[i][k] * m2[k][j])%mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}
void matrix_mod(long **m, int r, int c,long mod) {
    for (auto i=0;i<r;i++){
        for (auto j=0;j<c;j++){
            m[i][j] = m[i][j] % mod;
        }
    }

}
long **matrix_expmod(long **a, long b, long mod, int r, int c){
    auto result = matrix_allocate(r,c);
    for (int i=0;i<r;i++) result[i][i] = 1;
    while (b){
        if (b&1){
            result = matrix_mml(result,r,c,a,r,c,mod);
        }
        a = matrix_mml(a,r,c,a,r,c,mod);
        matrix_mod(a,r,c,mod);
        matrix_mod(result,r,c,mod);
        b /= 2;
    }
    return result;
}


void matrix_print(long **m, int r, int c){
    for (auto i=0;i<r;i++){
        for (auto j=0;j<c;j++){
            cout << setw(5) << m[i][j] <<", ";
        }
        cout <<endl;
    }
}
void matrix_deallocate(long **m, int r, int c){
    for (int i=0;i<r;i++)
        delete m[i];
    delete []m;
    
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    long mod = 1e9+7;
    cin >> n;
    
    // for (int i=0;i<n;i++) {
    //     long a, b;
    //     cin >>a >> b;
    //     cout <<expmod(a,b,mod) <<endl;
    // }
    long **a = matrix_allocate(6,6);
    // init matrix
    for (int i=0;i<5;i++) a[i][i+1] = 1;
    for (int i=0;i<6;i++) a[5][i] = 1;
    // matrix_mod(a,6,6,7);
    // auto b = matrix_mml(a,6,6,a,6,6);
    auto c = matrix_expmod(a,n,mod,6,6);
    // matrix_print(a,6,6);
    // matrix_print(c,6,6);
    cout << c[5][5] << endl;
    
}