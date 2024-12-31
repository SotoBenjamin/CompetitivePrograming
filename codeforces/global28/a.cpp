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
 
int n,k;



void slv(){ 
    int n,m; cin>>n>>m;
    vector<ll> a(n+1);
    vector<ll> b(m+1);
    for(int i = 1 ; i <= n ; i++) cin>>a[i];
    for(int j = 1 ; j <= m ; j++) cin>>b[j];
    

    

    sort(b.begin() + 1 , b.end() );

    for(int k = 1; k <= m ; k++){
        //tope;
        //k = problemas por contest; 
        int r = (m/k);
        r *= k;
        


    }


}
     
int main(){
    freopen("a.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}