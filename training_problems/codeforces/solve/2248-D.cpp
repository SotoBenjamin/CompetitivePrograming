#include <bits/stdc++.h>
using namespace std;

int n,q;



void slv() {
    cin >> n >> q;
    string s,t;
    cin>>s>>t;
    vector<int> eq(n+1,0); // 11 , 00
    vector<int> a(n+1,0);  //01
    vector<int> b(n+1,0); //10

    for (int i = 1 ; i <= n ; i++) {
        if (s[i-1] == t[i-1]) eq[i] = eq[i-1] + 1;
        else eq[i] = eq[i-1];

        if (s[i-1] == '1' && t[i-1] == '0') b[i] = b[i-1] + 1;
        else b[i] = b[i-1];

        if (s[i-1] == '0' && t[i-1] == '1') a[i] = a[i-1] + 1;
        else a[i] = a[i-1];
    }

    while (q--) {
        int l,r; cin >> l >> r;
        int x = a[r] - a[l-1];
        int y = b[r] - b[l-1];
        int z = abs(x-y);
        int w = eq[r] - eq[l-1];
        if ( w >= z) cout<<"YES\n";
        else cout<<"NO\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; cin >> t;
    while (t--) slv();

    return 0;
}
