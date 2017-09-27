#include <bits/stdc++.h>
using namespace std;
double val;

struct Point {
	double x, y;
	bool operator <(const Point &p) const {
		return y < p.y || (y == p.y && x < p.x);
	}
};

double cross(const Point &O, const Point &A, const Point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double calc(vector<Point> &a){
	int siz=a.size();
	double ans=0;
	for(int i=1;i<siz;i++){
		ans+=sqrt((a[i].x-a[i-1].x)*(a[i].x-a[i-1].x) + (a[i].y-a[i-1].y)*(a[i].y-a[i-1].y));
	}
	ans+=sqrt((a[0].x-a[siz-1].x)*(a[0].x-a[siz-1].x) + (a[0].y-a[siz-1].y)*(a[0].y-a[siz-1].y));
	return ans;
}

vector<Point> convex_hull(vector<Point> &P){
	int n = P.size(), k = 0;
	vector<Point> H(2*n);
	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	
	H.resize(k-1);
	val=calc(H);
	return H;
}
int main(){
	int t;
	Point q;
	cin>>t;
	while(t--){
		map<Point,int>m;
		vector<Point>a;
		int n;
		cin>>n;
		for(int i=0,u,v;i<n;i++){
			cin>>q.x>>q.y;
			if(m.find(q)==m.end()){
				m[q]=i+1;
				a.push_back(q);
			}
		}
		if(n==1){
			cout<<0<<endl;
			cout<<1<<" "<<endl;
		}
		else{
			a=convex_hull(a);
			printf("%.2lf\n", val);
			for(int i=0;i<a.size();i++){
				cout<<setprecision(16)<<m[a[i]]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
