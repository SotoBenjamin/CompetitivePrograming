#include <bits/stdc++.h>
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
     
const ll mod = 1e9+7;
     
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
 
int h,w;


vector<pii> dir = { {0,1} , {0,-1} , {1,0} , {-1,0}};

bool isIn(int x,int y){
    return x >= 1 && x <= h && y >= 1 && y <= w;
}


void slv(int h){ 
    ll x;
    cin>>w>>x;
    int p,q;
    cin>>p>>q;
    vector<vector<ll>> M(h+1,vector<ll>(w+1));
    for(int i = 1; i <= h ;i++){
        for(int j = 1 ; j <= w ; j++) cin>>M[i][j];
    }
    using Node = pair<ll , pii>;
    auto compare = [](const Node & a,const Node & b){
        return a.first > b.first;
    };

    priority_queue< Node , std::vector<Node> , decltype(compare)> pq(compare);
    ll ans = M[p][q];
    vector<vector<bool>> vis(h+1,vector<bool>(w+1,false));
    vis[p][q] = true;
    for(int k = 0 ; k < 4 ; k++){
        int ni = p + dir[k].fi;
        int nj = q + dir[k].se;
        if( isIn(ni,nj) &&  vis[ni][nj] == false ){
            pq.push( {M[ni][nj] , {ni,nj} });
        }
    }


    while( !pq.empty()){
        ll v = pq.top().fi;
      
        int i,j;
        i = pq.top().se.fi;
        j = pq.top().se.se; 

        pq.pop();
        if( vis[i][j] ){
            continue;
        }
        vis[i][j] = true;
        if( v >= (ans + x-1)/x) continue;
        else ans += v;
        
        for(int k = 0 ; k < 4 ; k++){
            int ni = i + dir[k].fi;
            int nj = j + dir[k].se;
            if( isIn(ni,nj)){
                pq.push( {M[ni][nj] , {ni,nj} });
            }
        }
    }

    cout<<ans<<"\n";
}
     
int main(){
    freopen("e.in" , "r" , stdin);
    while(cin>>h){
        slv(h);
    }
    return 0;
}