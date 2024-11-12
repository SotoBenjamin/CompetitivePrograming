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
	string s; cin>>s;
	sort(all(s));
	vector<string> ans;
	do{
		ans.push_back(s);
	}while(next_permutation(all(s)));
	cout<<sz(ans)<<"\n";
	for(auto &i : ans){
		cout<<i<<"\n";
	}
}
     
int main(){
	//freopen("cstrings.in", "r" ,stdin);
	//freopen("blocks.out", "w", stdout);
	slv();
    return 0;
}


