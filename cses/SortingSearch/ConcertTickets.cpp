#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
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
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
     
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
int n,m,k;
ll x;
void slv(){
    cin>>m;
    multiset<int> s;
    for(int i = 0 ; i < n ; i++) {
        int item; cin>>item;
        s.insert(item);
    }
    while(m--){
        int target ; cin>>target;
        if( sz(s) == 0 ){
            cout<<-1<<"\n";
            continue;
        }
        auto it = s.upper_bound(target);
        if(it == s.begin()){
            cout<<-1<<"\n";
            continue;
        }
        --it;
        int ans = *it;
        s.erase(it);
        cout<<ans<<"\n";
    }
}   
     
int main(){
    //freopen("ConcertTickets.in","r" ,stdin);
    while(cin>>n) slv();
    return 0;
}