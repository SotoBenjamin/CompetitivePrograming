#include <bits/stdc++.h>
#include <cmath>
#include <iterator>
#include <string>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define dbg(x) cout << #x << " = " << x << '\n';
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

const int MAX = (int) 2e5+5;
vector<int> adj[MAX];
int n;
ll m;

void slv(){
	ll k,x; cin>>k>>x;
	vector<int> ans;
	ll tot = (1LL)<<(k+1);
	ll c = x , v = tot-x;
	while( c != tot/2){
		if( c < v){
			ans.push_back(1);
			c*=2;
			v = tot-c;
		}
		else{
			ans.push_back(2);
			v*=2;
			c = tot-v;
		}
	}
	cout<<sz(ans)<<"\n";
	reverse(all(ans));
	for(int i : ans) cout<<i<<" ";
	cout<<"\n";
}	
     
int main(){
    #ifndef ONLINE_JUDGE
	 freopen("input.txt","r",stdin);    
	 freopen("output.txt","w",stdout);
   #endif
       int t = 1; cin>>t;

    while(t--) {
		slv();
    }
    return 0;
}
