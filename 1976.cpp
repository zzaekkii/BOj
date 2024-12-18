// 1976번 여행 가자 - 골드4 / #Union-find 
#include <bits/stdc++.h>
using namespace std;

int N, M, T, X; // 도시 N곳, 여행 계획지 M곳.
// 뿌리 기준 도시 X, 그 외 도시 입력 T. 
int root[201]; // 연결된 도시 정보. 
// 계획에 속한 도시들이 같은 뿌리면 됨. 

int find(int x){
	if(root[x]==x)return x;
	return root[x]=find(root[x]);
}

void union_set(int x, int y){
	int rootX=find(x);
	int rootY=find(y);
	
	if(rootX!=rootY)
		root[rootY]=rootX;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    // 뿌리를 자기로 초기화. 
    for(int i=1;i<=N;i++)
    	root[i]=i;
    
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=N;j++){
    		cin >> T;
    		if(T)union_set(i,j);
    	}
    
    cin >> X;
    X=find(X); 
    while(--M){
    	cin >> T;
		if(X!=find(T)){
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";
}
