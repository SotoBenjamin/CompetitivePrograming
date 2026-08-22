#include <bits/stdc++.h>

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
		tree[x] = tree[left(x)] + tree[right(x)];
	}
	
	int query(int l, int r, int x, int lx, int rx){
		if(l >= rx || r <= lx){
			return 0;
		}
		
		if(lx >= l && rx <= r){
			return tree[x];
		}
		
		int m = (lx + rx)/2;
		
		return query(l, r, left(x), lx, m) + query(l, r, right(x), m, rx);
	}

public:
	Stree(int n){
		sz = 1;
		while(sz < n) sz *= 2;
		tree.assign(2*sz,0);
	}
	
	void set(int i,int v){
		set(i, v, 0, 0, sz);
	}
	
	int query(int l, int r){
		return query(l, r, 0, 0, sz);
	}
};

int n;


void slv(){
	int b[n];
	for(int i = 0 ; i < n ; i++) cin>>b[i];
	
}


int main(){
	while(cin>>n) slv();
	return 0;
}
