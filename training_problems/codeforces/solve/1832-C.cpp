#include <bits/stdc++.h>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using ll = long long;
//https://codeforces.com/problemset/problem/1832/C
using namespace std;
const ll INF = (ll) 1e18;
int n;


void slv() {
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1 ; i < n ; i++) {
        if (a[i] != a[i-1]) b.push_back(a[i]);
    }
    vector<int> c;
    c.push_back(b[0]);
    for (int i = 1 ; i < (int) b.size() -1; i++) {
        if (b[i-1] < b[i] && b[i] < b[i+1]) continue;
        if (b[i-1] > b[i] && b[i] > b[i+1]) continue;
        c.push_back(b[i]);
    }
    c.push_back(b.back());
    if (c.size() == 2 && c[0] == c[1]) {
        cout<<"1\n";
        return;
    }

    cout<<c.size()<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}