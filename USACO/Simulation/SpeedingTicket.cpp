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
	int n,m; cin>>n>>m;
	//road data
	vector<pii> inter1(n);
	vector<int> velocity_limit(n);
	inter1[0].fi = 0;
	inter1[n-1].se = 100;
	for(int i = 0; i < n ; i++){
		int a,b; cin>>a>>b;
		velocity_limit[i] = b;
		if(i != 0){
			inter1[i].fi = inter1[i-1].se;
		}
		inter1[i].se = inter1[i].fi + a;
	}
	//cow data
	vector<pii> inter2(m);
	vector<int> cow_velocity(m);
	inter2[0].fi = 0;
	inter2[m-1].se = 100;
	for(int i = 0; i < m ; i++){
		int a,b; cin>>a>>b;
		cow_velocity[i] = b;
		if(i != 0){
			inter2[i].fi = inter2[i-1].se;
		}
		inter2[i].se = inter2[i].fi + a;
	}
	
	int i = 0 , j = 0;
	int ans = 0;
	while(i < n && j < m){
		int current_limit = velocity_limit[i];
		int current_velocity = cow_velocity[j];
		ans = max(ans, current_velocity - current_limit);
		int fi = inter1[i].se , fj = inter2[j].se;
		if(fi == fj){
			i++;
			j++;
			
		}
		else if(fi < fj){
			i++;
		}
		else{
			j++;
		}
	}
	
	
	cout<<ans<<"\n";	
}
     
int main(){
	freopen("speeding.in", "r" ,stdin);
	//freopen("speeding.out", "w", stdout);

    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}

