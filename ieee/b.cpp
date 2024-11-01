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
    int x; cin>>x;
    vector<int> A(n);
    for(int i = 0 ; i < n ; i++) cin>>A[i];
    sort(A.begin() , A.end());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
    vector<vector<int>> v(n);
    int tam = 0;
    for(auto& ld : A){
        if(tam == 0){
            v[tam].push_back(ld);
            minHeap.push({ld,tam});
            tam++;
            continue;
        }
        auto p = minHeap.top();
        if( p.first + x <= ld ){
            minHeap.pop();        
            v[p.second].push_back(ld);
            minHeap.push({ld,p.second});
        }
        else{
            v[tam].push_back(ld);
            minHeap.push({ld,tam});
            tam++;
        }
    }
    cout<<tam<<"\n";
    for(int i = 0 ; i < tam; i++){
        cout<<v[i].size()<<" ";
        for(int j = v[i].size() -1 ; j >= 0 ; j--){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}