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
 
int n;

 
void slv(int n){ 
    int r;
    cin>>r;
    for(int i = 0 ; i < n ; i++){
        int d,a;
        cin>>d>>a;
        if( d == 1){
            if( r >= 1600 && r <= 2799 ){
                r = r + a;
            }
        }
        else{
            if( r >= 1200 && r <= 2399){
                r = r + a;
            }
        }
    }
    cout<<r<<"\n";
}
     
int main(){
    //freopen("b.in" , "r" , stdin);
    while(cin>>n){
        slv(n);
    }
    return 0;
}