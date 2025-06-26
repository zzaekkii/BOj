// 14594번 동방 프로젝트 (Small) - 실버4 / 구현 
#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
pair<int,int> p[101]; 
int room[101];
bool vis[101];
int ans;

int Merge(int x, int y){
	if(room[x]==room[y])
		return room[x];
	return room[y]=Merge(room[x],y-1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    // Init.
    for(int i=1;i<=N;i++)
    	room[i]=i;
    
    cin >> M;
    
    for(int i=0;i<M;i++){
    	cin >> A >> B;
    	
    	p[i]={A,B};
	}
	
	sort(p,p+M);
    	
    for(int i=0;i<M;i++)
    	if(room[p[i].first]!=room[p[i].second])
			Merge(p[i].first,p[i].second);
	
	for(int i=1;i<=N;i++)
		if(!vis[room[i]]){
			vis[room[i]]=1;
			ans++;
		}
	
	cout << ans;
}
