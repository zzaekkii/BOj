#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Point{
	int x,y;
	// differ.
	int p,q;
	// struct constructor overloading.
    Point(): x(0),y(0),p(0),q(0){}
	Point(int a,int b): x(a),y(b),p(0),q(0){}
	
	// sort cmp with operator overloading.
	bool operator<(const Point &O){
		// compare slope (asc).
		if(1LL*q*O.p!=1LL*p*O.q)return 1LL*q*O.p<1LL*p*O.q;
		if(y!=O.y)return y<O.y;
		return x<O.x;
	}
};

// compare slope a-c vs b-c.
bool Ccw(const Point &fst,const Point &sec,const Point &nxt){
	return 1LL*(nxt.y-fst.y)*(sec.x-fst.x)>1LL*(sec.y-fst.y)*(nxt.x-fst.x);
}

double Dist(const Point &a,const Point &b){
    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

int N,X,Y;
Point p[100001];
int S[100001];
double ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> X >> Y;
		p[i]=Point(X,Y);
	}
	
	// find zero vertex.
	sort(p,p+N);
	
	// find the gradient.
	for(int i=1;i<N;i++){
		p[i].p=p[i].x-p[0].x;
		p[i].q=p[i].y-p[0].y;
	}
	
	// sort by CCW.
	sort(p+1,p+N);
	
	S[0]=0;
	S[1]=1;
	int idx=1;
	int nxt=2;
	
	// make convex hull.
	while(nxt<N){
		while(idx>=1){
			int second=S[idx--];
			int first=S[idx];
			
			// check second vertex is convex hull member.
			if(Ccw(p[first],p[second],p[nxt])){
				S[++idx]=second;
				break;
			}
		}
		S[++idx]=nxt++;
	}
	
	for(int i=0;i<idx;i++)
		for(int j=i+1;j<=idx;j++)
			ans=max(ans,Dist(p[S[i]],p[S[j]]));
	
	cout << fixed;
    cout.precision(8);
    cout << ans;
}
