#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll n;

bool is_sq(ll x){
	ll sq = (ll) sqrtl(x);
	return x == sq*sq;
}

void slv(){
	cin>>n;
	vector<ll> a;
	
	ll tot = (ll) n*(n+1)/2;
	if(is_sq(tot)){
		cout<<-1<<"\n";
		return;
	}
    for(ll i = 1 ; i <= n ; i++) a.push_back(i);
	ll s = 0;
	for(int i = 0 ; i < (int) n ; i++){
		s += a[i];
		if(is_sq(s)){
			s -= a[i];
			s += a[i+1];
			swap(a[i+1],a[i]);
		}
	}
	
	for(auto& i : a) cout<<i<<" ";
	cout<<"\n";
}


int main(){
	int t = 1; cin>>t;
	while(t--) slv();
	return 0;
}
