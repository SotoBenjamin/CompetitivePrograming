#include <bits/stdc++.h>

#define sz(x) (int) x.size()
#define all(x) x.begin() , x.end()
#define ll long long int

using namespace std;


template <typename T>
struct Point2D{
	T x,y;

	Point2D(){};

	Point2D(T _x ,T _y){
		x = _x;
		y = _y;
	}

    bool operator < (const Point2D<T> &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

	Point2D operator - (const Point2D<T> &other) const{
		return Point2D(x - other.x , y - other.y);
	}
};


template<typename T>
int sign(T t){
	if(t > 0) return 1;
	if(t  == 0) return 0;
	return -1;
}

template<typename T>
int orientation(const Point2D<T> & A ,const Point2D<T>& B ,const Point2D<T> & C){
	auto v1 = B - A;
	auto v2 = C - A;
	// v1.x v1.y
	// v2.x v2.y
	return sign(v1.x*v2.y - v1.y*v2.x); 
}


template <typename T>
T dot_product(const Point2D<T> &A , const Point2D<T> &B){
	return A.x*B.x + A.y*B.y;
}

template <typename T>
bool is_in(const Point2D<T> &A,const Point2D<T> &B,const Point2D<T> &C){
	auto u = C-A;
	auto v = C-B;
	return sign(dot_product(u,v)) <= 0;
}


int prev(int i , int n){
	return (i - 1 + n)%n;
}
int next(int i , int n){
	return (i+1)%n;
}


template <typename T>
T cuadratic_dist(const Point2D<T>& A, const Point2D<T>& B) {
    T dx = A.x - B.x;
    T dy = A.y - B.y;
    return dx * dx + dy * dy;
}



template <typename T>
vector<Point2D<T>> interior_point_removal(vector<Point2D<T>> &P){
	int n = sz(P);
	T xmin = P[0].x , ymin = P[0].y , xmax = P[0].x , ymax = P[0].y;
	for(auto& p : P){
		xmin = min(xmin,p.x);
		ymin = min(ymin,p.y);
		xmax = max(xmax,p.x);
		ymax = max(ymax,p.y);
	}
	vector<Point2D<T>> X_min(2) , Y_min(2) , X_max(2) , Y_max(2);
	int sz_xmin = 0, sz_ymin = 0 , sz_xmax = 0, sz_ymax = 0;
	
	for(auto& p : P){
		if (p.x == xmin){
			if( sz_xmin == 0) {
				X_min[0] = p ;
				X_min[1] = p;
				sz_xmin++;
			
			}
			else{
				 if (p.y < X_min[0].y)  X_min[0] = p;
				 if (p.y > X_min[1].y)    X_min[1] = p;
				 sz_xmin++;
			} 
		}
		
		if( p.y == ymin){
			if( sz_ymin == 0) {
				Y_min[0] = p ;
				Y_min[1] = p;
				sz_ymin++;
			
			}
			else{
				 if (p.x < Y_min[0].x)   Y_min[0] = p;
				 if (p.x > Y_min[1].x)   Y_min[1] = p;
				 sz_ymin++;
			} 
		}
		
		if(p.x == xmax){
			if( sz_xmax == 0) {
				X_max[0] = p ;
				X_max[1] = p;
				sz_xmax++;
			
			}
			else{
				 if (p.y < X_max[0].y)  X_max[0] = p;
				 if (p.y > X_max[1].y)   X_max[1] = p;
				 sz_xmax++;
			} 
		}
	
		if(p.y == ymax){
			if( sz_ymax == 0) {
				Y_max[0] = p ;
				Y_max[1] = p;
				sz_ymax++;
			
			}
			else{
				 if (p.x < Y_max[0].x)   Y_max[0] = p;
				 if (p.x > Y_max[1].x)   Y_max[1] = p;
				 sz_ymax++;
			} 
		}
	}
	
	if(sz_ymin == 1) Y_min.pop_back();
	if (sz_xmax == 1) X_max.pop_back();
	if (sz_ymax == 1) Y_max.pop_back();
	if (sz_xmin == 1) X_min.pop_back();
	reverse(all(Y_max));
	reverse(all(X_min));
	
	
	vector<Point2D<T>> poly;
	
	for(auto& p : Y_min) poly.push_back(p);
	for(auto& p : X_max) poly.push_back(p); 
	for(auto& p : Y_max) poly.push_back(p);
	for(auto& p : X_min) poly.push_back(p);
	
	vector<Point2D<T>> poly2;
	for(int i = 0 ; i < sz(poly) ; i++){
		if (i == 0 || poly[i].x != poly[i-1].x || poly[i].y  != poly[i-1].y ){
			poly2.push_back(poly[i]);
		}
	
	}
	
	if(poly2.size()>1 && poly2.front().x==poly2.back().x && poly2.front().y==poly2.back().y) {
		poly2.pop_back();
	}
	
	if(sz(poly2) < 3){
		return P;
	}
	
	
	vector<Point2D<T>> ans;
	for(auto& p : P){
		bool flag = false;
		for(int i = 0 ; i < sz(poly2) ; i++){
			auto A = poly2[i];
			auto B = poly2[ next(i,sz(poly2))];
			if (orientation(A,B,p) <= 0){
				flag = true;
				break;
			}
		}
		if (flag) ans.push_back(p);
	}
	
	return ans;
}




template<typename T>
vector<Point2D<T>> graham_handle_overflow(vector<Point2D<T>> & P, bool withInteriorPointsRemoval){
    int n = sz(P);
    sort(all(P));
    vector<Point2D<T>> l,u;
    for(int i = 0 ; i < n ; i++){
		while( sz(l) >= 2 && orientation(l[sz(l)-2] , l[sz(l) -1] ,P[i]) <= 0)
			l.pop_back();
		l.push_back(P[i]);
	}
	
	for(int i = n-1 ; i >= 0 ; i--){
		while( sz(u) >= 2 && orientation(u[sz(u)-2], u[sz(u) -1] ,P[i]) <= 0)
			u.pop_back();
		u.push_back(P[i]);		
	}
	l.pop_back();
	u.pop_back();
	vector<Point2D<T>> h = l;
	for(auto& p : u) h.push_back(p);
	return h;
}


template<typename T>
vector<Point2D<T>> jarvis_handle_overflow(vector<Point2D<T>> & P, bool withInteriorPointsRemoval){
	int n = sz(P);
	if (n < 3) return P;
	int pmin = distance(P.begin() , min_element(all(P))); // index of min
	int i = pmin; // current index
	vector<Point2D<T>> h;
	do{
		h.push_back(P[i]);
		int j = next(i,n);
		//punto mas a la izquierda con respecto al actual (i)
		for(int k  = 0 ; k < n ; k++){
			int o1 = orientation(P[i],P[j],P[k]);
			if ( o1 > 0 || ( o1 == 0 && cuadratic_dist(P[i] , P[j]) < cuadratic_dist(P[i],P[k])  )){
				j = k;
			}
		}
		i = j;
	} while( i != pmin);
	return h;
}






int main(){
	int n; cin>>n;
	vector<Point2D<ll>> P(n);
	for(int i = 0 ; i < n ; i++){
		ll x,y; cin>>x>>y;
		P[i] = {x,y};
	}
	auto h = graham_handle_overflow(P,0);
	cout<<sz(h)<<"\n";
	for(auto& p : h){
		cout<<p.x<<" "<<p.y<<"\n";
	}
	
	return 0;
}
