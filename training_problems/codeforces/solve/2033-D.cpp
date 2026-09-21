#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/problemset/problem/2033/D
using namespace std;
const ll INF = (ll) 1e18;
int n;


void slv() {
    cin>>n;
    vector<ll> a(n+1);
    for (int  i = 1; i <= n; i++) cin>>a[i];
    vector f(n+1,-INF);
    f[0] = 0;
    map<ll,int> mp;
    mp[0] = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        f[i] = f[i-1];
        if (mp.contains(sum)) f[i] = max(f[i],1 + f[mp[sum]]);
        mp[sum] = i;
    }
    cout << f[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}