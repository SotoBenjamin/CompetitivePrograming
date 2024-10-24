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
    string s;string t; cin>>s>>t;
    int n = s.size() , m = t.size();

    

    int ans = -1;
    int i = 0 , j = 0;
    while(i < n && j < m){
        if(s[i] != t[j]){
            ans = i;
            break;
        }
        i++;
        j++;
    }

    if(ans == -1){
        if( n == m){
            cout<<0<<"\n";
            return 0;
        }
        if(i == n){
            cout<<(n+1)<<"\n";
            return 0;
        }
        if(j == m){
            cout<<(m+1)<<"\n";
            return 0;
        }

    }
    else{
        cout<<(ans+1)<<"\n";
    }



    return 0;
}

signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}