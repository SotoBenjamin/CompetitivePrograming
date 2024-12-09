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
 
 
vector<pii> coodinates = { {0,1} , {0,-1} , {1,0} , {-1,0}}; 

int n,m;

bool isIn(int x , int y){
    return  x >= 1 && x <= n && y >= 1 && y <= m;
}

        
signed slv() {
	int D; cin>>n>>m>>D;
    vector<vector<bool>> vis(n+1,vector<bool>(m+1,0) );
    vector< vector<char> > M(n+1 , vector<char>(m+1));
    queue< pair<pii , int> > q;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin>>M[i][j];
            if( M[i][j] == 'H'){
                q.push({{i,j} , 0});
            }
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int x,y,d;
        x = q.front().fi.fi;
        y = q.front().fi.se;
        d = q.front().se;
        q.pop();
        
        if( d > D){
            continue;
        }

        if( vis[x][y] == true) continue;

        vis[x][y] = true;

        cnt++;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + coodinates[i].fi;
            int ny = y + coodinates[i].se;
            if( isIn(nx,ny) && M[nx][ny] == '.'){
                q.push({{nx,ny} , d+1});
            }
        }
    }

    

    cout<<cnt<<"\n";


    return 0;
}
 
signed main(){
    //freopen("c.in","r",stdin);
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}