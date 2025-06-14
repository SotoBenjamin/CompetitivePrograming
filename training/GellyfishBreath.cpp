#include <bits/stdc++.h>
#include <vector>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
using namespace std;
     
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
              
const ll mod = 1e9+7;
const ll MOD =  998244353;
int nxt() {
        int x; cin >> x;
        return x;
}  
const int inf = INT_MAX;
template<typename T>
T minV(T a){
   return a;
}
template<typename T, typename ... Args>
T minV(T a , Args... arg){
   T b = minVariadic(arg...);
   return min(a,b);
}

ll fastpow(ll a,ll b){
	if( b == 0) return 1LL;
	if( b%2 == 0){
		ll ans = fastpow(a,b/2);
		ans = (ans*ans) % MOD;
		return ans;
	}
	ll ans = fastpow(a,(b-1)/2);
	ans = (ans*ans) % MOD;
	ans = (a*ans) % MOD;
	return ans;
}     

int n;     
void slv(){
   cin>>n;
   vl p(n);
   vl q(n);
   for(ll& i : p) cin>>i;
   for(ll& i : q) cin>>i;
   reverse(all(q));
   vl ans(n);
   int l = 0 , r = n-1;
   ll ml = p[0] , mr = q[n-1];
   ans[0] =  (fastpow(2LL,ml) + fastpow(2LL,mr)) % MOD; 
   for(int i = 1 ; i < n ; i++){
	  if(ml < p[i]){
		   ml = p[i];
		   l = i;
	  }
	  if(mr < q[n-1-i]){
		  mr = q[n-1-i];
		  r = n-1-i;	
	  }
	  int li = n-1-i+l;
	  int ri = r - (n-1-i);
	  if( ml > mr){
		  ans[i] = (fastpow(2LL,ml) + fastpow(2LL,q[li]))%MOD;
	  }
	  else if(ml < mr){
		  ans[i] = (fastpow(2LL,mr) + fastpow(2LL,p[ri]))%MOD;
	  }
	  else{
		  ans[i]=(fastpow(2LL,ml) + fastpow(2LL, max(q[li],p[ri])))%MOD;
	  }
   }
   for(int i = 0 ; i < n ; i++){
		cout<<ans[i]<<" ";
   } 
   cout<<"\n";
}   
         
int main(){
    int t = 1;
    cin>>t;
    while(t--) slv();
    return 0;
}
