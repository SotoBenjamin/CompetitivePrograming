#include <bits/stdc++.h>
#define dbg(x) cout << #x << " = " << x << endl
#define raya() cout<<"------------------------------"<<endl;
//https://codeforces.com/contest/1102/problem/E
using namespace std;
using ll = long long;
int n,m;

const ll MOD = 998244353;

void slv(){
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    map<int,vector<int>> mp;
    for (int i = 0 ; i < n ; i++) mp[a[i]].push_back(i);
    vector p(n,0);
    for (auto& [s,v] : mp) {
        if (v.size() == 1) continue;
        int l = v.front() , r = v.back();
        p[l] += 1;
        p[r] -= 1;
    }
    ll ans = 1;

    ll s = p[0];
    for (int i = 1; i < n; i++) {
        //dbg(s);
        //dbg(p[i]);
        if (s == 0) ans = (ans * 2) % MOD;
        s += p[i];
    }
    cout << ans << "\n";
    //raya();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        slv();
    }
    return 0;
}
