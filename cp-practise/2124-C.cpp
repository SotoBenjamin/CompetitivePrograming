#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define dbg(x) cerr<<#x<<" = "<<x<<endl;

#define all(x) x.begin(),x.end()

const int MAXN = 2e5 + 5;

using namespace std;

int n;

void slv(){
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    int f[n];
    f[n-1] = a[n-1];
    for(int i = n-2 ; i >= 0 ; i--) f[i] = std::gcd(a[i],f[i+1]);
    set<int> p;
    for(int i = 0 ; i < n ; i++){
		  if(a[i] != f[i]){
			  int y = std::gcd(a[i],a[i+1]);
			  p.insert(a[i]/y);
		  }
	  }
	  ll ans = 1;
	  for(int x : p) ans = std::lcm(ans,x);
	  cout<<ans<<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1; cin>>t;
	while(t--) slv(); 
	return 0;
}
