#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

const int MOD = 1e4 + 7;

int n,m,a,b,k;

int binpow(int x,int y){
   int ans = 1; 
   while(y > 0){
      if(y%2 == 1) ans = (ans * x) % MOD;
      x = (x * x) % MOD;
      y = y/2;
   }
   return ans;
}




void slv(){
    vector<int> f(k+1,0);
    f[0] = 1;
    for(int i = 1 ; i <= k ; i++) f[i] = (f[i-1] * i) % MOD;
    vector<int> inv_f(k+1,0);
    inv_f[k] = binpow(f[k],MOD - 2);
    for(int i = k-1 ; i >= 0 ; i--){
        inv_f[i] = (inv_f[i+1] * (i+1)) % MOD; 
    }
    int x = binpow(a,n) , y = binpow(b,m);
    int ans = (((f[k] * inv_f[n]) % MOD) * inv_f[m]) % MOD;
    ans = (ans * x) % MOD;
    ans = (ans * y) % MOD;
    cout << ans << "\n";
}


signed main(){
    while(cin >> a >> b >> k >> n >> m) slv();
    return 0;
}
