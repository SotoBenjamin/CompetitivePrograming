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
 
template<typename T>
T sign(T a){
	if(a > 0) return 1;
	else if(a < 0) return -1;
	return 0;
}

struct Point{
    int x{},y{};
    explicit Point(){};
    
    Point(int _x , int _y){
        this->x = _x;
        this->y = _y;
    };

    friend istream& operator >> (istream& in , Point& p);
};

istream& operator >> (istream& in , Point& p){
    in>>p.x;
    in>>p.y;
    return in;
}

int paralelX(Point& p1, Point& p2){
    if(p1.x == p2.x) return abs(p1.y - p2.y);

    return -1;
}

int paralelY(Point& p1, Point& p2){
    if(p1.y == p2.y){
        return abs(p1.x - p2.x);
    }
    return -1;
}

signed slv() {
    int n; cin>>n;
	vector<Point> v(n);
    for(int i = 0 ; i < n ; i++) cin>>v[i];
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                int x = paralelX(v[i],v[j]);
                int y = paralelY(v[j],v[k]);
                if(x != -1 && y != -1){
                    ans = max(ans , (ll) (x*y) );     
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
 
signed main(){
	freopen("triangles.in","r",stdin);
    freopen("triangles.out", "w" , stdout);
    int t=1; //cin>>t;
    while(t--) slv();
    return 0;
}