#include <bits/stdc++.h>

#define dbg(x) cout<<#x<<" = "<<x<<endl;


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

	int kth(int t, int x, int lx, int rx){
		if(tree[x] < t) return -1;

		if(rx - lx == 1){
			return lx;
		}

		//dbg(x);
		//dbg(tree[x]);
		//dbg(t);
		int m = (lx + rx)/2;

		int qr = kth(t, right(x), m, rx);

		if(qr != -1) return qr;

		return kth(t - tree[right(x)], left(x), lx, m);
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

	int kth(int k){
		return kth(k+1, 0, 0, sz);
	}

};

int n;


void slv(){
	int b[n];
	for(int i = 0 ; i < n ; i++) cin>>b[i];
	Stree st(n);
	for(int  i = 0 ; i < n ; i++) st.set(i,1);
	int a[n];
	for(int i = n-1 ; i >= 0 ; i--){
		int idx = st.kth(b[i]);
		a[i] = idx;
		st.set(idx,0);
		//dbg(idx);
		//cout<<"---------------------"<<endl;
	}
	for(int i = 0 ; i < n ; i++)
		cout<<(a[i]+1)<<" ";
	cout<<"\n";
}


int main(){
	while(cin>>n) slv();
	return 0;
}
