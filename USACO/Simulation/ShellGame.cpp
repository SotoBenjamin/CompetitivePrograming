#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
using namespace std;


typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
     
template<typename T>
T minV(T a){
    return a;
}

template<typename T, typename ... Args>
T minV(T a , Args... arg){
    T b = minV(arg...);
    return min(a,b);
}



void slv(){ 
    int n; cin>>n;
    vector<int> v(3,0);
    for(int i = 0;i < 3;i++) v[i] = i;
    vector<int> ans(3,0);
    while(n--){
		int a,b,g; cin>>a>>b>>g;
		a--;b--;g--;
		swap(v[a],v[b]);
		ans[v[g]]++;
	}
	cout<<*max_element(all(ans))<<"\n";
}
     
int main(){
	freopen("shell.in", "r" ,stdin);
	freopen("shell.out", "w", stdout);

    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}
