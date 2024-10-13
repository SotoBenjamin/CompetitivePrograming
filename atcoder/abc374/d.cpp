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
typedef pair<ld,ld> pld;


const ll mod = 1e9+7;
     
int nxt() {
    int x; cin >> x;
    return x;
}
     
const ll inf = INT64_MAX;

ll s,t;
int n;


ld distance(pll P0,pll P1){
    ll res = 0;
    res += (P0.fi - P1.fi)*(P0.fi - P1.fi);
    res += (P0.se - P1.se)*(P0.se - P1.se);
    return sqrtl(ld(res));
}

struct Line{
    pll P0;
    pll P1;
    Line(pll A , pll B) {
        this->P0 = A;
        this->P1 = B;
    }
    ld large(){
        return distance(P0,P1);
    }
};






ld result(vector<Line> & v ){
    ld res = distance({0,0} , v[0].P0)/s + v[0].large()/t;
    for(int i = 1 ; i < n ; i++){
        res += distance(v[i-1].P1 , v[i].P0)/s + v[i].large()/t;
    }

    return res;
}

signed slv() {
    cin>> n >> s >> t;
    vector<Line> v;
    for(int i = 0 ; i < n ; i++){
        ll a,b,c,d; cin>>a>>b>>c>>d;
        Line l1(make_pair(a,b) , make_pair(c,d));
        v.push_back(l1);
    }

    vector<int> idx;
    for(int i = 0 ; i  < n ; i++) idx.push_back(i);
    ld ans = INFINITY;
    do{
       
       for(int i = 0 ; i < (1<<n) ; i++){
            bitset<6> bits(i);
            vector<Line> current;
            for(int j = n-1 ; j >= 0 ; j--){
                if( bits[j] ){
                    Line l1 = v[idx[j]];
                    current.push_back({l1.P1 , l1.P0});
                }
                else{
                    current.push_back(v[idx[j]]);
                }
            }
            reverse(all(current));
            // for(auto & l : current){
            //     DBGS(l.P0.fi);
            //     DBGS(l.P0.se);
            //     DBGS(l.P1.fi);
            //     DBGS(l.P1.se);
                
            // }
            ans = min(ans,result(current));
            // cout<<result(current)<<endl;
       }


    }while(next_permutation(all(idx)));

    
    cout<<setprecision(20)<<ans<<"\n";

    return 0;
}
     
signed main(){
    slv();
    return 0;
}