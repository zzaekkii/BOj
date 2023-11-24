#include <bits/stdc++.h>
using namespace std;
int N, X;

priority_queue<int, vector<int>> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    
    while(N--){
    	cin >> X;
    	if(!X){
    		if(pq.empty())cout << "0\n";
    		else{
    			cout << pq.top() << '\n';
    			pq.pop();
			}
		}
		else pq.push(X);
	}
}
