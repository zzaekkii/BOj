// 7983번 내일 할거야 - 골드5 / 그리디
#include <bits/stdc++.h>
using namespace std;

int N,D,T;
vector<pair<int,int>> V;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    for(int i=0;i<N;i++){
    	cin >> D >> T;
    	V.push_back({T,D});
	}
	
	sort(V.begin(),V.end(),greater<>());
	
    int ans=V[0].first;
	for(int i=0;i<N;i++){
		if(V[i].first<ans)ans=V[i].first;
		ans-=V[i].second;
	}
	
	cout << ans;
}
