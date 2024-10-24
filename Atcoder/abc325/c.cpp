#include <bits/stdc++.h>
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

vector<pii> directions = { {0,1} , {1,0} , {-1,0} , {0,-1} , {1,1}, {-1,-1} , {-1,1} , {1,-1}};
int h,w;
bool vis[1005][1005];

vector<string> grid(10005);

bool in(int i , int j){
    return i >= 0 && i < h && j >= 0 && j < w;
}

void dfs(int x,int y){
    vis[x][y] = true;
    for(int i = 0 ; i < 8 ; i++){
        int dx = x + directions[i].fi;
        int dy = y + directions[i].se;
        if(!in(dx,dy)) continue;
        if(grid[dx][dy] == '#' && !vis[dx][dy]) dfs(dx,dy);
    }
}





signed slv() {
    cin>>h>>w;
    for(int i = 0 ; i < h ;i++) cin>>grid[i];
    
    int cnt = 0;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            if( grid[i][j] == '#' && !vis[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";


    return 0;
}

signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}