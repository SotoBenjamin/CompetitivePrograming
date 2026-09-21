#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/problemset/problem/1907/D
using namespace std;
int n;
vector<ll> L;
vector<ll> R;

bool go(ll k) {
    ll lx = 0 , rx = 0;
    for (int i = 0 ; i < n ; i++) {
        //dbg(lx);
        //dbg(rx);
        //dbg(L[i]);
        //dbg(R[i]);
        //cout<<"---------------------------\n";
        if (L[i] >= rx) {
            if (rx + k < L[i]) return false;
            lx = L[i];
            rx = min(rx + k , R[i]);
            continue;
        }
        if (R[i] <= lx) {
            if (lx - k > R[i]) return false;
            rx = R[i];
            lx = max(L[i] , lx - k);
            continue;
        }

        if (L[i]  <= lx && R[i] >= rx) {
            lx = max(lx - k , L[i]);
            rx = min(rx + k , R[i]);
            continue;
        }

        if (L[i] >= lx && R[i] <= rx) {
            lx = L[i];
            rx = R[i];
            continue;
        }

        if (L[i] >= lx ) {
            lx = L[i];
            rx = min(rx + k , R[i]);
            continue;
        }

        if (R[i] <= rx) {
            rx = R[i];
            lx = max(lx - k , L[i]);
            continue;
        }
    }
    return true;
}


void slv() {
    cin>>n;
    L.assign(n ,0);
    R.assign(n ,0);
    for (int i = 0; i < n; i++) cin>>L[i]>>R[i];
    ll l = 0 , r = 1e9;
    ll res = -1;
    while (l <= r) {
        ll m = (l + r) / 2;
        if (go(m)) {
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res << "\n";
}

int main() {
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}