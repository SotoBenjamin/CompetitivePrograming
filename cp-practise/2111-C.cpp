#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define dbg(x) cerr<<#x<<" = "<<x<<endl;
#define INF 1e18
#define all(x) x.begin(),x.end()

const int MAXN = 2e5 + 5;

using namespace std;

int n;
string s;
void slv(){
    cin>>n;
    ll a[n+1];
    for(int i = 1 ; i <= n ; i++) cin>>a[i];
    ll ans = (ll) INF;
    int i = 1;
    while(i <= n){
        int j = i;
        while(j <= n && a[j] == a[i]) j++;
        ll t = (i-1)*a[i] + (n-j+1)*a[j-1];
        ans = min(ans,t);
        i = j;
    }
    cout<<ans<<"\n";
}

signed main(){
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	  int t = 1; cin>>t;
	  while(t--) slv(); 
	  return 0;
}
