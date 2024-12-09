#include "bits/stdc++.h"
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const ll mod = 1e9+7;
 
int nxt() {
    int x; cin >> x;
    return x;
}
 
const int inf = INT_MAX;
 
 
 
 
        
signed slv() {
	int n,m,d; cin>>n>>m>>d;
    vector< vector<char> > M(n+1 , vector<char>(m+1));
    vector<pii> v;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin>>M[i][j];
            if( M[i][j] == '.'){
                v.push_back({i,j});
            }
        }
    }

    int tam = sz(v);


    int ans = -1;

    for(int i = 0 ; i < tam ; i++){
        
        for(int j = i + 1 ; j  < tam ; j++){
            
            pii h1 = v[i] , h2 = v[j];
            int cnt = 0;
            
            for(int i1 = 1 ; i1  <= n ; i1++){
                
                for(int j1 = 1 ;  j1 <= m ; j1++){
                    
                    int m1 = abs(i1 - h1.fi) + abs(j1 - h1.se);
                    int m2 = abs(i1 - h2.fi) + abs(j1 - h2.se);
                    
                    if( (m1 <= d || m2 <= d) && M[i1][j1] != '#'){
                     
                        cnt++;
                    }
                }
            }
            
            ans = max(ans,cnt);
        }
    }

    cout<<ans<<"\n";


    return 0;
}
 
signed main(){
    //freopen("b.in","r",stdin);
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}