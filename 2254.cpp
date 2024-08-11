#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x,y;
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

int N,X,Y;
vector<Point> V;
Point prison;
stack<int> S,tmp;
int ans;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> prison.x >> prison.y;
 
	for(int i=0;i<N;i++){
		cin >> X >> Y;
		V.push_back(Point(X,Y));
	}
	
	while(1){
		// find zero vertex.
		sort(V.begin(),V.end());
        
		int l=V.size();
		// find the gradient.
		for(int i=1;i<l;i++){
			V[i].p=V[i].x-V[0].x;
			V[i].q=V[i].y-V[0].y;
		}
 
		// sort by CCW.
		sort(V.begin()+1,V.end());
 
		vector<Point> hull=V;
        
		S.push(0);
		S.push(1);
		int nxt=2;
        
        // make convex hull.
		while(nxt<l){
			while(S.size()>=2){
				int second=S.top(); S.pop();
				int first=S.top();
				
				// check second vertex is convex hull member.
				if(Ccw(V[first],V[second],V[nxt])){
					S.push(second);
					break;
				}
			}
			S.push(nxt++);
		}
        
		tmp=S;
		int top=S.top();
		int first=S.top(); S.pop(); // 꺼낼 때는 시계 방향이니까 
		int second=S.top(); S.pop(); // first와 second 순서가 이번에는 반대. 
 
		bool in=Ccw(V[first],V[second],prison);
        bool flag=1;
		while(!S.empty()){
			first=second;
			second=S.top(); S.pop();
 
			if(in!=Ccw(V[first],V[second],prison)){
				flag=0;
				break;
			}
		}
		if(in!=Ccw(V[second],V[top],prison))flag=0;
		
		if(flag){
			ans++;
			set<int> saver;
			
			int l=V.size();
			for(int i=0;i<l;i++)
				saver.insert(i);
			
			while(!tmp.empty()){
				saver.erase(tmp.top()); tmp.pop();
			}
			
			V.clear();
			for(auto it=saver.begin();it!=saver.end();it++)
				V.push_back(hull[*it]);
		}
		else break;
		if(V.size()<3)break;
	}
    cout << ans;
}
