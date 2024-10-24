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


struct Line{
    pll A;
    pll B;

    Line(pll a,pll b){
        A = a;
        B = b;
    }

    ld distance(){
        return sqrt( pow(ld(A.fi - B.fi) , 2) + pow(ld(A.se-B.se),2) );
    }
};

ll s,t;
ld distance (pll A,pll B){
    return sqrt( pow(ld(A.fi - B.fi) , 2) + pow(ld(A.se-B.se),2) );
}


ld res(vector<Line> & v){
    ld ans = distance(v[0].A , {0,0})*s + v[0].distance()*t;
    for(int i = 1 ; i < v.size() ; i++){
        ans += distance(v[i].A,v[i-1].B) + v[i].distance();
    }
    return ans;
}





signed slv() {
    ll n; cin>>n>>s>>t;

    vector<Line> v(n);
    for(int i = 0 ; i < n ; i++) {
        ll a,b,c,d; cin>>a>>b>>c>>d;
        v[i] = { {a,b} , {c,d}};
    }
    int pot = 1<<n;
    ld ans = INFINITY;
    do{
        for(int i = 0 ; i < pot ; i++){
            bitset<6> bits(i);
            vector<Line> aux(n);
            for(int i = n-1 ; i >= 0 ; i--){
                if(bits[i] == 0){
                    aux[i] = v[i];
                }
                else{
                    aux[i] = {v[i].B , v[i].A};
                }
            }
            ans = min(ans,res(aux));
        }


    }while(std::next_permutation(v.begin(),v.end()));


    
    cout<<fixed<<setprecision(20)<<ans<<"\n";
  

    return 0;
}

signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}