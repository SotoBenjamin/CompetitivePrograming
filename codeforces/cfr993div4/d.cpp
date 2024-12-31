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
 



void slv(){ 
    cin>>n;
    vector<int> v;
    vector<bool> A(n+1,false);
    for(int i = 0 ; i < n ; i++){
        int item; cin>>item;
        if( A[item] == false){
            v.push_back(item);
            A[item] = true;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if( A[i] == false){
            v.push_back(i);
        }
    }

    for(auto& i : v){
        cout<<i<<" ";
    }
    cout<<"\n";


}
     
int main(){
    //freopen("b.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}