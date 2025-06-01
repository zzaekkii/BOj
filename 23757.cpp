// 23757번 아이들과 선물 상자 - 실버2 / 우선순위 큐 
#include <bits/stdc++.h>
using namespace std;

int N, M, T;
priority_queue<int, vector<int>, less<int>> gift;
int child[100001];
int ans=1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    for(int i=0;i<N;i++){
    	cin >> T;
    	gift.push(T);
    }
    
    for(int i=0;i<M;i++)
    	cin >> child[i];
    
    for(int i=0;i<M;i++){
		int tmp=gift.top(); gift.pop();
		
		if(child[i]<=tmp) gift.push(tmp-child[i]);
    	else {
    		ans=0;
    		break;
		}
	}
	
	cout << ans;
}
