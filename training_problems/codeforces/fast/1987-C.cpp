#include <bits/stdc++.h>
#define INF 1e9
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;
int n;
int m;

vector<ll> a;

void slv(){
    cin>>n;
    a.assign(n,0);
    for (int i = 0 ; i < n ; i++) cin>>a[i];
    vector<ll> t(n,0);
    t[n-1] = a[n-1];
    for (int i = n-2 ; i >= 0 ; i--) {
        t[i] = max(t[i+1] + 1 , a[i]);
    }
    cout<< *max_element(t.begin(),t.end()) << "\n";
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
