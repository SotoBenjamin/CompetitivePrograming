#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
ll k;

vector<ll> a;

bool check(ll t, vector<ll> A){
    ll op = t - A[n/2]; 
    if(op > k) return false;
    A[n/2] = t;
    for(int i = n/2 + 1 ; i < n ; i++){
        if(A[i] < A[i-1]){
            op += (A[i-1] - A[i]);
            if(op > k) return false;
            A[i] = A[i-1];
        }
    }
    return true;
}



void slv(){
    cin>>k;
    a.assign(n,0);
    //cout<<n<<endl;
    //cout<<k<<endl;
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll l = a[n/2] , r = 2e18;
    ll ans = a[n/2];
    while(l <= r){
        ll m = l + (r-l)/2;
        if(check(m,a)){
            ans = m;
            l = m+1;
        }
        else r = m-1;
    }
    cout<<ans<<"\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n) slv();
}
