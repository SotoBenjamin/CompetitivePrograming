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
void slv(){
    cin>>m>>k;
    vi a(n);
    vi b(m);
    for (int & i : a) cin>>i;
    for(int &i : b) cin>>i;
    sort(all(a));
    sort(all(b));
    int i = n-1,j=m-1;
    int cnt = 0 ;
    while(i >= 0 && j >= 0){
        if(abs(a[i]-b[j]) <= k){
            cnt++;
            i--;
            j--;
            continue;
        }
        if ( a[i]  > b[j]){
            i--;
        }
        else {
            j--;
        }
    }
    cout<<cnt<<"\n";
}   
     
int main(){
    //freopen("Apartments.in","r" ,stdin);
    while(cin>>n) slv();
    return 0;
}