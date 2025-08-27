#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
     

 

void slv(){
   int n; cin>>n;
   indexed_set s;
   for(int i = 0 ; i < n ; i++){
		int x; cin>>x;
		cout<<(s.size() - s.order_of_key(x))<<" ";
		s.insert(x);
   }
   cout<<"\n";
}


     
int main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}
