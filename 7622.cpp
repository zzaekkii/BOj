// 7662번 이중 우선순위 큐 - 골드4 / 우선순위 큐, 맵, 구현 
#include <bits/stdc++.h>
using namespace std;

int T, K, N;
char O;
unordered_map<int,int> cnt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    
    while(T--){
    	cin >> K;
    	
    	priority_queue<int,vector<int>,less<int>> mx;
    	priority_queue<int,vector<int>,greater<int>> mn;
    	
    	for(int i=0;i<K;i++){
    		cin >> O >> N;
    		
    		if(O=='I'){
    			mx.push(N);
    			mn.push(N);
    			cnt[N]++;
    		}
    		else{
    			if(mx.size()&&N==1){ // 최대 삭제. 
    				cnt[mx.top()]--;
    				mx.pop();
				}
				else if(mn.size()&&N==-1){ // 최소 삭제. 
					cnt[mn.top()]--;
					mn.pop();
				}
				
				while(!mx.empty()&&!cnt[mx.top()]){
					mx.pop();
				}
				while(!mn.empty()&&!cnt[mn.top()]){
					mn.pop();
				}
			}
		}
		
		if(mx.empty()&&mn.empty())cout << "EMPTY\n";
		else cout << mx.top() << ' ' << mn.top() << '\n';
		
    	cnt.clear();
	}
}
