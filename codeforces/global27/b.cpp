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
 

 



void slv(){ 
    int n; cin>>n;
    if( n == 1 ) {
        cout<<-1<<"\n";
        return;
    }
    if( n == 2){
        cout<<66<<"\n";
        return;
    }
    if( n == 3){
        cout<<-1<<"\n";
        return;
    }

    if( n % 2 == 0){
        string s = "6633";
        for(int i = 1 ; i <= (n-4) ; i++){
            s += '3';
        }
        std::reverse(all(s));
        cout<<s<<"\n";
        return;
    }

    string s = "66363";
    for(int i = 1 ; i <= (n-5) ; i++){
        s += '3';
    }

    std::reverse(all(s));
    cout<<s<<"\n";

}
     
int main(){
    //freopen("b.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}