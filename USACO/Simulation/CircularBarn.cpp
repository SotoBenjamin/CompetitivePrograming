#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
using namespace std;


typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
     
template<typename T>                                                             
T minV(T a){
    return a;
}

template<typename T, typename ... Args>
T minV(T a , Args... arg){
    T b = minV(arg...);
    return min(a,b);
}



void slv(){
	int n; cin>>n;
	vector<int> v(n);
	for(auto& i : v) cin>>i;
	ll ans = 1e18;
	for(int i = 0 ; i < n ; i++){
		int k = i;
		ll s = 0;
		for(int j = 0 ; j < n ; j++){
			s += v[k]*j;
			k = (k+1)%n;
		}
		ans = min(ans,s);
	}
	cout<<ans<<"\n";
}
     
int main(){
	freopen("cbarn.in", "r" ,stdin);
	freopen("cbarn.out", "w", stdout);

    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}



