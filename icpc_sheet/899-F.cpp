#include <bits/stdc++.h>
#define dbg(x) cout << #x << " = " << x << endl
#define raya() cout<<"------------------------------"<<endl;
//https://codeforces.com/problemset/problem/899/F
using namespace std;
using ll = long long;
int n,m;
string s;
const ll MOD = 998244353;

int idx_of(char c) {
    int x = c;
    if ( x >= 65 && x <= 90 ) return x - 65;
    if ( x >= 97 && x <= 122 )  return x - 97;
    return x - 48;
}

void process(vector<int>& v) {
    for (int i = 1 ; i <= n ; i++) {
        v[i] += v[i-1];
    }
}

void slv(){
    cin>>s;
    vector a(63,vector<int>(n+1,0));
    string ans;
    while (m--) {
        char c;
        int l,r; cin>>l>>r>>c;
        l--; r--;
        assert(idx_of(c) != -1);
        int id = idx_of(c);
        a[id][l] ++;
        a[id][r+1]--;
    }
    for (int i = 0 ; i < 63 ; i++) process(a[i]);

    for (int i = 0 ; i < n ; i++) {
        int id = idx_of(s[i]);
        for (auto& i : a[id]) cout << i << ' ';
        cout << endl;
    }
    //cout<<ans<<"\n";
    raya();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> m) {
        slv();
    }
    return 0;
}
