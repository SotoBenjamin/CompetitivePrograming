#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
int n;

void slv(){
	map<int,int> mp;
	for(int i = 0 ; i < n ; i++){
		int x; cin>>x;
		mp[x]++;
	}
	if(n <= 4){
		if(mp.size() == 1){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
		return;
	}

	if(mp.size() == 1){
		cout<<"YES\n";
		return;
	}

	vector<int> a;
	for(auto& p : mp) a.push_back(p.second);

	sort(a.begin(),a.end());

	int x = a.back();
	a.pop_back();
	int y = a.back();
	x -= 4;

	if(x < 0){
		cout<<"NO\n";
		return;
	}

	if(x >= y-1){
		cout<<"YES\n";
		return;
	}

	cout<<"NO\n";
}

int main(){
	while(cin>>n) slv();
	return 0;
}
