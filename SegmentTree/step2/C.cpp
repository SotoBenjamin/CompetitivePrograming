#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 7
using namespace std;


class Stree{
private:
	int sz = 0;
	vector<int> tree;
	
	int left(int x){
		return 2*x + 1;
	}
	
	int right(int x){
		return 2*x + 2;
	}
	
	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			tree[x] = v;
			return;
		}
		int m = (lx + rx)/2;
		if(i < m) set(i, v, left(x), lx, m);
		else set(i, v, right(x), m, rx);
		tree[x] = max(tree[left(x)] , tree[right(x)]);
	}
	
	
	void init(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		tree.assign(2*sz,-INF);
	}
	
	
	int index(int k, int x, int lx, int rx){
		if(rx - lx == 1) 
			return lx;
		int ml = tree[left(x)];
		int m = (lx + rx)/2;
		if(ml >= k) return index(k, left(x), lx, m);
		else return index(k, right(x), m, rx);
	}
public:
	Stree(int n){
		init(n);
	}
	
	void set(int i, int v){
		set(i, v, 0, 0, sz);
	}
	
	int index(int k){
		return index(k, 0, 0, sz);
	}
	int max_el(){
		return tree[0];
	}
};

int main(){
	int n,m; cin>>n>>m;
	Stree st(n);
	for(int i = 0 ; i < n ; i++){
		int v; cin>>v;
		st.set(i, v);
	}
	
	while(m--){
		int type; cin>>type;
		if(type == 1){
			int i,v; cin>>i>>v;
			st.set(i,v);
			continue;
		}
		int k; cin>>k;
		if(st.max_el() < k){
			cout<<"-1\n";
			continue;
		}
		cout<<st.index(k)<<"\n";
	}
	
	return 0;
}
