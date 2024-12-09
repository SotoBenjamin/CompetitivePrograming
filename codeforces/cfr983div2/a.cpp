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
 
 
 
signed slv(){ 
    int n; cin>>n;
    int z = 0 , o = 0;
    for(int i = 0 ; i < 2*n ; i++){
        int c; cin>>c;
        if(c) o++;
        else z++;
    }


    int maxi = min(z,o);
    int mini = n -   z/2  -  o/2;
    cout<<mini<<" "<<maxi<<"\n";

    return 0;
}
     
signed main(){
    //freopen("a.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}