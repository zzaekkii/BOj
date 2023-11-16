#include <bits/stdc++.h>
using namespace std;
int N, X;

struct cmp{ // 우선순위 큐는 컨테이너라 구조체로 선언해줘야함.
	bool operator() (int a, int b){
		if(abs(a)!=abs(b))return abs(a)>abs(b); // 더 높은 우선순위를 갖기 위해서는 비교 값이 true로 (일반적인 cmp와 반대)
		return a>=b; // b가 양수, a가 음수일 경우 false.
	}
};

priority_queue<int, vector<int>, cmp> pq;

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
