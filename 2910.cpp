#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N,C,T;
map<int,pair<int,int>> m;

bool cmp(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b){
	  if(a.Y.X==b.Y.X) return a.Y.Y<b.Y.Y;
	  return a.Y.X>b.Y.X;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    
    for(int i=0;i<N;i++){
    	  cin >> T;
    	
    	  auto tmp=m.find(T);
    	  if(tmp!=m.end()) tmp->Y.X++;
    	  else m[T]={1,i};
    }
    
    vector<pair<int,pair<int,int>>> V(m.begin(),m.end());
    
    sort(V.begin(),V.end(),cmp);
	
	  for(auto a:V)
		    for(auto i=0;i<a.Y.X;i++)
			      cout << a.X << ' ';
}
