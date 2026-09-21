#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/problemset/problem/2259/E
using namespace std;
const ll INF = (ll) 1e18;
int n;


void slv() {
    cin>>n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin>>b[i];
    vector<ll> dif(n+1,0);
    vector<int> ans(n,1);
    for (int i = 0 ; i < n ; i++) {
        if (b[i] == -1) continue;
        if (b[i] == 0) continue;
        int l = max(0,i-b[i]+1) , r = min(n-1,i+b[i]-1);
        dif[l]++;
        dif[r+1]--;
    }
    ll s = 0;
    for (int i = 0 ; i < n ; i++) {
        s += dif[i];
        if (s > 0) {
            if (b[i] == 0) {
                cout<<"-1\n";
                return;
            }
            ans[i] = 0;
        }
    }

    for (int i = 0 ; i < n ; i++) {
        if (b[i] == 0) continue;
        if (b[i] == -1) continue;
        int l = i - b[i] , r =
            i + b[i];
        bool ok = false;
        if (l >= 0 && ans[l]) ok = true;
        if (r <= n-1 && ans[r]) ok = true;
        if (!ok) {
            cout<<"-1\n";
            return;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout<<ans[i];
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}